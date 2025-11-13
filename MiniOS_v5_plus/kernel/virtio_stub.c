#include <stdint.h>
extern void console_write_str(const char*);
void virtio_net_init(void){
    console_write_str("virtio-net: init stub (implement device probing & queue setup)\n");
}
