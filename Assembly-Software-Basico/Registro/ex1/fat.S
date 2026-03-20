.section .rodata

        .data

        .text

        .globl fat

fat:
        pushq %rbp
        movq %rsp, %rbp
        subq $8, %rsp # Como calcular o valor em subq, para diferentes tamanhos de pilha?

        cmpl $0, %edi
        jle end_if

        movq %rdi, -8(%rbp)
        decl %edi
        call fat

        movq -8(%rbp), %rdi  # Recuperar somente o necessário da pilha para futuras operações ou mudanças
        imull %edi, %eax

        leave
        ret
    end_if:
        movl $1, %eax
end_fat:
        # Seu código aqui...

        leave

        ret