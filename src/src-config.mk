SUBDIRS_C_SOURCE=string ctype linux gen stdlib stdio compat locale citrus citrus-modules iconv \
		gdtoa termios regex thread-sub db time arch/amd64/gen cdb nls
SUBDIRS_S_SOURCE=gen string stdlib

ALL_C_SRCS := $(foreach dir,$(SUBDIRS_C_SOURCE),$(wildcard $(dir)/*.c)) $(CURDIR)/csu/libc_start.c
ALL_S_SRCS := $(foreach dir,$(SUBDIRS_S_SOURCE),$(wildcard arch/amd64/$(dir)/*.S))

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

C_OBJS := $(ALL_C_SRCS:%.c=%.o)
S_OBJS := $(ALL_S_SRCS:%.S=%.o)
ALL_OBJS := $(C_OBJS) $(S_OBJS)
