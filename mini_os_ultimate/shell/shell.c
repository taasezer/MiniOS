\
    // shell.c - minimal interactive shell (placeholder)
    #include <stdint.h>\nextern void console_write_str(const char*);\nvoid shell_main_c(void){ console_write_str(\"\\nUltimate Shell v0.1\\n> \"); for(;;) asm volatile(\"hlt\"); }\n