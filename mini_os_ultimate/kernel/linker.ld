\
    OUTPUT_FORMAT(elf64-x86-64)
    ENTRY(_start)
    SECTIONS {
      . = 0x100000;
      .multiboot_header ALIGN(8) : { *(.multiboot_header) }
      .text ALIGN(4096) : { *(.text) }
      .rodata ALIGN(4096) : { *(.rodata) }
      .data ALIGN(4096) : { *(.data) }
      .bss ALIGN(4096) : { *(.bss) *(COMMON) }
    }
