#include <stdint.h>
extern void kb_map_init(void);
extern void ramdisk_init(void);
extern void modules_init(void);
extern void virtio_net_init(void);
extern void scheduler_init(void);
extern void shell_main_c(void);

void main_c(void){
    kb_map_init();
    ramdisk_init();
    modules_init();
    virtio_net_init(); /* stub */
    scheduler_init();
    shell_main_c();
    for(;;) asm volatile("hlt");
}
