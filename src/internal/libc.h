#ifndef _LIBC_H
#define _LIBC_H	1

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
	__long(ret);									\
}
#endif

static long
seterrno(long err)
{
	if (err < 0) {
		errno = -err;
		return -1;
	}

	return err;
}

#endif
