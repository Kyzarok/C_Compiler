	.globl	f
	.ent	f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
li $8, 5
li $9, 5
sub $8,$8,$9
bne	$0, $8, $if_t1
nop
b	$else1
nop
$if_t1:
li $2, 5
j $returnLable0
nop

b	$if_fin1
nop
$else1:
li $2, 9
j $returnLable0
nop

b	$if_fin1
nop
$if_fin1:
li $2, 11
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	f
