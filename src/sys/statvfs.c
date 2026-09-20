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

#include <sys/syscall.h>
#include <sys/statvfs.h>
#include <sys/cdefs.h>
#include <string.h>
#include <errno.h>
#include <asm.h>

#include "magic.h"

struct statvfs_linux {
	unsigned long f_bsize;
	unsigned long f_frsize;
	fsblkcnt_t f_blocks;
	fsblkcnt_t f_bfree;
	fsblkcnt_t f_bavail;
	fsfilcnt_t f_files;
	fsfilcnt_t f_ffree;
	fsfilcnt_t f_favail;
	unsigned long f_fsid;
	unsigned long f_flag;
	unsigned long f_namemax;
	unsigned int f_type;
	int __reserved[5];
};

static const char
*getfstypename(unsigned int ftype)
{
	const char *name = NULL;
	switch (ftype) {
	case EXT4_SUPER_MAGIC:
		name = "ext4";
		break;
	case BTRFS_SUPER_MAGIC:
		name = "btrfs";
		break;
	case XFS_SUPER_MAGIC:
		name = "xfs";
		break;
	case TMPFS_MAGIC:
		name = "tmpfs";
		break;
	case MSDOS_SUPER_MAGIC:
		name = "fat";
		break;
	case EXFAT_SUPER_MAGIC:
		name = "exfat";
		break;
	case PROC_SUPER_MAGIC:
		name = "proc";
		break;
	case SYSFS_MAGIC:
		name = "sysfs";
		break;
	case EFIVARFS_MAGIC:
		name = "efivars";
		break;
	case CGROUP2_SUPER_MAGIC:
		name = "cgroup2";
		break;
	default:
		name = "unknown";
		break;
	}

	return name;
}

static int
__vfs(struct statvfs *restrict buf, struct statvfs_linux *restrict vfs_linux, int ret)
{
	if (ret != 0) {
		errno -ret;
		return ret;
	}

	buf->f_flag = vfs_linux->f_flag;
	buf->f_bsize = vfs_linux->f_bsize;
	buf->f_frsize = vfs_linux->f_frsize;
	buf->f_iosize = 0;

	buf->f_blocks = vfs_linux->f_blocks;
	buf->f_bfree = vfs_linux->f_bfree;
	buf->f_bavail = vfs_linux->f_bavail;
	buf->f_bresvd = 0;

	buf->f_files = vfs_linux->f_files;
	buf->f_ffree = vfs_linux->f_ffree;
	buf->f_favail = vfs_linux->f_favail;
	buf->f_fresvd = 0;

	/* We can't get this information in Linux */
	buf->f_syncreads = 0;
	buf->f_syncwrites = 0;
	buf->f_asyncreads = 0;
	buf->f_asyncwrites = 0;

	buf->f_fsidx = (fsid_t){ .__fsid_val = 0 };
	buf->f_fsid = vfs_linux->f_fsid;
	buf->f_namemax = vfs_linux->f_namemax;
	buf->f_owner = 0;

	strlcpy(buf->f_fstypename, getfstypename(vfs_linux->f_type), sizeof(buf->f_fstypename));
	strlcpy(buf->f_mntonname, "unknown", sizeof(buf->f_mntonname));
	strlcpy(buf->f_mntfromname, "/", sizeof(buf->f_mntfromname));
	strlcpy(buf->f_mntfromlabel, "unknown", sizeof(buf->f_mntfromlabel));
	return 0;
}

int
__statvfs190(const char *restrict path, struct statvfs *restrict buf, int flags __unused)
{
	struct statvfs_linux *vfs_linux = {0};
	int ret = __syscall2(SYS_statfs, path, vfs_linux);
	return __vfs(buf, vfs_linux, ret);
}

int
__fstatvfs190(int fd, struct statvfs *restrict buf, int flags __unused)
{
	struct statvfs_linux *vfs_linux = {0};
	int ret = __syscall2(SYS_fstatfs, fd, vfs_linux);
	return __vfs(buf, vfs_linux, ret);
}

int
__statvfs90(const char *restrict path, struct statvfs *restrict buf)
{
	return __statvfs190(path, buf, 0);
}

int
__fstatvfs90(int fd, struct statvfs *restrict buf)
{
	return __fstatvfs190(fd, buf, 0);
}
