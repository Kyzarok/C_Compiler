	.globl	f
	.ent	f
f:
addiu $sp,$sp,-16
sw $fp,12($sp)
move	$fp,$sp
li $8, 2

sw $8,4($fp)
lw $8, 4($fp)
li $9, 2
slt	$10, $8, $9
slt	$9, $9, $8
xor $8, $9, $10
xori $8, $8, 1
bne	$0, $8, $if_s1
nop
b	$if_f1
nop

$if_s1:
li $8, 3

sw $8,8($fp)
b	$if_f1
nop

$if_f1:
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
