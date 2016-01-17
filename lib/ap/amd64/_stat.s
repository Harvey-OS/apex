.globl _STAT
_STAT:
stat:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $4138,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
