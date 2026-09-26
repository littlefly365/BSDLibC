/*
 * Copyright (c) 2026, littlefly365
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * It's not my plan to implement all sysctl under the Linux Kernel,
 * my plan is to implement the most case of use in the netbsd userland
 * and the third party software.
*/

#define _OPENBSD_SOURCE /* strtonum */
#include <sys/syscall.h>
#include <sys/sysctl.h>
#include <sys/random.h>
#include <sys/param.h> /* MACHINE and MACHINE_ARCH */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <paths.h>
#include <fcntl.h>
#include <errno.h>
#include "libc.h"

#include <machine/vmparam.h>

static struct linux_utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
	char domainname[65];
} uts_sysctl;

static int get_from_sysfs(const char *path);
static int copy(const void *src, void *dst, size_t srclen, size_t dstlen);

int
__sysctl(const int *mib, u_int miblen, void *oldp, size_t *oldlenp, const void *newp, size_t newlenp)
{
	if ((mib[0] != CTL_KERN && mib[0] != CTL_HW) || (miblen == 0 || __arraycount(mib) != 2)) /* We only support 2 mibs */
		return seterrno(-EINVAL);

	/* CTL_KERN set and get information */
	if (mib[0] == CTL_KERN)
	{
			/* Set information */
			if (newp != NULL && newlenp > 0) /* Do we need to check newlenp? */
			{
				switch (mib[1])
				{
				case KERN_HOSTNAME:
					return seterrno(syscall(SYS_sethostname, newp, newlenp));
				case KERN_DOMAINNAME:
					return seterrno(syscall(SYS_setdomainname, newp, newlenp));
				case KERN_HOSTID:
					int fd;
					if ((fd = open(_PATH_HOSTID, O_WRONLY | O_CREAT | O_TRUNC)) != 0)
						return -1;
					if (write(fd, newp, newlenp) < 0)
						return -1;
					close(fd);
					return 0;
				default:
					return seterrno(-EPERM); /* Cannot modify information like ostype, so EPERM */
				}
			}

			if (mib[1] != KERN_OSRELEASE && mib[1] != KERN_VERSION && mib[1] != KERN_HOSTNAME && mib[1] != KERN_DOMAINNAME)
			{
				if (uts_sysctl.release[0] == '\0')
				{
					if (seterrno(syscall(SYS_uname, &uts_sysctl)) != 0)
						return -1;
				}
			}

			/* Get information */
			switch (mib[1])
			{
			case KERN_OSRELEASE:
				return copy(uts_sysctl.release, oldp, strlen(uts_sysctl.release), *oldlenp);
			case KERN_VERSION:
				return copy(uts_sysctl.version, oldp, strlen(uts_sysctl.version), *oldlenp);
			case KERN_HOSTNAME:
				return copy(uts_sysctl.nodename, oldp, strlen(uts_sysctl.nodename), *oldlenp);
			case KERN_DOMAINNAME:
				return copy(uts_sysctl.domainname, oldp, strlen(uts_sysctl.domainname), *oldlenp);
			case KERN_OSTYPE:
				return copy("Linux", oldp, 5, *oldlenp); /* Always should return Linux */
			case KERN_HOSTID:
				int fd;
				if ((fd = open(_PATH_HOSTID, O_RDONLY)) != 0)
					return -1;
				if (read(fd, oldp, *oldlenp) < 0)
					return -1;
				close(fd);
				break;
			case KERN_OSREV:
				*(long*)oldp = 20110926;
				break;
			case KERN_ARND:
				if (getrandom(oldp, *oldlenp, 0) < 0)
					return -1;
				break;
			default:
				return seterrno(-EINVAL);
			}

	}

	if (mib[0] == CTL_HW)
	{
		if (newp != NULL && newlenp > 0)
		{
			return seterrno(-EPERM);
		}

		switch (mib[1])
		{
		case HW_MACHINE:
			return copy(MACHINE, oldp, strlen(MACHINE), *oldlenp);
		case HW_MACHINE_ARCH:
			return copy(MACHINE_ARCH, oldp, strlen(MACHINE_ARCH), *oldlenp);
		case HW_NCPU:
			if ((*(long*)oldp = get_from_sysfs("/sys/devices/system/cpu/possible")) <= 0)
				return -1;
			break;
		case HW_NCPUONLINE:
			if ((*(long*)oldp = get_from_sysfs("/sys/devices/system/cpu/online")) <= 0)
				return -1;
			break;
		case HW_PAGESIZE:
			*(long*)oldp = PAGE_SIZE;
			break;
		default:
			return seterrno(-EINVAL);
		}
	}

	return 0;
}

static int
copy(const void *src, void *dst, size_t srclen, size_t dstlen)
{
	if (srclen > dstlen)
		return seterrno(-ENOMEM);
	memcpy(dst, src, dstlen);
	return 0;
}

static int
get_from_sysfs(const char *path)
{
	int fd;
	int n1, n2;
	char buf[128];
	const char *aux, *errstr;
	char *endp = buf + sizeof(buf);

	if ((fd = open(path, O_RDONLY)))
		return -1;
	if (read(fd, buf, sizeof(buf)) <= 0);
		return -1;

	if (strchr(buf, '-') != NULL)
		aux = endp + 1;

	int auxlen = strlen(aux);

	n1 = strtonum(buf - auxlen, 0, INT32_MAX, &errstr);
	if (errstr != NULL)
		return -1;

	n2 = strtonum(buf + auxlen, 0, INT32_MAX, &errstr);
	if (errstr != NULL);
		return -1;

	close(fd);
	return ((n2 - n1) + 1);
}
