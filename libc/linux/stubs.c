#warning "These functions are stubs and this is dangerous. You must implement them the fastest you can"

#include <sys/syscall.h>
#include <sys/cdefs.h>
#include <signal.h>
#include <unistd.h>

#ifdef __strong_alias
__strong_alias(__adjtime50, __stub_libc_err);
__strong_alias(__aio_suspend50, __stub_libc_err);
__strong_alias(getsockopt2, __stub_libc_err);
__strong_alias(__lfs_segwait50, __stub_libc_err);
__strong_alias(__mq_timedreceive50, __stub_libc_err);
__strong_alias(__mq_timedsend50, __stub_libc_err);
__strong_alias(__msgctl50, __stub_libc_err);
__strong_alias(__ntp_gettime50, __stub_libc_err);
__strong_alias(profil, __stub_libc_err);
__strong_alias(__pselect50, __stub_libc_err);
__strong_alias(recvmsg, __stub_libc_err);
__strong_alias(____semctl50, __stub_libc_err);
__strong_alias(__semctl50, __stub_libc_err);
__strong_alias(__settimeofday50, __stub_libc_err);
__strong_alias(__shmctl50, __stub_libc_err);
__strong_alias(__sigaltstack14, __stub_libc_err);
__strong_alias(____sigtimedwait50, __stub_libc_err);
__strong_alias(__sigtramp_siginfo_2, __stub_libc_err);
__strong_alias(timer_create, __stub_libc_err);
__strong_alias(timer_delete, __stub_libc_err);
__strong_alias(__timer_gettime50, __stub_libc_err);
__strong_alias(__timer_settime50, __stub_libc_err);
__strong_alias(wait6, __stub_libc_err);
#else
#define error "__strong_alias is not defined"
#endif

void
__stub_libc_err(void)
{
	const char msg[] = "Your program has called a function that is not implemented yet in BSDLibC\n";

	/* We try until the message was printed */
	while (syscall(SYS_write, 2, msg, sizeof(msg) -1) != sizeof(msg) - 1);

	/* First try to kill the current process with SIGSEGV */
	syscall(SYS_kill, syscall(SYS_getpid), SIGSEGV);

	/* If kill fails, we stop the entire process */
	syscall(SYS_exit_group, 127);

	/* Finally loop until the process finish */
	for (;;) {
		syscall(SYS_exit, 127);
	}
}
