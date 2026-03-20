.globl media

media:

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

movl $0, %r12d
movq $0, %r13

movl $0, %r12d

movq %r12, -8(%rbp)
movq %r13, -16(%rbp)

for01:
    movslq %r12d, %rax
    cmpq %rsi, %rax
    jge endfor01

    movslq %r12d, %rax
    imulq $24, %rax
    addq %rdi, %rax

    addq 8(%rax), %r13

    incl %r12d
    jmp for01

endfor01:

movq -8(%rbp), %r12
movq -16(%rbp), %r13

movq %r13, %rax
cqto
idivq %rsi

leave

ret
