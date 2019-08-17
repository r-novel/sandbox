	.file	"sse-01.c"
	.text
	.globl	a
	.data
	.align 16
	.type	a, @object
	.size	a, 16
a:
	.long	1133903872
	.long	1082130432
	.long	1082130432
	.long	1094713344
	.globl	b
	.align 16
	.type	b, @object
	.size	b, 16
b:
	.long	1069547520
	.long	1075838976
	.long	1080033280
	.long	1083179008
	.section	.rodata
.LC0:
	.string	"A: %f %f %f %f\n"
.LC1:
	.string	"B: %f %f %f %f\n"
.LC2:
	.string	"\nR: %f %f %f %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movss	12+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm3
	movss	8+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC0(%rip), %rdi
	movl	$4, %eax
	call	printf@PLT
	movss	12+b(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm3
	movss	8+b(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4+b(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	b(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$4, %eax
	call	printf@PLT
#APP
# 35 "sse-01.c" 1
	movups a(%rip), %xmm0
	movups b(%rip), %xmm1
	mulps %xmm1, %xmm0
	movups %xmm0, a(%rip)
	
# 0 "" 2
#NO_APP
	movss	12+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm3
	movss	8+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4+a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$4, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
