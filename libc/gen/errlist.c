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
	"Resource temporarily unavailable",	/* 11 - EAGAIN */
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
	"Resource deadlock avoided",		/* 35 - EDEADLK */
	"File name too long",			/* 36 - ENAMETOOLONG */
	"No locks available",			/* 37 - ENOLCK */
	"Function not implemented",		/* 38 - ENOSYS */
	"Directory not empty",			/* 39 - ENOTEMPTY */
	"Too many levels of symbolic links",	/* 40 - ELOOP */
	"Undefined error: 41",			/* 41 - EERROR41 */
	"No message of desired type",		/* 42 - ENOMSG */
	"Identifier removed",			/* 43 - EIDRM */
	"Channel number out of range",		/* 44 - ECHRNG */
	"Level 2 not synchronized",		/* 45 - EL2NSYNC */
	"Level 3 halted",			/* 46 - EL3HLT */
	"Level 3 reset",			/* 47 - EL3RST */
	"Link number out of range",		/* 48 - ELNRNG */
	"Protocol driver not attached",		/* 49 - EUNATCH */
	"No CSI structure available",		/* 50 - ENOCSI */
	"Level 2 halted",			/* 51 - EL2HLT */
	"Invalid exchange",			/* 52 - EBADE */
	"Invalid request descriptor",		/* 53 - EBADR */
	"Exchange full",			/* 54 - EXFULL */
	"No anode",				/* 55 - ENOANO */
	"Invalid request code",			/* 56 - EBADRQC */
	"Invalid slot",				/* 57 - EBADSLT */
	"Undefined error: 58",			/* 58 - EERROR58 */
	"Bad font file format",			/* 59 - EBFONT */
	"Not a STREAM",				/* 60 - ENOSTR */
	"No message available",			/* 61 - ENODATA */
	"STREAM ioctl timeout",			/* 62 - ETIME */
	"No STREAM resources",			/* 63 - ENOSR */
	"Machine is not on the network",	/* 64 - ENONET */
	"Package not installed",		/* 65 - ENOPKG */
	"Too many levels of remote in path",	/* 66 - EREMOTE */
	"Link has been severed",		/* 67 - ENOLINK */
	"Advertise error",			/* 68 - EADV */
	"Srmount error",			/* 69 - ESRMNT */
	"Communication error on send",		/* 70 - ECOMM */
	"Protocol error",			/* 71 - EPROTO */
	"Multihop attempted",			/* 72 - EMULTIHOP */
	"RFS specific error",			/* 73 - EDOTDOT */
	"Bad or Corrupt message",		/* 74 - EBADMSG */
	"Value too large to be stored in data type",/* 75 - EOVERFLOW */
	"Name not unique on network",		/* 76 - ENOTUNIQ */
	"File descriptor in bad state",		/* 77 - EBADFD */
	"Remote address changed",		/* 78 - EREMCHG */
	"Can not access a needed shared library",/* 79 - ELIBACC */
	"Accessing a corrupted shared library",	/* 80 - ELIBBAD */
	".lib section in a.out corrupted",	/* 81 - ELIBSCN */
	"Attempting to link in too many shared libraries",/* 82 - ELIBMAX */
	"Cannot exec a shared library directly",/* 83 - ELIBEXEC */
	"Illegal byte sequence",		/* 84 - EILSEQ */
	"restart syscall",			/* 85 - ERESTART */
	"Streams pipe error",			/* 86 - ESTRPIPE */
	"Too many users",			/* 87 - EUSERS */
	"Socket operation on non-socket",	/* 88 - ENOTSOCK */
	"Destination address required",		/* 89 - EDESTADDRREQ */
	"Message too long",			/* 90 - EMSGSIZE */
	"Protocol wrong type for socket",	/* 91 - EPROTOTYPE */
	"Protocol option not available",	/* 92 - ENOPROTOOPT */
	"Protocol not supported",		/* 93 - EPROTONOSUPPORT */
	"Socket type not supported",		/* 94 - ESOCKTNOSUPPORT */
	"Operation not supported",		/* 95 - EOPNOTSUPP */
	"Protocol family not supported",	/* 96 - EPFNOSUPPORT */
	"Address family not supported by protocol family",/* 97 - EAFNOSUPPORT */
	"Address already in use",		/* 98 - EADDRINUSE */
	"Can't assign requested address",	/* 99 - EADDRNOTAVAIL */
	"Network is down",			/* 100 - ENETDOWN */
	"Network is unreachable",		/* 101 - ENETUNREACH */
	"Network dropped connection on reset",	/* 102 - ENETRESET */
	"Software caused connection abort",	/* 103 - ECONNABORTED */
	"Connection reset by peer",		/* 104 - ECONNRESET */
	"No buffer space available",		/* 105 - ENOBUFS */
	"Socket is already connected",		/* 106 - EISCONN */
	"Socket is not connected",		/* 107 - ENOTCONN */
	"Can't send after socket shutdown",	/* 108 - ESHUTDOWN */
	"Too many references: can't splice",	/* 109 - ETOOMANYREFS */
	"Operation timed out",			/* 110 - ETIMEDOUT */
	"Connection refused",			/* 111 - ECONNREFUSED */
	"Host is down",				/* 112 - EHOSTDOWN */
	"No route to host",			/* 113 - EHOSTUNREACH */
	"Operation already in progress",	/* 114 - EALREADY */
	"Operation now in progress",		/* 115 - EINPROGRESS */
	"Stale NFS file handle",		/* 116 - ESTALE */
	"Structure needs cleaning",		/* 117 - EUCLEAN */
	"Not a XENIX named type file",		/* 118 - ENOTNAM */
	"No XENIX semaphores available",	/* 119 - ENAVAIL */
	"Is a named type file",			/* 120 - EISNAM */
	"Remote I/O error",			/* 121 - EREMOTEIO */
	"Disc quota exceeded",			/* 122 - EDQUOT */
	"No medium found",			/* 123 - ENOMEDIUM */
	"Wrong medium type",			/* 124 - EMEDIUMTYPE */
	"Operation canceled",			/* 125 - ECANCELED */
	"Required key not available",		/* 126 - ENOKEY */
	"Key has expired",			/* 127 - EKEYEXPIRED */
	"Key has been revoked",			/* 128 - EKEYREVOKED */
	"Key was rejected by service",		/* 129 - EKEYREJECTED */
	"Previous owner died",			/* 130 - EOWNERDEAD */
	"State not recoverable",		/* 131 - ENOTRECOVERABLE */
	"Operation not possible due to RF-kill",/* 132 - ERFKILL */
	"Memory page has hardware error",	/* 133 - EHWPOISON */
	"Too many processes",			/* 134 - EPROCLIM */
	"RPC structure is bad",			/* 135 - EBADRPC */
	"RPC version wrong",			/* 136 - ERPCMISMATCH */
	"RPC program not available",		/* 137 - EPROGUNAVAIL */
	"Program version wrong",		/* 138 - EPROGMISMATCH */
	"Bad procedure for program",		/* 139 - EPROCUNAVAIL */
	"Inappropriate file type or format",	/* 140 - EFTYPE */
	"Authentication error",			/* 141 - EAUTH */
	"Need authenticator",			/* 142 - ENEEDAUTH */
	"Attribute not found",			/* 143 - ENOATTR */
};

const int sys_nerr = sizeof(errlist) / sizeof(errlist[0]);
const char * const *sys_errlist = errlist;
