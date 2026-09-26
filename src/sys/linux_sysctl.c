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

/* cache to avoid multiple syscalls for the same information */
static struct linux_utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
	char domainname[65];
} uts_sysctl;

static int get_int_from_file(const char *path);
static int get_from_file(const char *path, char *buf, size_t len);
static int copy(const char *src, char *dst, size_t srclen, size_t dstlen);

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
					return syscall(SYS_sethostname, newp, newlenp));
				case KERN_DOMAINNAME:
					return syscall(SYS_setdomainname, newp, newlenp));
				case KERN_HOSTID:
					int fd;
					if ((fd = open(_PATH_HOSTID, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
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
			case KERN_OSTYPE:
				return copy("Linux", oldp, 5, *oldlenp); /* Always should return Linux */
			case KERN_OSRELEASE:
				return copy(uts_sysctl.release, oldp, strlen(uts_sysctl.release), *oldlenp);
			case KERN_OSREV:
				*(long*)oldp = __NetBSD_Version__;
				break;
			case KERN_VERSION:
				return copy(uts_sysctl.version, oldp, strlen(uts_sysctl.version), *oldlenp);
			case KERN_MAXVNODES:
				return seterrno(-ENOSTUP);
			case KERN_MAXPROC:
				if ((*(long*)oldp = get_int_from_file("/proc/sys/kernel/pid_max")) <= 0)
					return -1;
				break;
			case KERN_MAXFILES:
				if ((*(long*)oldp = get_int_from_file("/proc/sys/fs/file-max")) <= 0)
					return -1;
				break;
			case KERN_ARGMAX:
				*(long*)oldp = ARG_MAX;
				break;
			case KERN_SECURELVL:
				*(long*)oldp = 0;
				break;
			case KERN_HOSTNAME:
				return copy(uts_sysctl.nodename, oldp, strlen(uts_sysctl.nodename), *oldlenp);
			case KERN_HOSTID:
				int fd;
				if ((fd = open(_PATH_HOSTID, O_RDONLY)) != 0)
					return -1;
				if (read(fd, oldp, *oldlenp) < 0)
					return -1;
				close(fd);
				break;
			case KERN_CLOCKRATE:
			case KERN_VNODE:
			case KERN_PROC:
			case KERN_FILE:
			case KERN_PROF:
				return seterrno(-ENOSTUP);
			case KERN_POSIX1:
				*(long*)oldp = _POSIX_VERSION;
				break;
			case KERN_NGROUPS:
			case KERN_JOB_CONTROL:
			case KERN_SAVED_IDS:
			case KERN_OBOOTTIME:
				return seterrno(-ENOSTUP);
			case KERN_DOMAINNAME:
				return copy(uts_sysctl.domainname, oldp, strlen(uts_sysctl.domainname), *oldlenp);
			case KERN_MAXPARTITIONS:
			case KERN_RAWPARTITION:
			case KERN_NTPTIME:
			case KERN_TIMEX:
			case KERN_AUTONICETIME:
			case KERN_RTC_OFFSET:
			case KERN_ROOT_DEVICE:
			case KERN_MSGBUFSIZE:
			case KERN_FSYNC:
			case KERN_OLDSYSVMSG:
			case KERN_OLDSYSVSHM:
			case KERN_OLDSHORTCORENAME:
			case KERN_SYNCHRONIZED_IO:
			case KERN_IOV_MAX:
			case KERN_MBUF:
			case KERN_MAPPED_FILES:
			case KERN_MEMLOCK:
			case KERN_MEMLOCK_RANGE:
			case KERN_MEMORY_PROTECTION:
				return seterrno(-ENOSTUP);
			case KERN_LOGIN_NAME_MAX:
				*(long*)oldp = LOGIN_NAME_MAX;
				break;
			case KERN_DEFCORENAME:
			case KERN_LOGSIGEXIT:
			case KERN_PROC2:
			case KERN_PROC_ARGS:
			case KERN_FSCALE:
			case KERN_CCPU:
			case KERN_CP_TIME:
			case KERN_OLDSYSVIPC_INFO:
			case KERN_MSGBUF:
			case KERN_CONSDEV:
			case KERN_MAXPTYS:
			case KERN_PIPE:
			case KERN_MAXPHYS:
			case KERN_SBMAX:
			case KERN_TKSTAT:
			case KERN_MONOTONIC_CLOCK:
			case KERN_URND:
			case KERN_LABELSECTOR:
			case KERN_LABELOFFSET:
			case KERN_LWP:
			case KERN_FORKSLEEP:
			case KERN_POSIX_THREADS:
			case KERN_POSIX_SEMAPHORES:
			case KERN_POSIX_BARRIERS:
			case KERN_POSIX_TIMERS:
			case KERN_POSIX_SPIN_LOCKS:
			case KERN_POSIX_READER_WRITER_LOCKS:
			case KERN_DUMP_ON_PANIC:
			case KERN_SOMAXKVA:
			case KERN_ROOT_PARTITION:
			case KERN_DRIVERS:
			case KERN_BUF:
			case KERN_FILE2:
			case KERN_VERIEXEC:
			case KERN_CP_ID:
			case KERN_HARDCLOCK_TICKS:
				return seterrno(-ENOSTUP);
			case KERN_ARND:
				if (getrandom(oldp, *oldlenp, 0) < 0)
					return -1;
				break;
			case KERN_SYSVIPC:
			case KERN_BOOTTIME:
			case KERN_EVCNT:
			case KERN_SOFIXEDBUF:
			case KERN_ENTROPY:
				return seterrno(-ENOSTUP);
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
		case HW_MODEL:
			return get_from_file("/sys/devices/virtual/dmi/id/product_name", oldp, *oldlenp);
		case HW_NCPU:
			if ((*(long*)oldp = get_int_from_file("/sys/devices/system/cpu/possible")) <= 0)
				return -1;
			break;
		case HW_BYTEORDER:
			*(long*)oldp = 1234; /* BSDLibC only for x86_64 for now */
			break;
		case HW_PHYSMEM:
		case HW_USERMEM:
			return seterrno(-ENOSTUP);
		case HW_PAGESIZE:
			*(long*)oldp = PAGE_SIZE;
			break;
		case HW_DISKNAMES:
		case HW_IOSTATS:
			return seterrno(-ENOSTUP);
		case HW_MACHINE_ARCH:
			return copy(MACHINE_ARCH, oldp, strlen(MACHINE_ARCH), *oldlenp);
		case HW_ALIGNBYTES:
			*(long*)oldp = ALIGNBYTES;
			break;
		case HW_CNMAGIC:
		case HW_PHYSMEM64:
		case HW_USERMEM64:
		case HW_IOSTATNAMES:
			return seterrno(-ENOSTUP);
		case HW_NCPUONLINE:
			if ((*(long*)oldp = get_int_from_file("/sys/devices/system/cpu/online")) <= 0)
				return -1;
			break;
		default:
			return seterrno(-EINVAL);
		}
	}

	return 0;
}

