BITS 64
GLOBAL context_switch
; rdi = old task ptr, rsi = new task ptr
SECTION .text
context_switch:
    push rbp
    mov rbp, rsp
    push rax
    push rbx
    push rcx
    push rdx
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
    mov [rdi], rsp
    mov rsp, [rsi]
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rbx
    pop rax
    pop rbp
    mov rax, [rsi + 8]
    jmp rax
