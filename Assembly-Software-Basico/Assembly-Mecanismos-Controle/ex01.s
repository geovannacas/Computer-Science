.section .rodata

.data

    .globl  a
    .align  4
a:  .int    30

    .globl  b
    .align  4
b:  .int    45

    .globl  c
    .align  4
c:  .int    -60

    .globl  d
    .align  4
d:  .int    25

.text

.globl ex01

ex01:

   pushq %rbp

   movq  %rsp, %rbp

    movl a, %eax
    movl b, %ecx


    cmpl %ecx, %eax
    jle end_if
        movl c, %esi
        negl %esi
        movl %esi, c


        movl c, %edx
        cltd
        movl $3, %ebx
        idivl %ebx
        movl %edx, d
    end_if:

    cmpl %eax, %ecx
    jl end_2_if
        movl a, %eax
        movl b, %ebx
        addl %ebx, %eax

        movl c, %edx
        imull %eax, %edx
        movl %edx, c

        movl $1024, d
    end_2_if:

   leave

   ret