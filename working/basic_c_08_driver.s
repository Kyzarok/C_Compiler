	.file	1 "basic_c_08_driver.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,40,$31		# vars= 0, regs= 3/0, args= 16, gp= 8
	.mask	0xc0010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	sw	$16,28($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	lw	$2,%call16(f)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,f
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$16,$2
	lw	$2,%call16(g)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,g
1:	jalr	$25
	nop

	lw	$28,16($fp)
	addu	$2,$16,$2
	xori	$2,$2,0x7
	sltu	$2,$0,$2
	andi	$2,$2,0x00ff
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	lw	$16,28($sp)
	addiu	$sp,$sp,40
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
