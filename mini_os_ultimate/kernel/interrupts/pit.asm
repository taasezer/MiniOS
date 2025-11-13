\
    ; pit.asm - initialize PIT timer (IRQ0), simple tick generation for scheduler
    BITS 64
    GLOBAL pit_init
    SECTION .text
    pit_init:
        ; Program PIT - placeholder (hardware programming omitted here)
        ; Enable interrupts at CPU level as needed
        sti
        ret
