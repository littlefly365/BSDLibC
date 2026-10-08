.PATH: ${ARCHDIR}/sys ${.CURDIR}/sys

SRCS+=	eventfd_read.c eventfd_write.c fh.c fpathconf.c futimens.c getdents.c \
	getvfsstat.c ioctl.c issetugid.c kqueue.c login.c mmap.c posix_madvise.c \
	pathconf.c lwp.c minherit.c sbrk.c setexid.c __sigaction_siginfo.c \
	__sigaction_sigtramp.c  stat.c statvfs1.c statvfs.c syscall.c \
	syscalls.c __sysctl.c utimes.c utrace.c uuidgen.c vadvise.c
