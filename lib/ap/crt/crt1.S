
.text

// %rdi and %rsi are set up as argc, argv for main.
// %rdx points to top of stack
.globl	_start
_start:

	call	_envsetup
	movq	0(%rsp), %rdi
	leaq	8(%rsp), %rsi
	movq	environ, %rbx
	call	main
	call	exit
	ret
