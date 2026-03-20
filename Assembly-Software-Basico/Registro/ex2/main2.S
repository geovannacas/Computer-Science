.section .rodata

        .data
            .globl v1
            .align 2
            v1: .word 1,2

            .globl v2
            .align 8
            v2: .short 1,2,3
        .text

        .globl main
        .globl aux

aux:
        pushq %rbp
        movq  %rsp, %rbp
        subq $24, %rsp

        movl $2, %ecx
        loop:
            cmpl $0, %ecx
            jl end_loop

            movq %rdi, -8(%rbp)
            movq %rsi, -16(%rbp)
            movq $v2, %rdx
            movq %rcx, -24(%rbp)
            call sum

            movq -8(%rbp), %rdi
            movq -16(%rbp), %rsi
            movq -24(%rbp), %rcx
            
            decl %ecx

            jmp loop
        end_loop:

            leave
            ret

main:

    pushq %rbp
    movq  %rsp, %rbp
    subq $16, %rsp

    movl $0, %ecx

    loop_01:
        cmpl $2, %ecx
        jge end_loop_01

        movq %rcx, -8(%rbp)
        movq $v1, %rdi
        movl %ecx, %esi
        call aux

        movq -8(%rbp), %rcx

        incl %ecx
        jmp loop_01
    end_loop_01:
        movl $0, %eax
    
        leave

        ret


