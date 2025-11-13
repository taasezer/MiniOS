#include <stdint.h>
unsigned char kb_buf[256];
unsigned char kb_head = 0;
unsigned char kb_tail = 0;
void kb_buffer_push(unsigned char c){
    unsigned char next = (kb_head + 1) & 0xff;
    if(next==kb_tail) return;
    kb_buf[kb_head] = c;
    kb_head = next;
}
int kb_buffer_pop_nonblock(void){
    if(kb_head==kb_tail) return 0;
    unsigned char c = kb_buf[kb_tail];
    kb_tail = (kb_tail + 1) & 0xff;
    return c;
}
