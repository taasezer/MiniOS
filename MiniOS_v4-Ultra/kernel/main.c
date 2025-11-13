#include <stdint.h>
extern void shell_main_c(void);
extern void kb_map_init(void);
extern void ramdisk_init(void);

void main_c(void){
    kb_map_init();
    ramdisk_init();
    shell_main_c();
    for(;;) asm volatile("hlt");
}