static int
copy(const char *src, char *dst, size_t srclen, size_t dstlen)
{
	if (srclen > dstlen)
		return seterrno(-ENOMEM);
	strlcpy(dst, src, dstlen);
	return 0;
}

int
get_int_from_file(const char *path)
{
	char buf[128];
	char *str;
	const char *errstr = NULL;

	int fd = open(path, O_RDONLY);
	if (fd == -1)
		return -1;

	ssize_t len = read(fd, buf, sizeof(buf));
	buf[len] = '\0';

	close(fd);

	if ((str = strrchr(buf, '\n')) != NULL)
		*str = '\0';

	if ((str = strchr(buf, '-')) != NULL)
	{
		*str = '\0';
		char *endp = str + 1;

		int n1 = strtonum(buf, 0, INT32_MAX, &errstr);
		if (errstr != NULL)
			return -1;

		int n2 = strtonum(endp, 0, INT32_MAX, &errstr);
		if (errstr != NULL)
			return -1;

		return n2 - n1 + 1;
	}

	/* ',' is not supported */
	if ((str = strchr(buf, ',')) != NULL)
	{
		return 1; /* fallback */
	}

	int n = strtonum(buf, 0, INT32_MAX, &errstr);
	if (errstr != NULL)
		return -1;

	return n;
}

static int
get_from_file(const char *path, char *buf, size_t len)
{
	int fd, nl;
	char *str;
	if ((fd = open(path, O_RDONLY)) < 0)
		return -1;
	if ((nl = read(fd, buf, len)) <= 0)
		return -1;

	buf[nl] = '\0';

	if ((str = strrchr(buf, '\n')) != NULL)
		*str = '\0';
	return 0;
}
