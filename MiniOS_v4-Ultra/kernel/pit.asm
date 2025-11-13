BITS 64
GLOBAL pit_init
SECTION .text
pit_init:
    mov al, 0x36
    out 0x43, al
    mov ax, 1193
    out 0x40, al
    mov al, ah
    out 0x40, al
    ret
