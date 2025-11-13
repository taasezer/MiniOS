#include <stdint.h>
#include <stddef.h>
extern void scheduler_tick(void);
extern void pic_eoi(void);
extern void kb_buffer_push(unsigned char c);
extern unsigned char kb_map[256];
extern void handle_page_fault(uint64_t err_code);
extern void console_write_str(const char*);
void isr_c_handler(int vector, uint64_t* regs){
    if(vector==0x20){
        scheduler_tick();
        pic_eoi();
    } else if(vector==0x21){
        unsigned char sc;
        asm volatile("inb %1, %0" : "=a"(sc) : "Nd"(0x60));
        unsigned char ch = kb_map[sc];
        if(ch) kb_buffer_push(ch);
        pic_eoi();
    } else if(vector==14){
        uint64_t err = regs[0];
        handle_page_fault(err);
    } else {
        pic_eoi();
    }
}
