	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"Program start"
.LC1:
	.string	"10 + 20 = %d\n"
.LC2:
	.string	"calc_add failed"
.LC3:
	.string	"50 - 15 = %d\n"
.LC4:
	.string	"calc_sub failed"
.LC5:
	.string	"Program end"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	log_info@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	movl	$20, %esi
	movl	$10, %edi
	call	calc_add@PLT
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jne	.L2
	movl	-16(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	log_error@PLT
.L3:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	movl	$15, %esi
	movl	$50, %edi
	call	calc_sub@PLT
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jne	.L4
	movl	-16(%rbp), %eax
	leaq	.LC3(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L5
.L4:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	log_error@PLT
.L5:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	log_info@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
