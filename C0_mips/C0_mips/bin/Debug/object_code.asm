.data
con_int1: .word 1
con_int2: .word -1
con_int3: .word 34
con_int4: .word 10
con_ch4: .word 65
index: .word 0
var_arr: .word 0:10
bigger_input: .word 0
var_arr_ch: .word 0:10
.text
addi $fp,$sp,0
j main
find_bigger:
sw $ra,4($sp)
addi $sp,$sp,-20
lw $t0,-0($fp)
addi $s1,$t0,0
lw $t0,-4($fp)
addi $s0,$t0,0
sub $t2,$s1,$s0
bltz $t2,label0
addi $v0,$s1,0
addi $sp,$fp,76
lw $fp,-68($sp)
lw $ra,-72($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
lw $t4,-32($sp)
lw $t5,-36($sp)
lw $t6,-40($sp)
lw $t7,-44($sp)
lw $t8,-48($sp)
lw $t9,-52($sp)
lw $a1,-56($sp)
lw $a2,-60($sp)
lw $a3,-64($sp)
jr $ra
label0:
addi $t0,$zero,1
addi $t1,$fp,-8
sw $t0,0($t1)
addi $t1,$zero,1
add $t3,$s1,$t1
sw $t3,-12($fp)
sw $s0,0($sp)
sw $s1,-4($sp)
sw $s2,-8($sp)
sw $s3,-12($sp)
sw $s4,-16($sp)
sw $s5,-20($sp)
sw $s6,-24($sp)
sw $s7,-28($sp)
sw $t4,-32($sp)
sw $t5,-36($sp)
sw $t6,-40($sp)
sw $t7,-44($sp)
sw $t8,-48($sp)
sw $t9,-52($sp)
sw $a1,-56($sp)
sw $a2,-60($sp)
sw $a3,-64($sp)
sw $fp,-68($sp)
sw $fp,-68($sp)
addi $sp,$sp,-76
lw $t0,-12($fp)
sw $t0,0($sp)
sw $s0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $t0,$fp,-16
sw $v0,0($t0)
lw $t0,-16($fp)
addi $v0,$t0,0
addi $sp,$fp,76
lw $fp,-68($sp)
lw $ra,-72($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
lw $t4,-32($sp)
lw $t5,-36($sp)
lw $t6,-40($sp)
lw $t7,-44($sp)
lw $t8,-48($sp)
lw $t9,-52($sp)
lw $a1,-56($sp)
lw $a2,-60($sp)
lw $a3,-64($sp)
jr $ra
addi $sp,$fp,76
lw $fp,-68($sp)
lw $ra,-72($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
lw $t4,-32($sp)
lw $t5,-36($sp)
lw $t6,-40($sp)
lw $t7,-44($sp)
lw $t8,-48($sp)
lw $t9,-52($sp)
lw $a1,-56($sp)
lw $a2,-60($sp)
lw $a3,-64($sp)
jr $ra
print_bigger:
sw $ra,4($sp)
addi $sp,$sp,0
.data
string0: .asciiz "The bigger number is "
.text
la $a0,string0
addi $v0,$zero,4
syscall
la $t0,bigger_input
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $sp,$fp,76
lw $fp,-68($sp)
lw $ra,-72($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
lw $t4,-32($sp)
lw $t5,-36($sp)
lw $t6,-40($sp)
lw $t7,-44($sp)
lw $t8,-48($sp)
lw $t9,-52($sp)
lw $a1,-56($sp)
lw $a2,-60($sp)
lw $a3,-64($sp)
jr $ra
relation:
sw $ra,4($sp)
addi $sp,$sp,-20
lw $t0,-0($fp)
addi $s2,$t0,0
lw $t0,-4($fp)
addi $s1,$t0,0
addi $s4,$zero,0
addi $t0,$zero,0
sw $t0,-8($fp)
addi $s3,$zero,1
addi $t0,$zero,1
sw $t0,-12($fp)
sub $t2,$s2,$s1
bgtz $t2,label1
addi $s0,$s4,0
.data
string1: .asciiz "input3 is smaller OR equal than input4"
.text
la $a0,string1
addi $v0,$zero,4
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label1:
sub $t2,$s2,$s1
bltz $t2,label2
addi $s0,$s3,0
.data
string2: .asciiz "input3 is bigger OR equal than input4"
.text
la $a0,string2
addi $v0,$zero,4
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label2:
beq $s2,$s1,label3
label3:
bne $s2,$s1,label4
.data
string3: .asciiz "input3 is equal to input4"
.text
la $a0,string3
addi $v0,$zero,4
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label4:
addi $t1,$zero,0
bne $s0,$t1,label6
sub $t2,$s2,$s1
bgez $t2,label7
.data
string4: .asciiz "input3 is smaller than input4"
.text
la $a0,string4
addi $v0,$zero,4
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label7:
j label5
label6:
addi $t1,$zero,1
bne $s0,$t1,label8
sub $t2,$s2,$s1
blez $t2,label9
.data
string5: .asciiz "input3 is bigger than input4"
.text
la $a0,string5
addi $v0,$zero,4
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label9:
j label5
label8:
label5:
addi $sp,$fp,76
lw $fp,-68($sp)
lw $ra,-72($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
lw $t4,-32($sp)
lw $t5,-36($sp)
lw $t6,-40($sp)
lw $t7,-44($sp)
lw $t8,-48($sp)
lw $t9,-52($sp)
lw $a1,-56($sp)
lw $a2,-60($sp)
lw $a3,-64($sp)
jr $ra
main:
addi $sp,$sp,-104
addi $v0,$zero,5
syscall
sw $v0,-0($fp)
addi $v0,$zero,5
syscall
sw $v0,-4($fp)
addi $v0,$zero,5
syscall
sw $v0,-8($fp)
addi $v0,$zero,5
syscall
sw $v0,-12($fp)
addi $t0,$zero,0
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$zero,0
la $t1,index
sw $t0,0($t1)
sw $s0,0($sp)
sw $s1,-4($sp)
sw $s2,-8($sp)
sw $s3,-12($sp)
sw $s4,-16($sp)
sw $s5,-20($sp)
sw $s6,-24($sp)
sw $s7,-28($sp)
sw $t4,-32($sp)
sw $t5,-36($sp)
sw $t6,-40($sp)
sw $t7,-44($sp)
sw $t8,-48($sp)
sw $t9,-52($sp)
sw $a1,-56($sp)
sw $a2,-60($sp)
sw $a3,-64($sp)
sw $fp,-68($sp)
sw $fp,-68($sp)
addi $sp,$sp,-76
lw $t0,-0($fp)
sw $t0,0($sp)
lw $t0,-4($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $t0,$fp,-20
sw $v0,0($t0)
lw $t0,-20($fp)
la $t1,bigger_input
sw $t0,0($t1)
sw $s0,0($sp)
sw $s1,-4($sp)
sw $s2,-8($sp)
sw $s3,-12($sp)
sw $s4,-16($sp)
sw $s5,-20($sp)
sw $s6,-24($sp)
sw $s7,-28($sp)
sw $t4,-32($sp)
sw $t5,-36($sp)
sw $t6,-40($sp)
sw $t7,-44($sp)
sw $t8,-48($sp)
sw $t9,-52($sp)
sw $a1,-56($sp)
sw $a2,-60($sp)
sw $a3,-64($sp)
sw $fp,-68($sp)
sw $fp,-68($sp)
addi $sp,$sp,-76
addi $fp,$sp,0
jal print_bigger
sw $s0,0($sp)
sw $s1,-4($sp)
sw $s2,-8($sp)
sw $s3,-12($sp)
sw $s4,-16($sp)
sw $s5,-20($sp)
sw $s6,-24($sp)
sw $s7,-28($sp)
sw $t4,-32($sp)
sw $t5,-36($sp)
sw $t6,-40($sp)
sw $t7,-44($sp)
sw $t8,-48($sp)
sw $t9,-52($sp)
sw $a1,-56($sp)
sw $a2,-60($sp)
sw $a3,-64($sp)
sw $fp,-68($sp)
sw $fp,-68($sp)
addi $sp,$sp,-76
lw $t0,-8($fp)
sw $t0,0($sp)
lw $t0,-12($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal relation
addi $t0,$zero,-1
addi $t1,$fp,-24
sw $t0,0($t1)
lw $t0,-8($fp)
addi $t1,$zero,-1
div $t0,$t1
mflo $t3
sw $t3,-28($fp)
addi $t0,$zero,97
addi $t1,$fp,-32
sw $t0,0($t1)
lw $t0,-12($fp)
lw $t1,-28($fp)
mult $t0,$t1
mflo $t3
sw $t3,-36($fp)
lw $t0,-36($fp)
addi $t1,$zero,97
mult $t0,$t1
mflo $t3
sw $t3,-40($fp)
addi $t0,$zero,0
lw $t1,-8($fp)
sub $t3,$t0,$t1
sw $t3,-44($fp)
lw $t0,-44($fp)
lw $t1,-40($fp)
add $t3,$t0,$t1
sw $t3,-48($fp)
sw $s0,0($sp)
sw $s1,-4($sp)
sw $s2,-8($sp)
sw $s3,-12($sp)
sw $s4,-16($sp)
sw $s5,-20($sp)
sw $s6,-24($sp)
sw $s7,-28($sp)
sw $t4,-32($sp)
sw $t5,-36($sp)
sw $t6,-40($sp)
sw $t7,-44($sp)
sw $t8,-48($sp)
sw $t9,-52($sp)
sw $a1,-56($sp)
sw $a2,-60($sp)
sw $a3,-64($sp)
sw $fp,-68($sp)
sw $fp,-68($sp)
addi $sp,$sp,-76
lw $t0,-8($fp)
sw $t0,0($sp)
lw $t0,-12($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $t0,$fp,-52
sw $v0,0($t0)
addi $t0,$zero,7
addi $t1,$fp,-56
sw $t0,0($t1)
lw $t0,-52($fp)
addi $t1,$zero,7
mult $t0,$t1
mflo $t3
sw $t3,-60($fp)
lw $t0,-48($fp)
lw $t1,-60($fp)
add $t3,$t0,$t1
sw $t3,-64($fp)
lw $t0,-64($fp)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label10:
addi $t0,$zero,2
addi $t1,$fp,-68
sw $t0,0($t1)
addi $t0,$zero,1
addi $t1,$fp,-72
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,2
mult $t0,$t1
mflo $t3
sw $t3,-76($fp)
lw $t0,-76($fp)
addi $t1,$zero,1
add $t3,$t0,$t1
sw $t3,-80($fp)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr
add $t0,$t1,$t0
lw $t1,,-80($fp)
sw $t1,0($t0)
la $t0,con_ch4
lw $t0,0($t0)
la $t1,index
lw $t1,0($t1)
add $t3,$t0,$t1
sw $t3,-84($fp)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr_ch
add $t0,$t1,$t0
lw $t1,,-84($fp)
sw $t1,0($t0)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr
add $t0,$t1,$t0
lw $t0,0($t0)
sw $t0,-88($fp)
lw $t0,-88($fp)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr_ch
add $t0,$t1,$t0
lw $t0,0($t0)
sw $t0,-92($fp)
lw $t0,-92($fp)
addi $a0,$t0,0
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $t0,$zero,1
addi $t1,$fp,-96
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,1
add $t3,$t0,$t1
sw $t3,-100($fp)
lw $t0,-100($fp)
la $t1,index
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
la $t1,con_int4
lw $t1,0($t1)
sub $t2,$t0,$t1
bltz $t2,label10
EXIT:
