.data
addi $s0,$zero,1
con_int1: .word 1
addi $s1,$zero,-1
con_int2: .word -1
addi $s2,$zero,34
con_int3: .word 34
addi $s3,$zero,10
con_int4: .word 10
addi $s4,$zero,65
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
addi $t0,$fp,-0
lw $t0,0($t0)
addi $s0,$t0,0
addi $t0,$fp,-4
lw $t0,0($t0)
addi $s1,$t0,0
sub $t2,$s0,$s1
bltz $t2,label0
addi $v0,$s0,0
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
addi $t1,$fp,-8
lw $t1,0($t1)
addi $t2,$fp,-12
add $t3,$s0,$t1
sw $t3,0($t2)
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
addi $t0,$fp,-12
lw $t0,0($t0)
sw $t0,0($sp)
sw $s1,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $s2,$v0,0
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
addi $t0,$fp,-0
lw $t0,0($t0)
addi $s0,$t0,0
addi $t0,$fp,-4
lw $t0,0($t0)
addi $s1,$t0,0
addi $s2,$zero,0
addi $t0,$zero,0
addi $t1,$fp,-8
sw $t0,0($t1)
addi $s3,$zero,1
addi $t0,$zero,1
addi $t1,$fp,-12
sw $t0,0($t1)
sub $t2,$s0,$s1
bgtz $t2,label1
addi $t1,$fp,-16
sw $s2,0($t1)
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
sub $t2,$s0,$s1
bltz $t2,label2
addi $t1,$fp,-16
sw $s3,0($t1)
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
beq $s0,$s1,label3
label3:
bne $s0,$s1,label4
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
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$zero,0
bne $t0,$t1,label6
sub $t2,$s0,$s1
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
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$zero,1
bne $t0,$t1,label8
sub $t2,$s0,$s1
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
addi $t0,$fp,-0
sw $v0,0($t0)
addi $v0,$zero,5
syscall
addi $t0,$fp,-4
sw $v0,0($t0)
addi $v0,$zero,5
syscall
addi $t0,$fp,-8
sw $v0,0($t0)
addi $v0,$zero,5
syscall
addi $t0,$fp,-12
sw $v0,0($t0)
addi $t0,$zero,0
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$fp,-16
lw $t0,0($t0)
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
addi $t0,$fp,-0
lw $t0,0($t0)
sw $t0,0($sp)
addi $t0,$fp,-4
lw $t0,0($t0)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $s0,$v0,0
la $t1,bigger_input
sw $s0,0($t1)
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
addi $t0,$fp,-8
lw $t0,0($t0)
sw $t0,0($sp)
addi $t0,$fp,-12
lw $t0,0($t0)
sw $t0,-4($sp)
addi $fp,$sp,0
jal relation
addi $t0,$zero,0
addi $t1,$fp,-8
lw $t1,0($t1)
addi $t2,$fp,-20
sub $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$zero,-1
addi $t1,$fp,-24
sw $t0,0($t1)
addi $t0,$fp,-8
lw $t0,0($t0)
addi $t1,$fp,-24
lw $t1,0($t1)
addi $t2,$fp,-28
div $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$fp,-12
lw $t0,0($t0)
addi $t1,$fp,-28
lw $t1,0($t1)
addi $t2,$fp,-32
mult $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$zero,97
addi $t1,$fp,-36
sw $t0,0($t1)
addi $t0,$fp,-32
lw $t0,0($t0)
addi $t1,$fp,-36
lw $t1,0($t1)
addi $t2,$fp,-40
mult $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$fp,-20
lw $t0,0($t0)
addi $t1,$fp,-40
lw $t1,0($t1)
addi $t2,$fp,-44
add $t3,$t0,$t1
sw $t3,0($t2)
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
addi $t0,$fp,-8
lw $t0,0($t0)
sw $t0,0($sp)
addi $t0,$fp,-12
lw $t0,0($t0)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_bigger
addi $s1,$v0,0
addi $t0,$zero,7
addi $t1,$fp,-48
sw $t0,0($t1)
addi $t1,$fp,-48
lw $t1,0($t1)
addi $t2,$fp,-52
mult $s1,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$fp,-44
lw $t0,0($t0)
addi $t1,$fp,-52
lw $t1,0($t1)
addi $t2,$fp,-56
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-56
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
label10:
addi $t0,$zero,2
addi $t1,$fp,-60
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
addi $t1,$fp,-60
lw $t1,0($t1)
addi $t2,$fp,-64
mult $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$zero,1
addi $t1,$fp,-68
sw $t0,0($t1)
addi $t0,$fp,-64
lw $t0,0($t0)
addi $t1,$fp,-68
lw $t1,0($t1)
addi $t2,$fp,-72
add $t3,$t0,$t1
sw $t3,0($t2)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr
add $t0,$t1,$t0
addi $t1,$fp,-72
lw $t1,0($t1)
sw $t1,0($t0)
la $t0,con_ch4
lw $t0,0($t0)
la $t1,index
lw $t1,0($t1)
addi $t2,$fp,-76
add $t3,$t0,$t1
sw $t3,0($t2)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr_ch
add $t0,$t1,$t0
addi $t1,$fp,-76
lw $t1,0($t1)
sw $t1,0($t0)
la $t0,index
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,var_arr
add $t0,$t1,$t0
lw $t0,0($t0)
addi $t1,$fp,-80
sw $t0,0($t1)
addi $t0,$fp,-80
lw $t0,0($t0)
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
addi $t1,$fp,-84
sw $t0,0($t1)
addi $t0,$fp,-84
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $t0,$zero,1
addi $t1,$fp,-88
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
addi $t1,$fp,-88
lw $t1,0($t1)
addi $t2,$fp,-92
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-92
lw $t0,0($t0)
la $t1,index
sw $t0,0($t1)
la $t0,index
lw $t0,0($t0)
la $t1,con_int4
lw $t1,0($t1)
sub $t2,$t0,$t1
bltz $t2,label10
EXIT:
