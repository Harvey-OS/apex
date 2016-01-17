.globl _WSTAT
_WSTAT:
wstat:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $4140,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
