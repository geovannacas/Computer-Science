.section .rodata


.data

    .globl  a
    .align  4
a:  .int    0

    .globl  b
    .align  4
b:  .int    2

.text

.globl ex02

ex02:

   pushq %rbp

   movq  %rsp, %rbp



   # _if(a == 0)-> end
   cmpl $0, a
   je end_if01
   
    # _if( b >= 5) -> else 
    cmpl $5, b
    jge else02
        movl a, %eax
        movl b, %ecx
        imull %eax, %ecx 
        shll $1, %eax
        addl %eax, %ecx
        movl %ecx, b

    jmp end_if02
    else02:
        movl b, %edx 
        
    end_if02:
   end_if01:



   leave

   ret