.globl _OPEN
_OPEN:
open:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $2,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
