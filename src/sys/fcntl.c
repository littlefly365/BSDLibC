#include <sys/syscall.h>
#include <sys/cdefs.h>
#include <stdarg.h>
#include <fcntl.h>
#include <asm.h>

#ifdef __weak_alias
__weak_alias(fcntl, _fcntl);
#endif

int
_fcntl(int fd, int cmd, ...)
{
	u_long arg;
	va_list ap;

	va_start(ap, cmd);
	arg = va_arg(ap, u_long);
	va_end(ap);

	return __syscall3(SYS_fcntl, fd, cmd, (void *)arg);
}
