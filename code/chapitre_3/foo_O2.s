	.file	"foo_sec.c"
	.text
	.p2align 4
	.globl	foo
	.type	foo, @function
foo:
.LFB11:
	.cfi_startproc
	ret
	.cfi_endproc
.LFE11:
	.size	foo, .-foo
	.ident	"GCC: (Debian 14.3.0-5) 14.3.0"
	.section	.note.GNU-stack,"",@progbits
