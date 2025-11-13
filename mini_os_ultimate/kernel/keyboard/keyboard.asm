\
    ; keyboard.asm - keyboard read helper and install (placeholder)
    BITS 64
    GLOBAL keyboard_install, keyboard_read_scancode
    SECTION .text
    keyboard_install:
        ; In a full implementation we would create an IDT entry for IRQ1 and point to handler
        ret
    keyboard_read_scancode:
        in al, 0x60
        movzx rax, al
        ret
