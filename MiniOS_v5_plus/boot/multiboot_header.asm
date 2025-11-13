; Multiboot2 header for GRUB
BITS 32
SECTION .multiboot_header ALIGN=8
MB2_MAGIC equ 0xE85250D6
MB2_ARCH  equ 0
mb2_start:
    dd MB2_MAGIC
    dd MB2_ARCH
    dd mb2_len
    dd -(MB2_MAGIC + MB2_ARCH + mb2_len)
    ; end tag
    dd 0
    dd 8
mb2_end:
mb2_len = mb2_end - mb2_start
