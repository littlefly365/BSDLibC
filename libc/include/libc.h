#ifndef _LIBC_H
#define _LIBC_H	1

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>

static long
seterrno(long err)
{
	errno = (err <= -1 && err >= -4095) ? -err : errno;
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
