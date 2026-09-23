.PATH: ${.CURDIR}/arch/amd64/atomic ${.CURDIR}/arch/amd64/gen ${.CURDIR}/arch/amd64/stdlib ${.CURDIR}/arch/amd64/string

SRCS+=atomic.S alloca.S byte_swap_2.S byte_swap_4.S byte_swap_8.S flt_rounds.S fpclassifyl.c \
      abs.S div.S labs.S ldiv.S bcopy.S ffs.S memchr.S memcpy.S memmove.S memset.S strcat.S \
      strchr.S strcmp.S strcpy.S strlen.S strncmp.S strrchr.S swab.S
