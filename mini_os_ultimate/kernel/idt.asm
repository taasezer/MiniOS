\
    ; idt.asm - IDT table and helper to load it (ISR handlers in isr_common.asm)
    BITS 64
    GLOBAL idt_install
    SECTION .bss
    idt_table: resb 256*16
    idt_ptr: resb 10
    SECTION .text
    idt_install:
        lea rax, [rel idt_ptr]
        mov word [rax], idt_table_end - idt_table - 1
        mov qword [rax+2], idt_table
        lidt [rax]
        sti
        ret
    idt_table_end:
