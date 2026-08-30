#ifndef _STDIO_H
#define _STDIO_H	1

#include <sys/types.h>
#include <stdarg.h>

#define	BUFSIZ	1024

typedef void* FILE;

static FILE *stdout;
static FILE *stderr;

/* see mini-printf/ for the implementations */
int snprintf(char* buf, size_t len, const char *fmt, ...);
int vsnprintf(char *buf, size_t len, const char *fmt, va_list va);
int printf(const char *fmt, ...);
int eprintf(const char *fmt, ...);
int veprintf(const char *fmt, va_list va);
int fputs(const char *s, FILE *stream);
int putchar(int c);


/* NetBSD implementations */
void perror(const char *s);

#endif
