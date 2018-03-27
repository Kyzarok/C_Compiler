	.globl	f
	.ent	f
f:
addiu $sp,$sp,-12
sw $fp,8($sp)
move	$fp,$sp
li $8, 1
li $9, 1
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

sw $8,4($fp)
$cond2:
lw $8, 4($fp)
li $9, 0
sub $8,$8,$9
bne	$0, $8, $body2
nop
b $end2
nop
$body2:
lw $9, 4($fp)
li $10, -1
addu $9,$9,$10
sw $9,4($fp)
b $cond2
nop
$end2:
lw $2, 4($fp)
j $returnLable0
nop

b	$if_f1
nop

$if_f1:
li $2, 19
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,8($sp)
addiu $sp,$sp,12
j $31
nop
	.end	f
