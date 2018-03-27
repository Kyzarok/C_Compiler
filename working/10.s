.globl x
.data 
.align 2
x:
.word 1
.text
.align 2
.globl y
.data 
.align 2
y:
.word 0
.text
.align 2
	.globl	f
	.ent	f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move	$fp,$sp
lui $9,%hi(y)
addiu $9, %lo(y)
li $8, 1
sw	$8, ($9)
lui $2, %hi(x)
lw $2, %lo(x)($2)
lui $8, %hi(y)
lw $8, %lo(y)($8)
addu $2,$2,$8
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
j $31
nop
	.end	f
