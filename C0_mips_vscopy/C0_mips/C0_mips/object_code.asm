.data
maxsize: .word 100
maxnum: .word 100000
minnum: .word -100000
array: .word 0:100
o_left: .word 0
o_right: .word 0
o_sum: .word 0
name: .word 0:24
.text
addi $fp,$sp,0
j main
find_max_crossing_subarray:
sw $ra,4($sp)
addi $sp,$sp,-92
lw $t0,-0($fp)
addi $s3,$t0,0
lw $t0,-4($fp)
addi $s1,$t0,0
add $t3,$s3,$s1
sw $t3,-28($fp)
addi $t0,$zero,2
addi $t1,$fp,-32
sw $t0,0($t1)
lw $t0,-28($fp)
lw $t1,-32($fp)
div $t0,$t1
mflo $t3
sw $t3,-36($fp)
lw $t0,-36($fp)
addi $s2,$t0,0
la $t0,minnum
lw $t0,0($t0)
addi $s4,$t0,0
addi $t0,$zero,0
addi $t1,$fp,-40
sw $t0,0($t1)
lw $t0,-40($fp)
addi $s5,$t0,0
addi $s6,$s2,0
label0:
addi $t1,$zero,4
mult $s6,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
sw $t0,-44($fp)
lw $t1,-44($fp)
add $t3,$s5,$t1
sw $t3,-48($fp)
lw $t0,-48($fp)
addi $s5,$t0,0
sub $t2,$s5,$s4
blez $t2,label1
addi $s4,$s5,0
la $t1,o_left
sw $s6,0($t1)
label1:
addi $t0,$zero,1
addi $t1,$fp,-52
sw $t0,0($t1)
lw $t1,-52($fp)
sub $t3,$s6,$t1
sw $t3,-56($fp)
lw $t0,-56($fp)
addi $s6,$t0,0
sub $t2,$s6,$s3
bgez $t2,label0
la $t0,minnum
lw $t0,0($t0)
addi $s0,$t0,0
addi $t0,$zero,0
addi $t1,$fp,-60
sw $t0,0($t1)
lw $t0,-60($fp)
addi $s5,$t0,0
addi $t0,$zero,1
addi $t1,$fp,-64
sw $t0,0($t1)
lw $t1,-64($fp)
add $t3,$s2,$t1
sw $t3,-68($fp)
lw $t0,-68($fp)
addi $s6,$t0,0
label2:
addi $t1,$zero,4
mult $s6,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
sw $t0,-72($fp)
lw $t1,-72($fp)
add $t3,$s5,$t1
sw $t3,-76($fp)
lw $t0,-76($fp)
addi $s5,$t0,0
sub $t2,$s5,$s0
blez $t2,label3
addi $s0,$s5,0
la $t1,o_right
sw $s6,0($t1)
label3:
addi $t0,$zero,1
addi $t1,$fp,-80
sw $t0,0($t1)
lw $t1,-80($fp)
add $t3,$s6,$t1
sw $t3,-84($fp)
lw $t0,-84($fp)
addi $s6,$t0,0
sub $t2,$s6,$s1
blez $t2,label2
add $t3,$s4,$s0
sw $t3,-88($fp)
lw $t0,-88($fp)
la $t1,o_sum
sw $t0,0($t1)
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
find_maximum_subarray:
sw $ra,4($sp)
addi $sp,$sp,-100
lw $t0,-0($fp)
addi $t6,$t0,0
lw $t0,-4($fp)
addi $t5,$t0,0
bne $t6,$t5,label4
la $t1,o_left
sw $t6,0($t1)
la $t1,o_right
sw $t5,0($t1)
addi $t1,$zero,4
mult $t6,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
sw $t0,-56($fp)
lw $t0,-56($fp)
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
label4:
add $t3,$t6,$t5
sw $t3,-60($fp)
addi $t0,$zero,2
addi $t1,$fp,-64
sw $t0,0($t1)
lw $t0,-60($fp)
lw $t1,-64($fp)
div $t0,$t1
mflo $t3
sw $t3,-68($fp)
lw $t0,-68($fp)
addi $t1,$fp,-8
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
sw $t6,0($sp)
lw $t0,-8($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $t0,$fp,-72
sw $v0,0($t0)
lw $t0,-72($fp)
addi $t1,$fp,-40
sw $t0,0($t1)
la $t0,o_left
lw $t0,0($t0)
addi $s5,$t0,0
la $t0,o_right
lw $t0,0($t0)
addi $s4,$t0,0
addi $t0,$zero,1
addi $t1,$fp,-76
sw $t0,0($t1)
lw $t0,-8($fp)
lw $t1,-76($fp)
add $t3,$t0,$t1
sw $t3,-80($fp)
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
lw $t0,-80($fp)
sw $t0,0($sp)
sw $t5,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $t0,$fp,-84
sw $v0,0($t0)
lw $t0,-84($fp)
addi $s7,$t0,0
la $t0,o_left
lw $t0,0($t0)
addi $s1,$t0,0
la $t0,o_right
lw $t0,0($t0)
addi $s0,$t0,0
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
sw $t6,0($sp)
sw $t5,-4($sp)
addi $fp,$sp,0
jal find_max_crossing_subarray
la $t0,o_sum
lw $t0,0($t0)
addi $t5,$t0,0
la $t0,o_left
lw $t0,0($t0)
addi $s3,$t0,0
la $t0,o_right
lw $t0,0($t0)
addi $s2,$t0,0
addi $t0,$zero,108
addi $t1,$fp,-88
sw $t0,0($t1)
lw $t0,-88($fp)
addi $s6,$t0,0
lw $t0,-40($fp)
addi $t4,$t0,0
sub $t2,$s7,$t4
blez $t2,label5
addi $t4,$s7,0
addi $t0,$zero,114
addi $t1,$fp,-92
sw $t0,0($t1)
lw $t0,-92($fp)
addi $s6,$t0,0
label5:
sub $t2,$t5,$t4
blez $t2,label6
addi $t4,$t5,0
addi $t0,$zero,109
addi $t1,$fp,-96
sw $t0,0($t1)
lw $t0,-96($fp)
addi $s6,$t0,0
label6:
addi $t1,$zero,108
bne $s6,$t1,label8
la $t1,o_left
sw $s5,0($t1)
la $t1,o_right
sw $s4,0($t1)
addi $v0,$t4,0
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
j label7
label8:
addi $t1,$zero,109
bne $s6,$t1,label9
la $t1,o_left
sw $s3,0($t1)
la $t1,o_right
sw $s2,0($t1)
addi $v0,$t4,0
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
j label7
label9:
addi $t1,$zero,114
bne $s6,$t1,label10
la $t1,o_left
sw $s1,0($t1)
la $t1,o_right
sw $s0,0($t1)
addi $v0,$t4,0
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
j label7
label10:
label7:
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
addi $sp,$sp,-44
addi $a0,$zero,77
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,120
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,83
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,121
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,80
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,111
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $a0,$zero,80
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,101
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
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,121
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,122
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,58
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $v0,$zero,5
syscall
addi $s1,$v0,0
la $t1,maxsize
lw $t1,0($t1)
sub $t2,$s1,$t1
blez $t2,label11
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,121
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,122
addi $v0,$zero,11
syscall
addi $a0,$zero,101
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
addi $a0,$zero,111
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
addi $a0,$zero,10
addi $v0,$zero,11
syscall
j EXIT
label11:
addi $t0,$zero,0
addi $t1,$fp,-16
sw $t0,0($t1)
lw $t0,-16($fp)
addi $s0,$t0,0
label12:
addi $v0,$zero,5
syscall
sw $v0,-12($fp)
addi $t1,$zero,4
mult $s0,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t1,,-12($fp)
sw $t1,0($t0)
addi $t0,$zero,1
addi $t1,$fp,-20
sw $t0,0($t1)
lw $t1,-20($fp)
add $t3,$s0,$t1
sw $t3,-24($fp)
lw $t0,-24($fp)
addi $s0,$t0,0
sub $t2,$s0,$s1
bltz $t2,label12
addi $t0,$zero,0
addi $t1,$fp,-28
sw $t0,0($t1)
addi $t0,$zero,1
addi $t1,$fp,-32
sw $t0,0($t1)
lw $t1,-32($fp)
sub $t3,$s1,$t1
sw $t3,-36($fp)
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
lw $t0,-28($fp)
sw $t0,0($sp)
lw $t0,-36($fp)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $t0,$fp,-40
sw $v0,0($t0)
lw $t0,-40($fp)
addi $t1,$fp,-8
sw $t0,0($t1)
addi $a0,$zero,77
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,120
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,83
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,121
addi $v0,$zero,11
syscall
addi $a0,$zero,58
addi $v0,$zero,11
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $a0,$zero,108
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,102
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,95
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,100
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,120
addi $v0,$zero,11
syscall
addi $a0,$zero,61
addi $v0,$zero,11
syscall
la $t0,o_left
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,103
addi $v0,$zero,11
syscall
addi $a0,$zero,104
addi $v0,$zero,11
syscall
addi $a0,$zero,116
addi $v0,$zero,11
syscall
addi $a0,$zero,95
addi $v0,$zero,11
syscall
addi $a0,$zero,105
addi $v0,$zero,11
syscall
addi $a0,$zero,110
addi $v0,$zero,11
syscall
addi $a0,$zero,100
addi $v0,$zero,11
syscall
addi $a0,$zero,101
addi $v0,$zero,11
syscall
addi $a0,$zero,120
addi $v0,$zero,11
syscall
addi $a0,$zero,61
addi $v0,$zero,11
syscall
la $t0,o_right
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
addi $a0,$zero,83
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,98
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,114
addi $v0,$zero,11
syscall
addi $a0,$zero,97
addi $v0,$zero,11
syscall
addi $a0,$zero,121
addi $v0,$zero,11
syscall
addi $a0,$zero,32
addi $v0,$zero,11
syscall
addi $a0,$zero,115
addi $v0,$zero,11
syscall
addi $a0,$zero,117
addi $v0,$zero,11
syscall
addi $a0,$zero,109
addi $v0,$zero,11
syscall
addi $a0,$zero,61
addi $v0,$zero,11
syscall
lw $t0,-8($fp)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
j EXIT
EXIT:
