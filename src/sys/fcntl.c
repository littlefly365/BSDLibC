#include <sys/syscall.h>
#include <sys/cdefs.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include "libc.h"

#ifdef __weak_alias
__weak_alias(fcntl, _fcntl);
#endif

int
_fcntl(int fd, int cmd, ...)
{
	u_long arg;
	va_list ap;

	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	return syscall(SYS_fcntl, fd, cmd, (void *)arg);
}
