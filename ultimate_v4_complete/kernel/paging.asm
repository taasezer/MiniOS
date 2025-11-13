BITS 64
GLOBAL paging_install
SECTION .text
paging_install:
    ; For compatibility, do not change CR3/CR0 here. Provide scaffold for future real mapping.
    ret
