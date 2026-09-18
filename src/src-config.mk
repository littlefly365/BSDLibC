STRING := $(wildcard string/*.c)
CTYPE := $(wildcard ctype/*.c)
LINUX := $(wildcard linux/*.c)
GEN := $(wildcard gen/*.c)
STDLIB := $(wildcard stdlib/*.c)
STDIO := $(wildcard stdio/*.c)
MD := $(wildcard md/*.c)
LIB := csu/libc_start.c
COMPAT := $(wildcard compat/*.c)
LOCALE := $(wildcard locale/*.c)
CITRUS := $(wildcard citrus/*.c) $(wildcard citrus-modules/*.c)
ICONV := $(wildcard iconv/*.c)
GDTOA := $(wildcard gdtoa/*.c)
TERMIOS := $(wildcard termios/*.c)
REGEX := $(wildcard regex/*.c)
THREAD_SUB := $(wildcard thread-sub/*.c)
DB := $(wildcard db/*.c)
TIME := $(wildcard time/*.c)
ARCH_C := $(wildcard arch/amd64/gen/*.c)
ARCH_S := $(wildcard arch/amd64/gen/*.S)

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ALL_C_SRCS := $(STRING) $(CTYPE) $(LINUX) $(GEN) $(STDLIB) $(MD) $(LIB) $(COMPAT) \
		$(LOCALE) $(STDIO) $(CITRUS) $(ICONV) $(GDTOA) $(ARCH_C) $(TERMIOS) \
		$(REGEX) $(TIME) $(THREAD_SUB) $(DB)

ALL_S_SRCS := $(ARCH_S)
C_OBJS := $(ALL_C_SRCS:%.c=%.o)
S_OBJS := $(ALL_S_SRCS:%.S=%.o)
ALL_OBJS := $(C_OBJS) $(S_OBJS)
