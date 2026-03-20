.section .rodata
fmt: .string "Hello"


.data
   .globl val
   .align 4
val: .int 432

   .globl age
   .align 2
age: .short 4

   .globl r
   .align 4
r: .int 0

   .globl err
   .align 8
err: .quad 2048


.text



.globl main

main:

   pushq %rbp

   movq  %rsp, %rbp



   # Seu código aqui...

   movq $fmt, %rdi # 4
   movl val, %esi 
   movw age, %dx # 2
   movq $r, %rcx # 8

   call sum
   movl %eax, val

   movq err, %rdi
   movl val, %esi
   movl r, %edx

   call show

   # Faça o "return"
   movl $0, %eax
   leave

   ret