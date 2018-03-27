	.globl	f
	.ent	f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
li $2, 3
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	f
	.globl	g
	.ent	g
g:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
addiu $fp, $fp, -88
sw $8, 8($fp)
sw $9, 12($fp)
sw $10, 16($fp)
sw $11, 20($fp)
sw $12, 24($fp)
sw $13, 28($fp)
sw $14, 32($fp)
sw $15, 36($fp)
sw $16, 40($fp)
sw $17, 44($fp)
sw $18, 48($fp)
sw $19, 52($fp)
sw $20, 56($fp)
sw $21, 60($fp)
sw $22, 64($fp)
sw $23, 68($fp)
sw $24, 72($fp)
sw $25, 76($fp)
sw $31, 4($fp)
jal f
nop
lw $31, 4($fp)
lw $8, 8($fp)
lw $9, 12($fp)
lw $10, 16($fp)
lw $11, 20($fp)
lw $12, 24($fp)
lw $13, 28($fp)
lw $14, 32($fp)
lw $15, 36($fp)
lw $16, 40($fp)
lw $17, 44($fp)
lw $18, 48($fp)
lw $19, 52($fp)
lw $20, 56($fp)
lw $21, 60($fp)
lw $22, 64($fp)
lw $23, 68($fp)
lw $24, 72($fp)
lw $25, 76($fp)
move $2,$2
addiu $fp, $fp, 88
j $returnLable1
nop

$returnLable1:
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	g
