.data

    .globl Circle
    .align 8
s1:
    .int 0
    .int 0
    .byte 0
    .zero 7
    .quad 0

.text

    fmt: .string "color: %ld, filled: %d\n"
    

    .globl  main

main:

    pushq   %rbp

    movq    %rsp,   %rbp

    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    movq $s1, %r8

    movl $10, (%r8)
    movl (%r8), %eax
    imull $2, %eax
    movl %eax, 4(%r8)
    movb $1, 8(%r8)

    cmpl $15, 4(%r8)
    jle else_01
    
    movq $2, 16(%r8)

    jmp end_if
    else_01:
    
    movq $1, 16(%r8)

    end_if:

    movq $fmt, %rdi
    movq 16(%r8), %rsi
    movswl 8(%r8), %edx
    movl $0, %eax
    call printf

    movl $0, %eax

    leave

    ret