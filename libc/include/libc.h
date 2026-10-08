#ifndef _LIBC_H
#define _LIBC_H	1

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

#define __long(var)	((long)var)

#if defined(__x86_64__) || defined(__amd64__)
static inline long									\
__syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6) {		\
	unsigned long ret;								\
	register long r10 __asm__("r10") = __long(a4);					\
	register long r8 __asm__("r8") = __long(a5);					\
	register long r9 __asm__("r9") = __long(a6);					\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"__long(a1), 		\
				"S"__long(a2), "d"__long(a3), "r"(r10), "r"(r8),	\
				"r"(r9) : "rcx", "r11", "memory");			\
	return __long(ret);								\
}
#ifdef _CSU
#define __syscall3(n, a1, a2, a3) __syscall6(n, __long(a1), __long(a2), __long(a3), 0, 0, 0)
#endif
#endif

static long
seterrno(long err)
{
	errno = (err < 0) ? -err : errno;
	return (err < 0) ? -1 : err;
}

static int
procfdname(int fd, char *buf, size_t buflen)
{
        char proc[64];
        snprintf(proc, sizeof(proc), "/proc/self/fd/%d", fd);
        ssize_t n = readlink(proc, buf, buflen);
        if (n == -1)
                return -1;
        buf[n] = '\0';
        return 0;
}

#endif
