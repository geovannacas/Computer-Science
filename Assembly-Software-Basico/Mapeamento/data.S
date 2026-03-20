.data

.text

    .globl  data

data:

    pushq   %rbp

    movq    %rsp,   %rbp

    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:

    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    

    leave

    ret