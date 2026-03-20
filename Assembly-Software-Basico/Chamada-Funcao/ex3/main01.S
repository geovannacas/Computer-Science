.section .rodata

string01:
    .string "'a' maior do que 'b'\n"

string02:
    .string "Valor de 'b': %d\n"


.data
    .globl a
    .align 1
a:  .byte 97
    
    .globl b
    .align 1
b:  .byte 105 


.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp



   # Seu código aqui...

    movb a, %dil
    movb b, %sil

    call maximo

    movl %eax, %ebx

    start_if:
        movsbl a, %eax
        cmpl %eax, %ebx     
        jne else

        movq $string01, %rdi
        movl $0, %eax
        call printf
        
        jmp end_if
    else:
        movq $string02, %rdi
        movsbl b, %esi
        movl $0, %eax
        call printf

    end_if:
    movl $0, %eax   # return 0

   leave

   ret