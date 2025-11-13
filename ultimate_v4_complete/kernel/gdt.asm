BITS 64
GLOBAL gdt_install
SECTION .data
ALIGN 8
gdt:
    dq 0x0000000000000000
    dq 0x00AF9A000000FFFF
    dq 0x00AF92000000FFFF
gdt_descr:
    dw gdt_end - gdt - 1
    dq gdt
gdt_end:
SECTION .text
gdt_install:
    lgdt [rel gdt_descr]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov fs, ax
    mov gs, ax
    pushq 0x08
    lea rax, [rel 1f]
    push rax
    retf
1:
    ret
