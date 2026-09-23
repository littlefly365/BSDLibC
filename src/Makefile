LIB=c

CPPFLAGS+=-nostdinc -ffreestanding -fPIC -fno-stack-protector
CPPFLAGS+=-D_LIBC -D_REENTRANT -D__DBINTERFACE_PRIVATE -DNLS -D__ELF__ -D_LIBC_INTERNAL
CPPFLAGS+=-I${.CURDIR} -I${.CURDIR}/include -I${.CURDIR}/internal -I${.CURDIR}/citrus \
          -I${.CURDIR}/csu -I${.CURDIR}/stdlib -I${.CURDIR}/locale -I${.CURDIR}/ld.elf_so \
          -I${.CURDIR}/gen
LDFLAGS+=-nostdlib -ffreestanding

.include "${.CURDIR}/arch/Makefile.inc"
.include "${.CURDIR}/atomic/Makefile.inc"
.include "${.CURDIR}/citrus/Makefile.inc"
.include "${.CURDIR}/compat/Makefile.inc"
.include "${.CURDIR}/cdb/Makefile.inc"
.include "${.CURDIR}/db/Makefile.inc"
.include "${.CURDIR}/dlfcn/Makefile.inc"
.include "${.CURDIR}/gdtoa/Makefile.inc"
.include "${.CURDIR}/gen/Makefile.inc"
.include "${.CURDIR}/hash/Makefile.inc"
.include "${.CURDIR}/iconv/Makefile.inc"
.include "${.CURDIR}/locale/Makefile.inc"
.include "${.CURDIR}/math/Makefile.inc"
.include "${.CURDIR}/md/Makefile.inc"
.include "${.CURDIR}/misc/Makefile.inc"
.include "${.CURDIR}/nls/Makefile.inc"
.include "${.CURDIR}/quad/Makefile.inc"
.include "${.CURDIR}/regex/Makefile.inc"
.include "${.CURDIR}/stdio/Makefile.inc"
.include "${.CURDIR}/stdlib/Makefile.inc"
.include "${.CURDIR}/string/Makefile.inc"
.include "${.CURDIR}/sys/Makefile.inc"
.include "${.CURDIR}/termios/Makefile.inc"
.include "${.CURDIR}/thread-sub/Makefile.inc"
.include "${.CURDIR}/time/Makefile.inc"
.include "${.CURDIR}/tls/Makefile.inc"
.include "${.CURDIR}/util/Makefile.inc"

.include <bsd.lib.mk>
