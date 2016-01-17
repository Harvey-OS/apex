.globl _FSTAT
_FSTAT:
fstat:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $4139,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
