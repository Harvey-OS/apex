.globl _PIPE
_PIPE:
pipe:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $4117,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
