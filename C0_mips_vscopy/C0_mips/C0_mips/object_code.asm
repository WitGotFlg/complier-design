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
addi $sp,$fp,40
lw $fp,-32($sp)
lw $ra,-36($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
jr $ra
label0:
addi $t0,$zero,1
addi $t1,$fp,-8
sw $t0,0($t1)
lw $t1,-8($fp)
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
lw $t0,-12($fp)
sw $t0,0($sp)
sw $s0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $t0,$fp,-16
sw $v0,0($t0)
lw $t0,-16($fp)
addi $v0,$t0,0
addi $sp,$fp,40
lw $fp,-32($sp)
lw $ra,-36($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
jr $ra
addi $sp,$fp,40
lw $fp,-32($sp)
lw $ra,-36($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
jr $ra
print_bigger:
sw $ra,4($sp)
addi $sp,$sp,0
addi $a0,$zero,84
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
la $t0,bigger_input
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $sp,$fp,40
lw $fp,-32($sp)
lw $ra,-36($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
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
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,51
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,79
addi $v0,$zero,11
syscall
addi $a0,$zero,82
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,113
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,52
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label1:
sub $t2,$s2,$s1
bltz $t2,label2
addi $s0,$s3,0
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,51
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,79
addi $v0,$zero,11
syscall
addi $a0,$zero,82
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,113
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,52
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label2:
beq $s2,$s1,label3
label3:
bne $s2,$s1,label4
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,51
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,113
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,111
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,52
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label4:
addi $t1,$zero,0
bne $s0,$t1,label6
sub $t2,$s2,$s1
bgez $t2,label7
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,51
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,52
addi $v0,$zero,11
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
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,51
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,112
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,52
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label9:
j label5
label8:
label5:
addi $sp,$fp,40
lw $fp,-32($sp)
lw $ra,-36($sp)
lw $s0,0($sp)
lw $s1,-4($sp)
lw $s2,-8($sp)
lw $s3,-12($sp)
lw $s4,-16($sp)
lw $s5,-20($sp)
lw $s6,-24($sp)
lw $s7,-28($sp)
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
lw $t0,-16($fp)
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
lw $t0,-8($fp)
sw $t0,0($sp)
lw $t0,-12($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal relation
addi $t0,$zero,0
lw $t1,-8($fp)
sub $t3,$t0,$t1
sw $t3,-24($fp)
addi $t0,$zero,-1
addi $t1,$fp,-28
sw $t0,0($t1)
lw $t0,-8($fp)
lw $t1,-28($fp)
div $t0,$t1
mflo $t3
sw $t3,-32($fp)
lw $t0,-12($fp)
lw $t1,-32($fp)
mult $t0,$t1
mflo $t3
sw $t3,-36($fp)
addi $t0,$zero,97
addi $t1,$fp,-40
sw $t0,0($t1)
lw $t0,-36($fp)
lw $t1,-40($fp)
mult $t0,$t1
mflo $t3
sw $t3,-44($fp)
lw $t0,-24($fp)
lw $t1,-44($fp)
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
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
lw $t1,-56($fp)
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
la $t0,index
lw $t0,0($t0)
lw $t1,-68($fp)
mult $t0,$t1
mflo $t3
sw $t3,-72($fp)
addi $t0,$zero,1
addi $t1,$fp,-76
sw $t0,0($t1)
lw $t0,-72($fp)
lw $t1,-76($fp)
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
lw $t1,-96($fp)
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
