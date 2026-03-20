.section .rodata



.data
   .globl i
   .align 4
i: .int 0

   .globl bias
   .align 8
bias: .quad 256

   .globl LEN
   .align 1
vet: .byte 12, 3, 20, 8




.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp



   # Seu código aqui...
loop_for:
   cmpl $4, i
   jge end_for

   movb $vet, %dil
   movl $10, %esi
   movq bias, %rdx

   jmp loop_for
end_for
   # Faça o "return"
   movl $0, %eax


   leave

   ret