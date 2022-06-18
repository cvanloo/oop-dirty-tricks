.globl _ZN7Point2F3AddERKS_
_ZN7Point2F3AddERKS_:
    push   %rbp
    mov    %rsp,%rbp
    mov    %rdi,-0x8(%rbp)
    mov    %rsi,-0x10(%rbp)
    mov    -0x8(%rbp),%rax
    movss  (%rax),%xmm1
    mov    -0x10(%rbp),%rax
    movss  (%rax),%xmm0
    addss  %xmm1,%xmm0
    mov    -0x8(%rbp),%rax
    movss  %xmm0,(%rax)
    mov    -0x8(%rbp),%rax
    movss  0x4(%rax),%xmm1
    mov    -0x10(%rbp),%rax
    movss  0x4(%rax),%xmm0
    addss  %xmm1,%xmm0
    mov    -0x8(%rbp),%rax
    movss  %xmm0,0x4(%rax)
    nop
    pop    %rbp
    ret
