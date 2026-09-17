SRCS=_start.S crt0.c
OBJS=_start.o crt0.o

-include ../../config.mk

CFLAGS+=-ffreestanding -nostdlib -nostdinc
CFLAGS+=-I../include

all: $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
clean:
	rm -rf $(OBJS)
