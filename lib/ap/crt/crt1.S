
.text

// %rdi and %rsi are set up as argc, argv for main.
// %rdx points to top of stack
.globl	_start
_start:

	// 24 bytes room for environ
	subq	$24, %rsp

	// Prepare the environment
	call	_envsetup
	movq	%rax, 0(%rsp)
	movq	environ, %rax
	movq	%rax, 8(%rsp)

	// argc, argv
	movq	24(%rsp), %rdi
	leaq	32(%rsp), %rsi


	// Run constructors
	call	_init

	//  Give back 24 bytes of stack space
	addq	$24, %rsp

	call	main
	movq	%rax, %rdi
	call	exit
	ret
