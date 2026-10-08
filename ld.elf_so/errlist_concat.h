/* Automatically generated file; do not edit */
#include <sys/cdefs.h>
__RCSID("$NetBSD: errlist.awk,v 1.4 2010/12/16 22:52:32 joerg Exp $");
#include <errno.h>
static const char concat_errlist[] = {
	"Undefined error: 0\0"			/* 0 - ENOERROR */
	"Operation not permitted\0"		/* 1 - EPERM */
	"No such file or directory\0"		/* 2 - ENOENT */
	"No such process\0"			/* 3 - ESRCH */
	"Interrupted system call\0"		/* 4 - EINTR */
	"Input/output error\0"			/* 5 - EIO */
	"Device not configured\0"		/* 6 - ENXIO */
	"Argument list too long\0"		/* 7 - E2BIG */
	"Exec format error\0"			/* 8 - ENOEXEC */
	"Bad file descriptor\0"			/* 9 - EBADF */
	"No child processes\0"			/* 10 - ECHILD */
	"Resource temporarily unavailable\0"	/* 11 - EAGAIN */
	"Cannot allocate memory\0"		/* 12 - ENOMEM */
	"Permission denied\0"			/* 13 - EACCES */
	"Bad address\0"				/* 14 - EFAULT */
	"Block device required\0"		/* 15 - ENOTBLK */
	"Device busy\0"				/* 16 - EBUSY */
	"File exists\0"				/* 17 - EEXIST */
	"Cross-device link\0"			/* 18 - EXDEV */
	"Operation not supported by device\0"	/* 19 - ENODEV */
	"Not a directory\0"			/* 20 - ENOTDIR */
	"Is a directory\0"			/* 21 - EISDIR */
	"Invalid argument\0"			/* 22 - EINVAL */
	"Too many open files in system\0"	/* 23 - ENFILE */
	"Too many open files\0"			/* 24 - EMFILE */
	"Inappropriate ioctl for device\0"	/* 25 - ENOTTY */
	"Text file busy\0"			/* 26 - ETXTBSY */
	"File too large\0"			/* 27 - EFBIG */
	"No space left on device\0"		/* 28 - ENOSPC */
	"Illegal seek\0"			/* 29 - ESPIPE */
	"Read-only file system\0"		/* 30 - EROFS */
	"Too many links\0"			/* 31 - EMLINK */
	"Broken pipe\0"				/* 32 - EPIPE */
	"Numerical argument out of domain\0"	/* 33 - EDOM */
	"Result too large or too small\0"	/* 34 - ERANGE */
	"Resource deadlock avoided\0"		/* 35 - EDEADLK */
	"File name too long\0"			/* 36 - ENAMETOOLONG */
	"No locks available\0"			/* 37 - ENOLCK */
	"Function not implemented\0"		/* 38 - ENOSYS */
	"Directory not empty\0"			/* 39 - ENOTEMPTY */
	"Too many levels of symbolic links\0"	/* 40 - ELOOP */
	"Undefined error: 41\0"			/* 41 - EERROR41 */
	"No message of desired type\0"		/* 42 - ENOMSG */
	"Identifier removed\0"			/* 43 - EIDRM */
	"Channel number out of range\0"		/* 44 - ECHRNG */
	"Level 2 not synchronized\0"		/* 45 - EL2NSYNC */
	"Level 3 halted\0"			/* 46 - EL3HLT */
	"Level 3 reset\0"			/* 47 - EL3RST */
	"Link number out of range\0"		/* 48 - ELNRNG */
	"Protocol driver not attached\0"	/* 49 - EUNATCH */
	"No CSI structure available\0"		/* 50 - ENOCSI */
	"Level 2 halted\0"			/* 51 - EL2HLT */
	"Invalid exchange\0"			/* 52 - EBADE */
	"Invalid request descriptor\0"		/* 53 - EBADR */
	"Exchange full\0"			/* 54 - EXFULL */
	"No anode\0"				/* 55 - ENOANO */
	"Invalid request code\0"		/* 56 - EBADRQC */
	"Invalid slot\0"			/* 57 - EBADSLT */
	"Undefined error: 58\0"			/* 58 - EERROR58 */
	"Bad font file format\0"		/* 59 - EBFONT */
	"Not a STREAM\0"			/* 60 - ENOSTR */
	"No message available\0"		/* 61 - ENODATA */
	"STREAM ioctl timeout\0"		/* 62 - ETIME */
	"No STREAM resources\0"			/* 63 - ENOSR */
	"Machine is not on the network\0"	/* 64 - ENONET */
	"Package not installed\0"		/* 65 - ENOPKG */
	"Too many levels of remote in path\0"	/* 66 - EREMOTE */
	"Link has been severed\0"		/* 67 - ENOLINK */
	"Advertise error\0"			/* 68 - EADV */
	"Srmount error\0"			/* 69 - ESRMNT */
	"Communication error on send\0"		/* 70 - ECOMM */
	"Protocol error\0"			/* 71 - EPROTO */
	"Multihop attempted\0"			/* 72 - EMULTIHOP */
	"RFS specific error\0"			/* 73 - EDOTDOT */
	"Bad or Corrupt message\0"		/* 74 - EBADMSG */
	"Value too large to be stored in data type\0"/* 75 - EOVERFLOW */
	"Name not unique on network\0"		/* 76 - ENOTUNIQ */
	"File descriptor in bad state\0"	/* 77 - EBADFD */
	"Remote address changed\0"		/* 78 - EREMCHG */
	"Can not access a needed shared library\0"/* 79 - ELIBACC */
	"Accessing a corrupted shared library\0"/* 80 - ELIBBAD */
	".lib section in a.out corrupted\0"	/* 81 - ELIBSCN */
	"Attempting to link in too many shared libraries\0"/* 82 - ELIBMAX */
	"Cannot exec a shared library directly\0"/* 83 - ELIBEXEC */
	"Illegal byte sequence\0"		/* 84 - EILSEQ */
	"restart syscall\0"			/* 85 - ERESTART */
	"Streams pipe error\0"			/* 86 - ESTRPIPE */
	"Too many users\0"			/* 87 - EUSERS */
	"Socket operation on non-socket\0"	/* 88 - ENOTSOCK */
	"Destination address required\0"	/* 89 - EDESTADDRREQ */
	"Message too long\0"			/* 90 - EMSGSIZE */
	"Protocol wrong type for socket\0"	/* 91 - EPROTOTYPE */
	"Protocol option not available\0"	/* 92 - ENOPROTOOPT */
	"Protocol not supported\0"		/* 93 - EPROTONOSUPPORT */
	"Socket type not supported\0"		/* 94 - ESOCKTNOSUPPORT */
	"Operation not supported\0"		/* 95 - EOPNOTSUPP */
	"Protocol family not supported\0"	/* 96 - EPFNOSUPPORT */
	"Address family not supported by protocol family\0"/* 97 - EAFNOSUPPORT */
	"Address already in use\0"		/* 98 - EADDRINUSE */
	"Can't assign requested address\0"	/* 99 - EADDRNOTAVAIL */
	"Network is down\0"			/* 100 - ENETDOWN */
	"Network is unreachable\0"		/* 101 - ENETUNREACH */
	"Network dropped connection on reset\0"	/* 102 - ENETRESET */
	"Software caused connection abort\0"	/* 103 - ECONNABORTED */
	"Connection reset by peer\0"		/* 104 - ECONNRESET */
	"No buffer space available\0"		/* 105 - ENOBUFS */
	"Socket is already connected\0"		/* 106 - EISCONN */
	"Socket is not connected\0"		/* 107 - ENOTCONN */
	"Can't send after socket shutdown\0"	/* 108 - ESHUTDOWN */
	"Too many references: can't splice\0"	/* 109 - ETOOMANYREFS */
	"Operation timed out\0"			/* 110 - ETIMEDOUT */
	"Connection refused\0"			/* 111 - ECONNREFUSED */
	"Host is down\0"			/* 112 - EHOSTDOWN */
	"No route to host\0"			/* 113 - EHOSTUNREACH */
	"Operation already in progress\0"	/* 114 - EALREADY */
	"Operation now in progress\0"		/* 115 - EINPROGRESS */
	"Stale NFS file handle\0"		/* 116 - ESTALE */
	"Structure needs cleaning\0"		/* 117 - EUCLEAN */
	"Not a XENIX named type file\0"		/* 118 - ENOTNAM */
	"No XENIX semaphores available\0"	/* 119 - ENAVAIL */
	"Is a named type file\0"		/* 120 - EISNAM */
	"Remote I/O error\0"			/* 121 - EREMOTEIO */
	"Disc quota exceeded\0"			/* 122 - EDQUOT */
	"No medium found\0"			/* 123 - ENOMEDIUM */
	"Wrong medium type\0"			/* 124 - EMEDIUMTYPE */
	"Operation canceled\0"			/* 125 - ECANCELED */
	"Required key not available\0"		/* 126 - ENOKEY */
	"Key has expired\0"			/* 127 - EKEYEXPIRED */
	"Key has been revoked\0"		/* 128 - EKEYREVOKED */
	"Key was rejected by service\0"		/* 129 - EKEYREJECTED */
	"Previous owner died\0"			/* 130 - EOWNERDEAD */
	"State not recoverable\0"		/* 131 - ENOTRECOVERABLE */
	"Operation not possible due to RF-kill\0"/* 132 - ERFKILL */
	"Memory page has hardware error\0"	/* 133 - EHWPOISON */
	"Too many processes\0"			/* 134 - EPROCLIM */
	"RPC structure is bad\0"		/* 135 - EBADRPC */
	"RPC version wrong\0"			/* 136 - ERPCMISMATCH */
	"RPC program not available\0"		/* 137 - EPROGUNAVAIL */
	"Program version wrong\0"		/* 138 - EPROGMISMATCH */
	"Bad procedure for program\0"		/* 139 - EPROCUNAVAIL */
	"Inappropriate file type or format\0"	/* 140 - EFTYPE */
	"Authentication error\0"		/* 141 - EAUTH */
	"Need authenticator\0"			/* 142 - ENEEDAUTH */
	"Attribute not found\0"			/* 143 - ENOATTR */
};

