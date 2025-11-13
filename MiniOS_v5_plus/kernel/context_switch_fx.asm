BITS 64
GLOBAL context_switch_fx
; rdi = old_task ptr, rsi = new_task ptr
; old/new task layout: qword rsp, qword rip, fxsave_area (512 bytes), ...
SECTION .text
context_switch_fx:
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
    mov [rdi], rsp
    mov rax, rdi
    add rax, 16
    fxsave64 [rax]
    mov rsp, [rsi]
    mov rax, rsi
    add rax, 16
    fxrstor64 [rax]
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
    mov rax, [rsi + 8]
    jmp rax
