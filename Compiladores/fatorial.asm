.data
__str_0: .asciiz "Digite um numero inteiro nao negativo"
__str_1: .asciiz "O fatorial de "
__str_2: .asciiz " e: "

.text
.globl main
main:
    move $fp, $sp
    addiu $sp, $sp, -12
    li $t0, 1
    sub $t0, $zero, $t0
    sw $t0, -12($fp)
__enquanto_cond_0:
    lw $t0, -12($fp)
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    li $t0, 0
    lw $t1, 0($sp)
    addiu $sp, $sp, 4
    sle $t0, $t1, $t0
    beq $t0, $zero, __enquanto_fim_0
    la $a0, __str_0
    li $v0, 4
    syscall
    li $v0, 11
    li $a0, 10
    syscall
    li $v0, 5
    syscall
    sw $v0, -12($fp)
    j __enquanto_cond_0
__enquanto_fim_0:
    lw $t0, -12($fp)
    sw $t0, -4($fp)
    lw $t0, -12($fp)
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    li $t0, 1
    lw $t1, 0($sp)
    addiu $sp, $sp, 4
    sub $t0, $t1, $t0
    sw $t0, -8($fp)
__enquanto_cond_1:
    lw $t0, -8($fp)
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    li $t0, 1
    lw $t1, 0($sp)
    addiu $sp, $sp, 4
    sgt $t0, $t1, $t0
    beq $t0, $zero, __enquanto_fim_1
    lw $t0, -4($fp)
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    lw $t0, -8($fp)
    lw $t1, 0($sp)
    addiu $sp, $sp, 4
    mul $t0, $t1, $t0
    sw $t0, -4($fp)
    lw $t0, -8($fp)
    addiu $sp, $sp, -4
    sw $t0, 0($sp)
    li $t0, 1
    lw $t1, 0($sp)
    addiu $sp, $sp, 4
    sub $t0, $t1, $t0
    sw $t0, -8($fp)
    j __enquanto_cond_1
__enquanto_fim_1:
    la $a0, __str_1
    li $v0, 4
    syscall
    lw $t0, -12($fp)
    move $a0, $t0
    li $v0, 1
    syscall
    la $a0, __str_2
    li $v0, 4
    syscall
    lw $t0, -4($fp)
    move $a0, $t0
    li $v0, 1
    syscall
    li $v0, 11
    li $a0, 10
    syscall
    addiu $sp, $sp, 12
    li $v0, 10
    syscall
