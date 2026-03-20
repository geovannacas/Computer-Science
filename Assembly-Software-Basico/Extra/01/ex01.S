.section .rodata



        .data
            .globl max
            .align 2
        max: .short 0

            .globl vet
            .align 2
        vet: .short 50, 10, 67, 42


        .text

        .globl ex01

ex01:

        pushq %rbp

        movq  %rsp, %rbp



        # Seu código aqui...
        movb $0, %cl

        for_loop:

        cmpb $4, %cl
        jge end_loop

        movq $vet, %r8
        movsbq %cl, %r9
        imulq $2, %r9
        addq %r8, %r9
        movw (%r9), %dx

        cmpw max, %dx
        jle end_if

        movw %dx, max

        end_if:

        incb %cl
        jmp for_loop 
        end_loop:


        leave

        ret