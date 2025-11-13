\
    ; gdt.asm - GDT & TSS setup for long mode (simplified)
    BITS 64
    GLOBAL gdt_install
    SECTION .data
    ALIGN 8
    gdt_entries:
        dq 0x0000000000000000    ; null
        dq 0x00AF9A000000FFFF    ; code
        dq 0x00AF92000000FFFF    ; data
    gdt_descriptor:
        dw gdt_end - gdt_entries - 1
        dq gdt_entries
    gdt_end:
    SECTION .text
    gdt_install:
        lgdt [rel gdt_descriptor]
        ; load data segments
        mov ax, 0x10
        mov ds, ax
        mov es, ax
        mov ss, ax
        mov fs, ax
        mov gs, ax
        ; reload cs: far jump style
        pushq 0x08
        lea rax, [rel 1f]
        push rax
        retf
    1:
        ret
