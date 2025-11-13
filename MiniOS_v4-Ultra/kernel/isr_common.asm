BITS 64
GLOBAL isr_common_stub, irq0_stub, irq1_stub
EXTERN isr_c_handler
SECTION .text
irq0_stub:
    mov edi, 0x20
    jmp isr_common_stub
irq1_stub:
    mov edi, 0x21
    jmp isr_common_stub

isr_common_stub:
    push rbp
    mov rbp, rsp
    push r15
    push r14
    push r13
    push r12
    push r11
    push r10
    push r9
    push r8
    push rdx
    push rcx
    push rbx
    push rax
    mov rsi, rsp
    call isr_c_handler
    pop rax
    pop rbx
    pop rcx
    pop rdx
    pop r8
    pop r9
    pop r10
    pop r11
    pop r12
    pop r13
    pop r14
    pop r15
    pop rbp
    iretq
