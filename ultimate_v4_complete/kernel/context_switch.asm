BITS 64
GLOBAL context_switch
; rdi = pointer to old_task struct, rsi = pointer to new_task struct
; task struct: qword rsp, qword rip
SECTION .text
context_switch:
    ; save callee-saved + general regs onto current stack, then store rsp into [rdi]
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
    ; store current rsp into [rdi]
    mov [rdi], rsp
    ; load new rsp from [rsi]
    mov rsp, [rsi]
    ; pop registers from new stack (assumes appropriate layout)
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ; jump to new RIP at [rsi + 8]
    mov rax, [rsi + 8]
    jmp rax
