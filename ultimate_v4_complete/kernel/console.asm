BITS 64
GLOBAL console_clear, console_write_char, console_write_str
SECTION .data
vga_cursor: dq 0
SECTION .text
console_clear:
    mov rcx, 80*25*2
    mov rdi, 0xB8000
    xor rax, rax
    rep stosb
    mov qword [vga_cursor], 0
    ret
console_write_char:
    movzx rax, dil
    mov rbx, [vga_cursor]
    shl rbx, 1
    mov byte [0B8000h + rbx], al
    mov byte [0B8000h + rbx + 1], 7
    inc qword [vga_cursor]
    ret
console_write_str:
    mov rsi, rdi
.loop:
    mov al, [rsi]
    cmp al, 0
    je .done
    push rdi
    mov dil, al
    call console_write_char
    pop rdi
    inc rsi
    jmp .loop
.done:
    ret
