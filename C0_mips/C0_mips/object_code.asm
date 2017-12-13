.data
addi $s0,$zero,100
maxsize: .word 100
addi $s1,$zero,100000
maxnum: .word 100000
addi $s2,$zero,-100000
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
addi $t0,$fp,-0
lw $t0,0($t0)
addi $s0,$t0,0
addi $t0,$fp,-4
lw $t0,0($t0)
addi $s1,$t0,0
addi $t2,$fp,-28
add $t3,$s0,$s1
sw $t3,0($t2)
addi $t0,$zero,2
addi $t1,$fp,-32
sw $t0,0($t1)
addi $t0,$fp,-28
lw $t0,0($t0)
addi $t1,$fp,-32
lw $t1,0($t1)
addi $t2,$fp,-36
div $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$fp,-36
lw $t0,0($t0)
addi $t1,$fp,-20
sw $t0,0($t1)
la $t0,minnum
lw $t0,0($t0)
addi $t1,$fp,-8
sw $t0,0($t1)
addi $t0,$zero,0
addi $t1,$fp,-40
sw $t0,0($t1)
addi $t0,$fp,-40
lw $t0,0($t0)
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$fp,-20
lw $t0,0($t0)
addi $t1,$fp,-24
sw $t0,0($t1)
label0:
addi $t0,$fp,-24
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
addi $t1,$fp,-44
sw $t0,0($t1)
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-44
lw $t1,0($t1)
addi $t2,$fp,-48
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-48
lw $t0,0($t0)
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-8
lw $t1,0($t1)
sub $t2,$t0,$t1
blez $t2,label1
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-8
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
la $t1,o_left
sw $t0,0($t1)
label1:
addi $t0,$zero,1
addi $t1,$fp,-52
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
addi $t1,$fp,-52
lw $t1,0($t1)
addi $t2,$fp,-56
sub $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-56
lw $t0,0($t0)
addi $t1,$fp,-24
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
sub $t2,$t0,$s0
bgez $t2,label0
la $t0,minnum
lw $t0,0($t0)
addi $t1,$fp,-12
sw $t0,0($t1)
addi $t0,$zero,0
addi $t1,$fp,-60
sw $t0,0($t1)
addi $t0,$fp,-60
lw $t0,0($t0)
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$zero,1
addi $t1,$fp,-64
sw $t0,0($t1)
addi $t0,$fp,-20
lw $t0,0($t0)
addi $t1,$fp,-64
lw $t1,0($t1)
addi $t2,$fp,-68
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-68
lw $t0,0($t0)
addi $t1,$fp,-24
sw $t0,0($t1)
label2:
addi $t0,$fp,-24
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
addi $t1,$fp,-72
sw $t0,0($t1)
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-72
lw $t1,0($t1)
addi $t2,$fp,-76
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-76
lw $t0,0($t0)
addi $t1,$fp,-16
sw $t0,0($t1)
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-12
lw $t1,0($t1)
sub $t2,$t0,$t1
blez $t2,label3
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-12
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
la $t1,o_right
sw $t0,0($t1)
label3:
addi $t0,$zero,1
addi $t1,$fp,-80
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
addi $t1,$fp,-80
lw $t1,0($t1)
addi $t2,$fp,-84
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-84
lw $t0,0($t0)
addi $t1,$fp,-24
sw $t0,0($t1)
addi $t0,$fp,-24
lw $t0,0($t0)
sub $t2,$t0,$s1
blez $t2,label2
addi $t0,$fp,-8
lw $t0,0($t0)
addi $t1,$fp,-12
lw $t1,0($t1)
addi $t2,$fp,-88
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-88
lw $t0,0($t0)
la $t1,o_sum
sw $t0,0($t1)
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
find_maximum_subarray:
sw $ra,4($sp)
addi $sp,$sp,-100
addi $t0,$fp,-0
lw $t0,0($t0)
addi $s0,$t0,0
addi $t0,$fp,-4
lw $t0,0($t0)
addi $s1,$t0,0
bne $s0,$s1,label4
la $t1,o_left
sw $s0,0($t1)
la $t1,o_right
sw $s1,0($t1)
addi $t1,$zero,4
mult $s0,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
lw $t0,0($t0)
addi $t1,$fp,-56
sw $t0,0($t1)
addi $t0,$fp,-56
lw $t0,0($t0)
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
label4:
addi $t2,$fp,-60
add $t3,$s0,$s1
sw $t3,0($t2)
addi $t0,$zero,2
addi $t1,$fp,-64
sw $t0,0($t1)
addi $t0,$fp,-60
lw $t0,0($t0)
addi $t1,$fp,-64
lw $t1,0($t1)
addi $t2,$fp,-68
div $t0,$t1
mflo $t3
sw $t3,0($t2)
addi $t0,$fp,-68
lw $t0,0($t0)
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
sw $fp,-32($sp)
sw $fp,-32($sp)
addi $sp,$sp,-40
sw $s0,0($sp)
addi $t0,$fp,-8
lw $t0,0($t0)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $s2,$v0,0
addi $t1,$fp,-40
sw $s2,0($t1)
la $t0,o_left
lw $t0,0($t0)
addi $t1,$fp,-16
sw $t0,0($t1)
la $t0,o_right
lw $t0,0($t0)
addi $t1,$fp,-20
sw $t0,0($t1)
addi $t0,$zero,1
addi $t1,$fp,-72
sw $t0,0($t1)
addi $t0,$fp,-8
lw $t0,0($t0)
addi $t1,$fp,-72
lw $t1,0($t1)
addi $t2,$fp,-76
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
addi $t0,$fp,-76
lw $t0,0($t0)
sw $t0,0($sp)
sw $s1,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $s3,$v0,0
addi $t1,$fp,-44
sw $s3,0($t1)
la $t0,o_left
lw $t0,0($t0)
addi $t1,$fp,-24
sw $t0,0($t1)
la $t0,o_right
lw $t0,0($t0)
addi $t1,$fp,-28
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
sw $s0,0($sp)
sw $s1,-4($sp)
addi $fp,$sp,0
jal find_max_crossing_subarray
la $t0,o_sum
lw $t0,0($t0)
addi $t1,$fp,-48
sw $t0,0($t1)
la $t0,o_left
lw $t0,0($t0)
addi $t1,$fp,-32
sw $t0,0($t1)
la $t0,o_right
lw $t0,0($t0)
addi $t1,$fp,-36
sw $t0,0($t1)
addi $t0,$zero,108
addi $t1,$fp,-80
sw $t0,0($t1)
addi $t0,$fp,-80
lw $t0,0($t0)
addi $t1,$fp,-52
sw $t0,0($t1)
addi $t0,$fp,-40
lw $t0,0($t0)
addi $t1,$fp,-12
sw $t0,0($t1)
addi $t0,$fp,-44
lw $t0,0($t0)
addi $t1,$fp,-12
lw $t1,0($t1)
sub $t2,$t0,$t1
blez $t2,label5
addi $t0,$fp,-44
lw $t0,0($t0)
addi $t1,$fp,-12
sw $t0,0($t1)
addi $t0,$zero,114
addi $t1,$fp,-84
sw $t0,0($t1)
addi $t0,$fp,-84
lw $t0,0($t0)
addi $t1,$fp,-52
sw $t0,0($t1)
label5:
addi $t0,$fp,-48
lw $t0,0($t0)
addi $t1,$fp,-12
lw $t1,0($t1)
sub $t2,$t0,$t1
blez $t2,label6
addi $t0,$fp,-48
lw $t0,0($t0)
addi $t1,$fp,-12
sw $t0,0($t1)
addi $t0,$zero,109
addi $t1,$fp,-88
sw $t0,0($t1)
addi $t0,$fp,-88
lw $t0,0($t0)
addi $t1,$fp,-52
sw $t0,0($t1)
label6:
addi $t0,$fp,-52
lw $t0,0($t0)
addi $t1,$zero,108
bne $t0,$t1,label8
addi $t0,$fp,-16
lw $t0,0($t0)
la $t1,o_left
sw $t0,0($t1)
addi $t0,$fp,-20
lw $t0,0($t0)
la $t1,o_right
sw $t0,0($t1)
addi $t0,$fp,-12
lw $t0,0($t0)
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
j label7
label8:
addi $t0,$fp,-52
lw $t0,0($t0)
addi $t1,$zero,109
bne $t0,$t1,label9
addi $t0,$fp,-32
lw $t0,0($t0)
la $t1,o_left
sw $t0,0($t1)
addi $t0,$fp,-36
lw $t0,0($t0)
la $t1,o_right
sw $t0,0($t1)
addi $t0,$fp,-12
lw $t0,0($t0)
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
j label7
label9:
addi $t0,$fp,-52
lw $t0,0($t0)
addi $t1,$zero,114
bne $t0,$t1,label10
addi $t0,$fp,-24
lw $t0,0($t0)
la $t1,o_left
sw $t0,0($t1)
addi $t0,$fp,-28
lw $t0,0($t0)
la $t1,o_right
sw $t0,0($t1)
addi $t0,$fp,-12
lw $t0,0($t0)
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
j label7
label10:
label7:
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
addi $t0,$fp,-0
sw $v0,0($t0)
addi $t0,$fp,-0
lw $t0,0($t0)
la $t1,maxsize
lw $t1,0($t1)
sub $t2,$t0,$t1
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
addi $t0,$fp,-16
lw $t0,0($t0)
addi $t1,$fp,-4
sw $t0,0($t1)
label12:
addi $v0,$zero,5
syscall
addi $t0,$fp,-12
sw $v0,0($t0)
addi $t0,$fp,-4
lw $t0,0($t0)
addi $t1,$zero,4
mult $t0,$t1
mflo $t0
la $t1,array
add $t0,$t1,$t0
addi $t1,$fp,-12
lw $t1,0($t1)
sw $t1,0($t0)
addi $t0,$zero,1
addi $t1,$fp,-20
sw $t0,0($t1)
addi $t0,$fp,-4
lw $t0,0($t0)
addi $t1,$fp,-20
lw $t1,0($t1)
addi $t2,$fp,-24
add $t3,$t0,$t1
sw $t3,0($t2)
addi $t0,$fp,-24
lw $t0,0($t0)
addi $t1,$fp,-4
sw $t0,0($t1)
addi $t0,$fp,-4
lw $t0,0($t0)
addi $t1,$fp,-0
lw $t1,0($t1)
sub $t2,$t0,$t1
bltz $t2,label12
addi $t0,$zero,0
addi $t1,$fp,-28
sw $t0,0($t1)
addi $t0,$zero,1
addi $t1,$fp,-32
sw $t0,0($t1)
addi $t0,$fp,-0
lw $t0,0($t0)
addi $t1,$fp,-32
lw $t1,0($t1)
addi $t2,$fp,-36
sub $t3,$t0,$t1
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
addi $t0,$fp,-28
lw $t0,0($t0)
sw $t0,0($sp)
addi $t0,$fp,-36
lw $t0,0($t0)
sw $t0,-4($sp)
addi $fp,$sp,0
jal find_maximum_subarray
addi $s0,$v0,0
addi $t1,$fp,-8
sw $s0,0($t1)
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
addi $t0,$fp,-8
lw $t0,0($t0)
addi $a0,$t0,0
addi $v0,$zero,1
syscall
addi $a0,$zero,10
addi $v0,$zero,11
syscall
j EXIT
EXIT:
