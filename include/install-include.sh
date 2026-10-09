#!/bin/sh
set -e

PREFIX="${PREFIX:-usr}"
INCLUDEDIR="$PREFIX/include"

includes="assert.h dirent.h float.h grp.h link.h link_elf.h memory.h netgroup.h regex.h sha2.h stdint.h time.h \
      utime.h atomic.h dlfcn.h fmtmsg.h hesiod.h locale.h mntent.h nlist.h resolv.h sha3.h stdio.h ttyent.h \
      utmp.h bitstring.h elf.h fnmatch.h iconv.h lwp.h monetary.h nl_types.h res_update.h signal.h stdlib.h \
      tzfile.h utmpx.h bm.h endian.h fstab.h ifaddrs.h malloc.h mpool.h nsswitch.h rmd160.h spawn.h string.h \
      uchar.h uuid.h cdbr.h err.h fts.h inttypes.h math.h mqueue.h paths.h sched.h stdalign.h stringlist.h  \
      ucontext.h vis.h cdbw.h errno.h ftw.h langinfo.h md2.h ndbm.h poll.h search.h stdarg.h strings.h \
      ulimit.h wchar.h ctype.h fcntl.h getopt.h libgen.h md4.h netconfig.h pwd.h setjmp.h stdbool.h syslog.h \
      unistd.h wctype.h db.h fenv.h glob.h limits.h md5.h netdb.h randomid.h sha1.h stddef.h termios.h util.h \
      wordexp.h"
sys_includes="ansi.h atomic.h bitops.h bswap.h callout.h cdbr.h cdefs_elf.h cdefs.h common_ansi.h \
              common_int_const.h common_int_fmtio.h common_int_limits.h common_int_mwgwtypes.h \
              common_int_types.h ctype_bits.h ctype_inline.h dirent.h dkio.h elfdefinitions.h endian.h \
              errno.h eventfd.h event.h exec_elf.h exec.h fcntl.h fd_set.h featuretest.h file.h \
              filio.h float_ieee754.h fstypes.h gmon.h hash.h hook.h idtype.h ieee754.h inttypes.h \
              ioccom.h ioctl.h ipc.h ksyms.h ktrace.h localedef.h lock.h lwp.h md4.h md5.h mman.h \
              mmap.h mntent.h mount.h mqueue.h msg.h mutex.h null.h param.h poll.h proc.h psref.h \
              ptree.h queue.h random.h rbtree.h resource.h rmd160.h sched.h select.h sem.h sha1.h \
              sha2.h sha3.h shm.h siginfo.h signal.h sigtypes.h socket.h sockio.h spawn.h stat.h \
              statvfs.h stdalign.h stdarg.h stdbool.h stddef.h stdint.h syscall.h sysctl.h \
              syslimits.h syslog.h termios.h time.h times.h timespec.h timex.h tls.h ttycom.h \
              ttydefaults.h types.h ucontext.h ucred.h uio.h un.h unistd.h utsname.h uuid.h vmmeter.h \
              wait.h"

main()
{
	mkdir -p "$DESTDIR/$INCLUDEDIR"

	for i in $includes; do
		install -v -m 644 -o root -g root "$i" "$DESTDIR/$INCLUDEDIR/$i"
	done

	for i in $sys_includes; do
		install -v -m 644 -o root -g root "$i" "$DESTDIR/$INCLUDEDIR/$i"
	done
}

main
