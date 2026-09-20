CFLAGS=-ffreestanding -nostdinc -fno-stack-protector
CFLAGS+=-I$(CURDIR)/common -I$(CURDIR) -I../include -I../internal

all: crt0.o crtbegin.o crtend.o crti.o crtn.o sysident.o

crt0.o: amd64/crt0.S common/crt0-common.c
	$(CC) -c amd64/crt0.S -o crt0.S.o $(CFLAGS)
	$(CC) -c common/crt0-common.c -o crt0.c.o $(CFLAGS)
	$(LD) -r -o $@ crt0.S.o crt0.c.o
	rm -f crt0.S.o crt0.c.o
crtbegin.o: amd64/crtbegin.S
	$(CC) -c amd64/crtbegin.S -o crtbegin.o $(CFLAGS)
crtend.o: amd64/crtend.S
	$(CC) -c amd64/crtend.S -o crtend.o $(CFLAGS)
crti.o: amd64/crti.S
	$(CC) -c amd64/crti.S -o crti.o $(CFLAGS)
crtn.o: amd64/crtn.S
	$(CC) -c amd64/crtn.S -o crtn.o $(CFLAGS)
sysident.o: common/sysident.S
	$(CC) -c common/sysident.S -o sysident.o $(CFLAGS)
clean:
	rm -rf crt0.o crtbegin.o crtend.o crti.o crtn.o sysident.o
