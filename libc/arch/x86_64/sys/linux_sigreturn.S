#include <sys/syscall.h>
#include <machine/asm.h>

ENTRY(linux_sigreturn)
	movq	$SYS_rt_sigreturn, %rax
	syscall

	movq	$-1, %rdi
	movq	$SYS_exit, %rax
	syscall
END(linux_sigreturn)
