BITS 64
GLOBAL _start
EXTERN gdt_install
EXTERN idt_install
EXTERN pic_init
EXTERN pit_init
EXTERN paging_install
EXTERN heap_init
EXTERN console_clear
EXTERN console_write_str
EXTERN modules_init
EXTERN keyboard_install
EXTERN scheduler_init
EXTERN main_c

SECTION .text
_start:
    lea rsp, [rel _stack_top]
    call gdt_install
    call idt_install
    call pic_init
    call pit_init
    call paging_install
    call heap_init
    call console_clear
    lea rdi, [rel boot_msg]
    call console_write_str
    call modules_init
    call keyboard_install
    call scheduler_init
    call main_c
.halt:
    cli
    hlt
    jmp .halt

SECTION .bss
align 16
_stack_bottom: resb 65536
_stack_top:

SECTION .rodata
boot_msg: db "MiniOS v5 - BOOTED", 0x0A, 0
