#ifndef _LOCALE_H
#define _LOCALE_H	1

#if (_POSIX_C_SOURCE - 0) >= 200809L || defined(_NETBSD_SOURCE)
#   ifndef __LOCALE_T_DECLARED
typedef void* locale_t;
#   define __LOCALE_T_DECLARED
#   endif

#endif
