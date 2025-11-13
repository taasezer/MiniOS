BITS 64
GLOBAL keyboard_install, kb_getc_nonblock
EXTERN idt_set_entry, irq1_stub
SECTION .text
keyboard_install:
    ; set IDT entry 0x21 to irq1_stub
    mov rdi, 0x21
    lea rsi, [rel irq1_stub]
    call idt_set_entry
    ret

; wrapper: call C function kb_buffer_pop_nonblock (extern) - but provide asm alias that returns in eax
EXTERN kb_buffer_pop_nonblock
kb_getc_nonblock:
    call kb_buffer_pop_nonblock
    ret
