/* Automatically generated file; do not edit */
#include <sys/cdefs.h>
__RCSID("$NetBSD: errlist.awk,v 1.4 2010/12/16 22:52:32 joerg Exp $");
#include <errno.h>
static const char *const errlist[] = {
	"Undefined error: 0",			/* 0 - ENOERROR */
	"Operation not permitted",		/* 1 - EPERM */
	"No such file or directory",		/* 2 - ENOENT */
	"No such process",			/* 3 - ESRCH */
	"Interrupted system call",		/* 4 - EINTR */
	"Input/output error",			/* 5 - EIO */
	"Device not configured",		/* 6 - ENXIO */
	"Argument list too long",		/* 7 - E2BIG */
	"Exec format error",			/* 8 - ENOEXEC */
	"Bad file descriptor",			/* 9 - EBADF */
	"No child processes",			/* 10 - ECHILD */
	"Resource deadlock avoided",		/* 11 - EDEADLK */
	"Cannot allocate memory",		/* 12 - ENOMEM */
	"Permission denied",			/* 13 - EACCES */
	"Bad address",				/* 14 - EFAULT */
	"Block device required",		/* 15 - ENOTBLK */
	"Device busy",				/* 16 - EBUSY */
	"File exists",				/* 17 - EEXIST */
	"Cross-device link",			/* 18 - EXDEV */
	"Operation not supported by device",	/* 19 - ENODEV */
	"Not a directory",			/* 20 - ENOTDIR */
	"Is a directory",			/* 21 - EISDIR */
	"Invalid argument",			/* 22 - EINVAL */
	"Too many open files in system",	/* 23 - ENFILE */
	"Too many open files",			/* 24 - EMFILE */
	"Inappropriate ioctl for device",	/* 25 - ENOTTY */
	"Text file busy",			/* 26 - ETXTBSY */
	"File too large",			/* 27 - EFBIG */
	"No space left on device",		/* 28 - ENOSPC */
	"Illegal seek",				/* 29 - ESPIPE */
	"Read-only file system",		/* 30 - EROFS */
	"Too many links",			/* 31 - EMLINK */
	"Broken pipe",				/* 32 - EPIPE */
	"Numerical argument out of domain",	/* 33 - EDOM */
	"Result too large or too small",	/* 34 - ERANGE */
	"Resource temporarily unavailable",	/* 35 - EAGAIN */
	"Operation now in progress",		/* 36 - EINPROGRESS */
	"Operation already in progress",	/* 37 - EALREADY */
	"Socket operation on non-socket",	/* 38 - ENOTSOCK */
	"Destination address required",		/* 39 - EDESTADDRREQ */
	"Message too long",			/* 40 - EMSGSIZE */
	"Protocol wrong type for socket",	/* 41 - EPROTOTYPE */
	"Protocol option not available",	/* 42 - ENOPROTOOPT */
	"Protocol not supported",		/* 43 - EPROTONOSUPPORT */
	"Socket type not supported",		/* 44 - ESOCKTNOSUPPORT */
	"Operation not supported",		/* 45 - EOPNOTSUPP */
	"Protocol family not supported",	/* 46 - EPFNOSUPPORT */
	"Address family not supported by protocol family",/* 47 - EAFNOSUPPORT */
	"Address already in use",		/* 48 - EADDRINUSE */
	"Can't assign requested address",	/* 49 - EADDRNOTAVAIL */
	"Network is down",			/* 50 - ENETDOWN */
	"Network is unreachable",		/* 51 - ENETUNREACH */
	"Network dropped connection on reset",	/* 52 - ENETRESET */
	"Software caused connection abort",	/* 53 - ECONNABORTED */
	"Connection reset by peer",		/* 54 - ECONNRESET */
	"No buffer space available",		/* 55 - ENOBUFS */
	"Socket is already connected",		/* 56 - EISCONN */
	"Socket is not connected",		/* 57 - ENOTCONN */
	"Can't send after socket shutdown",	/* 58 - ESHUTDOWN */
	"Too many references: can't splice",	/* 59 - ETOOMANYREFS */
	"Operation timed out",			/* 60 - ETIMEDOUT */
	"Connection refused",			/* 61 - ECONNREFUSED */
	"Too many levels of symbolic links",	/* 62 - ELOOP */
	"File name too long",			/* 63 - ENAMETOOLONG */
	"Host is down",				/* 64 - EHOSTDOWN */
	"No route to host",			/* 65 - EHOSTUNREACH */
	"Directory not empty",			/* 66 - ENOTEMPTY */
	"Too many processes",			/* 67 - EPROCLIM */
	"Too many users",			/* 68 - EUSERS */
	"Disc quota exceeded",			/* 69 - EDQUOT */
	"Stale NFS file handle",		/* 70 - ESTALE */
	"Too many levels of remote in path",	/* 71 - EREMOTE */
	"RPC struct is bad",			/* 72 - EBADRPC */
	"RPC version wrong",			/* 73 - ERPCMISMATCH */
	"RPC prog. not avail",			/* 74 - EPROGUNAVAIL */
	"Program version wrong",		/* 75 - EPROGMISMATCH */
	"Bad procedure for program",		/* 76 - EPROCUNAVAIL */
	"No locks available",			/* 77 - ENOLCK */
	"Function not implemented",		/* 78 - ENOSYS */
	"Inappropriate file type or format",	/* 79 - EFTYPE */
	"Authentication error",			/* 80 - EAUTH */
	"Need authenticator",			/* 81 - ENEEDAUTH */
	"Identifier removed",			/* 82 - EIDRM */
	"No message of desired type",		/* 83 - ENOMSG */
	"Value too large to be stored in data type",/* 84 - EOVERFLOW */
	"Illegal byte sequence",		/* 85 - EILSEQ */
	"Not supported",			/* 86 - ENOTSUP */
	"Operation canceled",			/* 87 - ECANCELED */
	"Bad or Corrupt message",		/* 88 - EBADMSG */
	"No message available",			/* 89 - ENODATA */
	"No STREAM resources",			/* 90 - ENOSR */
	"Not a STREAM",				/* 91 - ENOSTR */
	"STREAM ioctl timeout",			/* 92 - ETIME */
	"Attribute not found",			/* 93 - ENOATTR */
	"Multihop attempted",			/* 94 - EMULTIHOP */
	"Link has been severed",		/* 95 - ENOLINK */
	"Protocol error",			/* 96 - EPROTO */
	"Previous owner died",			/* 97 - EOWNERDEAD */
	"State not recoverable",		/* 98 - ENOTRECOVERABLE */
};

const int sys_nerr = sizeof(errlist) / sizeof(errlist[0]);
const char * const *sys_errlist = errlist;
