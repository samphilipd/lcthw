	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$128, %rsp
	leaq	L_.str(%rip), %rax
	movl	$4, %ecx
	movl	%ecx, %edx
	movq	___stack_chk_guard@GOTPCREL(%rip), %r8
	movq	(%r8), %r8
	movq	%r8, -8(%rbp)
	movl	$0, -52(%rbp)
	movl	%edi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	l_main.areas(%rip), %rsi
	movq	%rsi, -32(%rbp)
	movq	l_main.areas+8(%rip), %rsi
	movq	%rsi, -24(%rbp)
	movl	l_main.areas+16(%rip), %ecx
	movl	%ecx, -16(%rbp)
	movl	L_main.name(%rip), %ecx
	movl	%ecx, -68(%rbp)
	movq	L_main.full_name(%rip), %rsi
	movq	%rsi, -46(%rbp)
	movl	L_main.full_name+8(%rip), %ecx
	movl	%ecx, -38(%rbp)
	movw	L_main.full_name+12(%rip), %r9w
	movw	%r9w, -34(%rbp)
	movq	%rax, %rdi
	movq	%rdx, %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str1(%rip), %rdi
	movl	$20, %ecx
	movl	%ecx, %esi
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str2(%rip), %rdi
	movl	$5, %ecx
	movl	%ecx, %esi
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str3(%rip), %rdi
	movl	-32(%rbp), %esi
	movl	-28(%rbp), %edx
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str4(%rip), %rdi
	movl	$1, %ecx
	movl	%ecx, %esi
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str5(%rip), %rdi
	movl	$4, %ecx
	movl	%ecx, %esi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str6(%rip), %rdi
	movl	$4, %ecx
	movl	%ecx, %esi
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str7(%rip), %rdi
	movl	$14, %ecx
	movl	%ecx, %esi
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str6(%rip), %rdi
	movl	$14, %ecx
	movl	%ecx, %esi
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str8(%rip), %rdi
	leaq	-46(%rbp), %rdx
	leaq	-68(%rbp), %rsi
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str9(%rip), %rdi
	leaq	-71(%rbp), %rsi
	movw	l_main.name_bad(%rip), %r9w
	movw	%r9w, -71(%rbp)
	movb	l_main.name_bad+2(%rip), %r10b
	movb	%r10b, -69(%rbp)
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str10(%rip), %rdi
	movsbl	-58(%rbp), %esi
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str10(%rip), %rdi
	movl	3968(%rbp), %esi
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdx
	movq	(%rdx), %rdx
	cmpq	-8(%rbp), %rdx
	movl	%eax, -124(%rbp)        ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	xorl	%eax, %eax
	addq	$128, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__const
	.align	4                       ## @main.areas
l_main.areas:
	.long	10                      ## 0xa
	.long	12                      ## 0xc
	.long	13                      ## 0xd
	.long	14                      ## 0xe
	.long	20                      ## 0x14

	.section	__TEXT,__cstring,cstring_literals
L_main.name:                            ## @main.name
	.asciz	"Sam"

L_main.full_name:                       ## @main.full_name
	.asciz	"Sam P. Davies"

L_.str:                                 ## @.str
	.asciz	"The size of an int: %ld\n"

L_.str1:                                ## @.str1
	.asciz	"The size of areas (int[]): %ld\n"

L_.str2:                                ## @.str2
	.asciz	"The number of ints in areas: %ld\n"

L_.str3:                                ## @.str3
	.asciz	"The first area is %d, the 2nd %d.\n"

L_.str4:                                ## @.str4
	.asciz	"The size of a char: %ld\n"

L_.str5:                                ## @.str5
	.asciz	"The size of name (char[]): %ld\n"

L_.str6:                                ## @.str6
	.asciz	"The number of chars: %ld\n"

L_.str7:                                ## @.str7
	.asciz	"The size of full_name (char[]): %ld\n"

L_.str8:                                ## @.str8
	.asciz	"name=\"%s\" and full_name=\"%s\"\n"

	.section	__TEXT,__const
l_main.name_bad:                        ## @main.name_bad
	.ascii	"Sam"

	.section	__TEXT,__cstring,cstring_literals
L_.str9:                                ## @.str9
	.asciz	"name without nul terminator: %s\n"

L_.str10:                               ## @.str10
	.asciz	"out of bounds access: %c\n"


.subsections_via_symbols
