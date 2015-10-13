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
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$2, -8(%rbp)
	je	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$1, -4(%rbp)
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB0_17
LBB0_2:
	movl	$0, -20(%rbp)
	movl	$0, -20(%rbp)
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movslq	-20(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	8(%rcx), %rcx
	movsbl	(%rcx,%rax), %edx
	cmpl	$0, %edx
	je	LBB0_16
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=1
	movslq	-20(%rbp), %rax
	movq	-16(%rbp), %rcx
	movq	8(%rcx), %rcx
	movb	(%rcx,%rax), %dl
	movb	%dl, -21(%rbp)
	movsbl	-21(%rbp), %esi
	movl	%esi, %edi
	subl	$96, %edi
	movl	%esi, -32(%rbp)         ## 4-byte Spill
	movl	%edi, -36(%rbp)         ## 4-byte Spill
	jg	LBB0_19
	jmp	LBB0_18
LBB0_18:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$84, %eax
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	jg	LBB0_28
	jmp	LBB0_27
LBB0_27:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$72, %eax
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	jg	LBB0_31
	jmp	LBB0_30
LBB0_30:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$65, %eax
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	je	LBB0_5
	jmp	LBB0_33
LBB0_33:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$69, %eax
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	je	LBB0_6
	jmp	LBB0_13
LBB0_31:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$73, %eax
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	je	LBB0_7
	jmp	LBB0_32
LBB0_32:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$79, %eax
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	je	LBB0_8
	jmp	LBB0_13
LBB0_28:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$85, %eax
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	je	LBB0_9
	jmp	LBB0_29
LBB0_29:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$89, %eax
	movl	%eax, -68(%rbp)         ## 4-byte Spill
	je	LBB0_10
	jmp	LBB0_13
LBB0_19:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$116, %eax
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	jg	LBB0_21
	jmp	LBB0_20
LBB0_20:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$104, %eax
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	jg	LBB0_24
	jmp	LBB0_23
LBB0_23:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$97, %eax
	movl	%eax, -80(%rbp)         ## 4-byte Spill
	je	LBB0_5
	jmp	LBB0_26
LBB0_26:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$101, %eax
	movl	%eax, -84(%rbp)         ## 4-byte Spill
	je	LBB0_6
	jmp	LBB0_13
LBB0_24:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$105, %eax
	movl	%eax, -88(%rbp)         ## 4-byte Spill
	je	LBB0_7
	jmp	LBB0_25
LBB0_25:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$111, %eax
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	je	LBB0_8
	jmp	LBB0_13
LBB0_21:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$117, %eax
	movl	%eax, -96(%rbp)         ## 4-byte Spill
	je	LBB0_9
	jmp	LBB0_22
LBB0_22:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-32(%rbp), %eax         ## 4-byte Reload
	subl	$121, %eax
	movl	%eax, -100(%rbp)        ## 4-byte Spill
	je	LBB0_10
	jmp	LBB0_13
LBB0_5:                                 ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str1(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -104(%rbp)        ## 4-byte Spill
	jmp	LBB0_14
LBB0_6:                                 ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str2(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -108(%rbp)        ## 4-byte Spill
	jmp	LBB0_14
LBB0_7:                                 ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str3(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -112(%rbp)        ## 4-byte Spill
	jmp	LBB0_14
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str4(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -116(%rbp)        ## 4-byte Spill
	jmp	LBB0_14
LBB0_9:                                 ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str5(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -120(%rbp)        ## 4-byte Spill
	jmp	LBB0_14
LBB0_10:                                ##   in Loop: Header=BB0_3 Depth=1
	cmpl	$2, -20(%rbp)
	jle	LBB0_12
## BB#11:                               ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str6(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -124(%rbp)        ## 4-byte Spill
LBB0_12:                                ##   in Loop: Header=BB0_3 Depth=1
	jmp	LBB0_14
LBB0_13:                                ##   in Loop: Header=BB0_3 Depth=1
	leaq	L_.str7(%rip), %rdi
	movl	-20(%rbp), %esi
	movsbl	-21(%rbp), %edx
	movb	$0, %al
	callq	_printf
	movl	%eax, -128(%rbp)        ## 4-byte Spill
LBB0_14:                                ##   in Loop: Header=BB0_3 Depth=1
	jmp	LBB0_15
LBB0_15:                                ##   in Loop: Header=BB0_3 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB0_3
LBB0_16:
	movl	$0, -4(%rbp)
LBB0_17:
	movl	-4(%rbp), %eax
	addq	$128, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"ERROR: You need one argument.\n"

L_.str1:                                ## @.str1
	.asciz	"%d: 'A'\n"

L_.str2:                                ## @.str2
	.asciz	"%d: 'E'\n"

L_.str3:                                ## @.str3
	.asciz	"%d: 'I'\n"

L_.str4:                                ## @.str4
	.asciz	"%d: 'O'\n"

L_.str5:                                ## @.str5
	.asciz	"%d: 'U'\n"

L_.str6:                                ## @.str6
	.asciz	"%d: 'Y'\n"

L_.str7:                                ## @.str7
	.asciz	"%d: %c is not a vowel\n"


.subsections_via_symbols
