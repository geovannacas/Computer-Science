.data

    .globl  c
    .align  1
c:  .byte   -20

    .globl  i
    .align  4
i:  .int    -256

    .globl  j
    .align  4
j:  .int    512

    .globl  l
    .align  8
l:  .quad   128

    .globl  us
    .align  2
us: .short  111

    .globl  ui
    .align  4
ui: .int    1024

    .globl  ul
    .align  8
ul: .quad   2048

.text



    .globl  aux

aux:

    pushq   %rbp

    movq    %rsp,   %rbp



    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    // Atribuições simples
    //j = 68000;
    //l = 4096;
    //i = j;
    movl $68000, j
    movl $4096, l
    movl j, %r8d
    movl %r8d, i

    // Expressões
    //j = 10 + i - 5;
    movl i, %eax
    addl $10, %eax
    subl $5, %eax
    movl %eax, j

    //i = (i * 2) - (j + 5);
    movl i, %ecx 
    imull $2, %ecx 
    movl j, %edx 
    addl $5, %edx 
    subl %edx, %ecx 
    movl %ecx, i 

    movl i, %esi
    movl %esi, ui

    movsbl c, %eax
    movl %eax, j

    movq ul, %rdx
    movw %dx, us

    leave

    ret