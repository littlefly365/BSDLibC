#ifndef _STDIO_H
#define _STDIO_H	1

#include <stdarg.h>

#define	BUFSIZ	1024

/* see mini-printf/ for the implementations */
int printf(const char *fmt, ...);
int eprintf(const char *fmt, ...);
int veprintf(const char *fmt, va_list va);

#endif
