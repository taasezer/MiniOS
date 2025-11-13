\
    // main.c - kernel main entry in C
    extern void shell_main_c(void);\nvoid main_c(void){ shell_main_c(); for(;;) asm volatile(\"hlt\"); }\n