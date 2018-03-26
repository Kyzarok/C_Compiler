	.globl	f
	.ent	f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
li $2, 3
li $3, 3
slt	$4, $2, $3
slt	$3, $3, $2
xor $2, $3, $4
xori $2, $2, 1
BNE	$0, $2, $if_s0
NOP
b	$if_f0
NOP

$if_s0:
li $2, 12

b	$if_f0
NOP

$if_f0:
li $2, 2

move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	f
