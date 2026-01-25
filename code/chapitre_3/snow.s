	.file	"snow.c"
	.text
	.globl	dwarf
	.type	dwarf, @function
dwarf:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	dwarf, .-dwarf
	.globl	snowWhite
	.type	snowWhite, @function
snowWhite:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$24, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	%r8d, -20(%rbp)
	movl	%r9d, -24(%rbp)
	movl	-24(%rbp), %r9d
	movl	-20(%rbp), %r8d
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	16(%rbp), %edi
	pushq	%rdi
	movl	%eax, %edi
	call	dwarf
	addq	$8, %rsp
	movl	-24(%rbp), %r9d
	movl	-20(%rbp), %r8d
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	16(%rbp), %edi
	pushq	%rdi
	movl	%eax, %edi
	call	dwarf
	addq	$8, %rsp
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	snowWhite, .-snowWhite
	.ident	"GCC: (Debian 14.3.0-5) 14.3.0"
	.section	.note.GNU-stack,"",@progbits
