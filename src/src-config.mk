SUBDIRS=string ctype linux gen stdlib stdio compat locale citrus citrus-modules iconv \
	gdtoa termios regex thread-sub db time arch/amd64/gen cdb nls

ALL_C_SRCS := $(foreach dir,$(SUBDIRS),$(wildcard $(dir)/*.c))

GENERAL_INCLUDES := $(wildcard include/*.h)
SYSTEM_INCLUDES := $(wildcard include/sys/*.h)
MACHINE_INCLUDES := $(wildcard arch/$(MACHINE)/machine/*.h)

ARCH_S := $(wildcard arch/amd64/gen/*.S)
ALL_S_SRCS := $(ARCH_S)

C_OBJS := $(ALL_C_SRCS:%.c=%.o)
S_OBJS := $(ALL_S_SRCS:%.S=%.o)
ALL_OBJS := $(C_OBJS) $(S_OBJS)
