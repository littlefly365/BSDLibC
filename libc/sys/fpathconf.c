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

#include <sys/cdefs.h>
#include <sys/statvfs.h>
#include <sys/sysctl.h>
#include <sys/syslimits.h>
#include <unistd.h>
#include "libc.h"

#ifdef __weak_alias
__weak_alias(fpathconf, _fpathconf);
#endif

static long namemax(int fd);

/*
 * TODO: check that macro values are correct
 * for Linux.
*/

long
_fpathconf(int fd, int name)
{
	if (fd < 0)
		return seterrno(-EBADF);

	switch (name)
	{
	case _PC_LINK_MAX:
		return LINK_MAX;
	case _PC_MAX_CANON:
		return MAX_CANON;
	case _PC_MAX_INPUT:
		return MAX_INPUT;
	case _PC_NAME_MAX:
		return namemax(fd);
	case _PC_PATH_MAX:
		return PATH_MAX;
	case _PC_PIPE_BUF:
		return PIPE_BUF;
	case _PC_CHOWN_RESTRICTED:
		return _POSIX_CHOWN_RESTRICTED;
	case _PC_NO_TRUNC:
		return _POSIX_NO_TRUNC;
	case _PC_VDISABLE:
		return _POSIX_VDISABLE;
	case _PC_SYNC_IO:
		int asn;
		size_t len = sizeof(asn);
		int mib[2] = { CTL_KERN, KERN_SYNCHRONIZED_IO };
		if (sysctl(mib, 2, &asn, &len, NULL, 0) < 0)
			return -1;
		return asn;
	case _PC_FILESIZEBITS:
		return 64; 	/* 64? */
	case _PC_SYMLINK_MAX:
		return -1;	/* Glibc says there's not any system with this limit */
	case _PC_2_SYMLINKS:
		return 1;
	case _PC_ACL_EXTENDED:
		return 0;	/* fd do not support acl */
	case _PC_MIN_HOLE_SIZE:
		return 4096;
	case _PC_ACL_PATH_MAX:
		return PATH_MAX; /* is it the same? */
	case _PC_ACL_NFS4:
		return 0;	/* fd do not support NFSv4 acl */
	default:
		break;
	}

	return seterrno(-EINVAL);
}

static long
namemax(int fd)
{
	struct statvfs st;
	if (fstatvfs(fd, &st) != 0)
		return NAME_MAX;
	return st.f_namemax;
}
