	.section	__TEXT,__text,regular,pure_instructions
	.globl	_foo
	.align	4, 0x90
_foo:                                   ## @foo
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	imull	-4(%rbp), %edi
	movl	%edi, -8(%rbp)
	movl	-8(%rbp), %edi
	addl	$2, %edi
	movl	%edi, %eax
	popq	%rbp
	ret
	.cfi_endproc


.subsections_via_symbols