static const int concat_nerr = 144;
static const unsigned short concat_offset[] = {
	0,
	19,
	43,
	69,
	85,
	109,
	128,
	150,
	173,
	191,
	211,
	230,
	263,
	286,
	304,
	316,
	338,
	350,
	362,
	380,
	414,
	430,
	445,
	462,
	492,
	512,
	543,
	558,
	573,
	597,
	610,
	632,
	647,
	659,
	692,
	722,
	748,
	767,
	786,
	811,
	831,
	865,
	885,
	912,
	931,
	959,
	984,
	999,
	1013,
	1038,
	1067,
	1094,
	1109,
	1126,
	1153,
	1167,
	1176,
	1197,
	1210,
	1230,
	1251,
	1264,
	1285,
	1306,
	1326,
	1356,
	1378,
	1412,
	1434,
	1450,
	1464,
	1492,
	1507,
	1526,
	1545,
	1568,
	1610,
	1637,
	1666,
	1689,
	1728,
	1765,
	1797,
	1845,
	1883,
	1905,
	1921,
	1940,
	1955,
	1986,
	2015,
	2032,
	2063,
	2093,
	2116,
	2142,
	2166,
	2196,
	2244,
	2267,
	2298,
	2314,
	2337,
	2373,
	2406,
	2431,
	2457,
	2485,
	2509,
	2542,
	2576,
	2596,
	2615,
	2628,
	2645,
	2675,
	2701,
	2723,
	2748,
	2776,
	2806,
	2827,
	2844,
	2864,
	2880,
	2898,
	2917,
	2944,
	2960,
	2981,
	3009,
	3029,
	3051,
	3089,
	3120,
	3139,
	3160,
	3178,
	3204,
	3226,
	3252,
	3286,
	3307,
	3326,
	3346,
};
