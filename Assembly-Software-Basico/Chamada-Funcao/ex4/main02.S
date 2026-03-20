.section .rodata

string01:
    .string "Iteração %d, v = %d\n"

.data
    .globl i
    .align 4
i:  .int 0

    .globl v
    .align 2
v:  .short 0

    .globl vetA
    .align 2
vetA: .short 28,42,16,23,47

    .globl vetB
    .align 4
vetB: .int 0,0,0,0,0


.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp



   # Seu código aqui...

    start_while:
        cmpl $5, i
        jge end_while

        movq $vetA, %r8
        movslq i, %r9 # (long)i
        imulq $2, %r9 # i * sizeof
        addq %r8, %r9 # r9 = &vet

        movw (%r9), %cx
        shlw $2, %cx
        movw %cx, v

        movq $string01, %rdi
        movl i, %esi
        movswl v, %edx
        movl $0, %eax
        call printf

        movq $vetB, %r8
        movslq i, %r9
        imulq $4, %r9
        addq %r8, %r9

        movl i, %edi
        movw v, %si
        movq %r9, %rdx
        call process

        incl i
    end_while:

    movq $vetB, %rdi
    movq $5, %rsi
    call show

   movl $0, %eax   # return 0

   leave

   ret