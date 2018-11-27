/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

.globl sigsetjmp
sigsetjmp:
__sigsetjmp:
	andl	%esi, %esi			/* save mask */
	movq	%rsi, 64(%rdi)			/* (sigset_t*)set  */
	leaq	_psigblocked, %rsi		/* (sigset_t*)oset */
	movq	%rsi, 72(%rdi)
	movq    %rbx, 16(%rdi)
	movq    %r12, 24(%rdi)
	movq    %r13, 32(%rdi)
	movq    %r14, 40(%rdi)
	movq    %r15, 48(%rdi)
	movq    %rbp, 56(%rdi)
	popq    %rdx            /* return address */
	movq    %rsp, 64(%rdi)
	movq    %rdx, 72(%rdi)


	xorl    %eax, %eax      /* return 0 */
	jmp     *%rdx
