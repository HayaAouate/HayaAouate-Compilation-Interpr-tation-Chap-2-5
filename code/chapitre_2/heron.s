	.text
	.globl heron

heron:
	pushl %ebx
	movl 8(%esp),%eax      # load a
	movl 12(%esp),%ebx     # load b  
	movl 16(%esp),%ecx     # load c
	movl %eax,%edx         # copy a
	addl %ebx,%eax         # s = (a+b+c)/2
	addl %ecx,%eax
	sarl $1,%eax
	subl %eax,%ebx         # (s-b)
	subl %eax,%ecx         # (s-c)
	subl %eax,%edx         # (s-a)
	imull %ebx,%eax        # area² = s(s-a)(s-b)(s-c)
	imull %ecx,%eax
	imull %edx,%eax
	negl %eax              # negate result
	popl %ebx
	ret
