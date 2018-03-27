	.globl	f
	.ent	f
f:
addiu $sp,$sp,-16
sw $fp,12($sp)
move	$fp,$sp
li $8, 2
li $9, 3
MULT	$8, $9
NOP
MFLO	$8
NOP
NOP
li $9, 5
addu $8,$8,$9

sw $8,4($fp)
li $8, 5
li $9, 3
or $8,$8,$9

sw $8,8($fp)
lw $8, 4($fp)
lw $9, 8($fp)
MULT	$8, $9
NOP
MFLO	$8
NOP
NOP
li $9, 3
addu $8,$8,$9
sw $8,4($fp)
lw $8, 4($fp)
li $9, 4
DIV	$8, $9
NOP
MFLO	$8
NOP
NOP
sw $8,8($fp)
li $2, 2
lw $8, 4($fp)
lw $9, 8($fp)
sub $8,$8,$9
MULT	$2, $8
NOP
MFLO	$2
NOP
NOP
j $returnLable0
nop

$returnLable0:
move $sp,$fp
lw $fp,12($sp)
addiu $sp,$sp,16
j $31
nop
	.end	f
