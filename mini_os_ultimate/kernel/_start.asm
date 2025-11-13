\
    ; _start.asm - kernel entry
    BITS 64
    GLOBAL _start
    EXTERN gdt_install, idt_install, pit_init, keyboard_install, paging_enable, kheap_init, scheduler_init, console_clear, console_write_str, main_c
    SECTION .text
    _start:
        ; Set up stack
        lea rsp, [rel stack_top]

        ; initialize GDT & TSS
        call gdt_install

        ; install IDT and default ISRs
        call idt_install

        ; enable basic paging (identity mapping + higher half)
        call paging_enable

        ; initialize kernel heap and frame allocator
        call kheap_init

        ; initialize console (VGA)
        call console_clear
        lea rdi, [rel boot_msg]
        call console_write_str

        ; initialize PIT and scheduler (timer interrupts)
        call pit_init

        ; install keyboard IRQ handler
        call keyboard_install

        ; initialize scheduler (creates idle task and launches main)
        call scheduler_init

        ; jump to C main
        call main_c

    .halt:
        cli
        hlt
        jmp .halt

    SECTION .bss
    ALIGN 16
    stack_bottom: resb 16384
    stack_top:
    SECTION .rodata
    boot_msg db "ULTIMATE-MINI-OS booted. Welcome to the Ultimate Mini OS!", 0x0A, 0
