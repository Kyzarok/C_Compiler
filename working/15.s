.globl x
.data 
.align 2
x:
.word 3
.text
.align 2
	.globl	f
	.ent	f
f:
addiu $sp,$sp,-12
sw $fp,8($sp)
move	$fp,$sp
li $8, 2

sw $8,4($fp)
lw $2, 4($fp)
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,8($sp)
addiu $sp,$sp,12
j $31
nop
	.end	f
