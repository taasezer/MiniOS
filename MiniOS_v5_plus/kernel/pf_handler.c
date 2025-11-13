#include <stdint.h>
extern void console_write_str(const char*);
extern void console_write_hex(uint64_t v);
void handle_page_fault(uint64_t err_code){
    uint64_t cr2;
    asm volatile("mov %%cr2, %0" : "=r"(cr2));
    console_write_str("PAGE FAULT! err=0x");
    console_write_hex(err_code);
    console_write_str(" cr2=0x");
    console_write_hex(cr2);
    console_write_str("\n"); 
    for(;;) asm volatile("hlt");
}
