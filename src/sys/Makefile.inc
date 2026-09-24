.PATH: ${.CURDIR}/sys

SRCS+=__sysctl.c _exit.c access.c brk.c chdir.c chown.c chroot.c close.c dup.c dup2.c execve.c fchdir.c \
      fchown.c fork.c fstat.c fstatat.c fsync.c ftruncate.c getdents.c getegid.c geteuid.c getgid.c \
      getgroups.c getpgid.c getpid.c getppid.c getrlimit.c getuid.c ioctl.c kill.c lchown.c link.c \
      lseek.c lstat.c madvise.c mkdir.c mmap.c mprotect.c mremap.c munmap.c nanosleep.c open.c pause.c \
      pipe.c pread.c pwrite.c read.c readlink.c readv.c rmdir.c sbrk.c setpgid.c setregid.c setreuid.c \
      stat.c statvfs.c sync.c truncate.c unlink.c utimensat.c waitpid.c write.c writev.c umask.c fcntl.c \
      getrandom.c __sigaction_siginfo.c gettimeofday.c _sys_sched_yield.c utrace.c chmod.c fchmod.c \
      fchmodat.c lchmod.c clock_gettime.c clock_nanosleep.c __getcwd.c sigsuspend.c getlogin.c setlogin.c \
      rename.c
