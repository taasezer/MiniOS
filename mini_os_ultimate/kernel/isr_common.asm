\
    ; isr_common.asm - basic ISR prolog/epilog for C handlers to use
    BITS 64
    GLOBAL isr_common_stub
    section .text
    isr_common_stub:
        ; preserve registers
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
        ; push error code placeholder
        push qword 0
        ; pass pointer to stack frame in rdi
        mov rdi, rsp
        extern isr_c_handler
        call isr_c_handler
        add rsp, 8
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
        ; iretq - use opcode bytes 0x48 0xcf is wrong; proper iretq is 0x48 0xcf ?
        ; we'll use 'iretq' mnemonic (NASM supports it in 64-bit when in interrupt context)
        iretq
