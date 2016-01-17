.globl _CLOSE
_CLOSE:
close:
	movq %rcx, %r10 /* rcx gets smashed by systenter. Use r10.*/
	movq $3,%rax  /* Put the system call into rax, just like linux. */
	syscall
	ret
