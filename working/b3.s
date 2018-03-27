	.globl	f
	.ent	f
f:
addiu $sp,$sp,-16
sw $fp,12($sp)
move	$fp,$sp
li $8, 7

sw $8,4($fp)
li $8, -2

sw $8,8($fp)
lw $8, 4($fp)
li $9, 3
sub $8,$8,$9
sw $8,4($fp)
lw $8, 4($fp)
lw $9, 8($fp)
addu $8,$8,$9
sw $8,4($fp)
lw $2, 4($fp)
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,12($sp)
addiu $sp,$sp,16
j $31
nop
	.end	f
