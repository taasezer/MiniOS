#include <stdint.h>
extern void console_write_str(const char*);
static const char *hex = "0123456789ABCDEF";
void console_write_hex(uint64_t v){
    char buf[17];
    for(int i=0;i<16;i++){ buf[15-i] = hex[v & 0xF]; v >>= 4; }
    buf[16]=0;
    console_write_str(buf);
}
