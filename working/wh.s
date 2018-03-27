	.globl	f
	.ent	f
f:
addiu $sp,$sp,-12
sw $fp,8($sp)
move	$fp,$sp
li $8, 0

sw $8,4($fp)
$cond1:
lw $8, 4($fp)
li $9, 3
sub $8,$8,$9
bne	$0, $8, $body1
nop
b $end1
nop
$body1:
lw $9, 4($fp)
li $10, 1
addu $9,$9,$10
sw $9,4($fp)
b $cond1
nop
$end1:
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
