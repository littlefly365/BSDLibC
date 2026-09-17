/* src/linux/open.c: modified by littlefly365 */
// SPDX-License-Identifier: BSD-3-Clause

#include <sys/syscall.h>
#include <sys/cdefs.h>
#include <fcntl.h>
#include <stdarg.h>
#include <asm.h>

#ifdef __weak_alias
__weak_alias(open, _open);
#endif

int
_open(const char *filename, int flags, ...)
{
	va_list args;
	va_start(args, flags);
	long fd;

	if(flags & O_CREAT) {
		mode_t mode = va_arg(args, mode_t);
		fd = __syscall3(SYS_open, filename, flags, mode);
	} else
		fd = __syscall2(SYS_open, filename, flags);
	va_end(args);

	if (fd < 0)
		return -1;

	return (int)fd;
}
