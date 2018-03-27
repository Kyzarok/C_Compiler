	.globl	f
	.ent	f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
li $2, 5
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	f
