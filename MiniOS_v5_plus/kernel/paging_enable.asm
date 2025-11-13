BITS 64
GLOBAL paging_install
SECTION .bss
align 4096
pml4: resq 512
pdpt: resq 512
pd:   resq 512
SECTION .text
paging_install:
    ; Clear first entries (simple)
    lea rdi, [rel pd]
    mov rcx, 512
    xor rax, rax
.zero_pd:
    mov [rdi], rax
    add rdi, 8
    dec rcx
    jnz .zero_pd

    ; fill pd entries for 2MB pages mapping first 16MB (8 entries)
    lea rdi, [rel pd]
    mov rcx, 8
    mov rbx, 0
.pd_fill:
    mov rax, rbx
    or rax, (1<<7)  ; PS
    or rax, 3       ; present + rw
    mov [rdi], rax
    add rdi, 8
    add rbx, 0x200000
    dec rcx
    jnz .pd_fill

    ; link pd into pdpt and pml4
    lea rax, [rel pd]
    or rax, 3
    mov [rel pdpt], rax
    lea rax, [rel pdpt]
    or rax, 3
    mov [rel pml4], rax

    ; map higher-half by copying entry to pml4[511]
    lea rax, [rel pdpt]
    or rax, 3
    lea rdi, [rel pml4]
    add rdi, 511*8
    mov [rdi], rax

    ; load CR3
    lea rax, [rel pml4]
    mov cr3, rax
    ret
