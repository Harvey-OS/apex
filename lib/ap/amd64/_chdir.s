.globl _CHDIR
_CHDIR:
chdir:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $4099,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret