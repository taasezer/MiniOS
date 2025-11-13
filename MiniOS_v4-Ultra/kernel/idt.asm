BITS 64
GLOBAL idt_install, idt_set_entry
SECTION .bss
ALIGN 16
idt_table: resb 256*16
idt_ptr: resb 10
SECTION .text
idt_set_entry:
    push rbp
    mov rbp, rsp
    mov rcx, rdi
    imul rcx, 16
    lea rdi, [rel idt_table]
    add rdi, rcx
    mov rax, rsi
    mov word [rdi + 0], ax
    mov word [rdi + 2], 0x08
    mov byte [rdi + 4], 0
    mov byte [rdi + 5], 0x8E
    shr rax, 16
    mov word [rdi + 6], ax
    shr rax, 16
    mov dword [rdi + 8], eax
    mov dword [rdi + 12], 0
    pop rbp
    ret

idt_install:
    lea rax, [rel idt_ptr]
    mov word [rax], idt_table_end - idt_table - 1
    mov qword [rax+2], idt_table
    lidt [rax]
    sti
    ret
idt_table_end:
