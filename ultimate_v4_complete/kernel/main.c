extern void shell_main_c(void);
extern void kb_map_init(void);
extern void ramdisk_init(void);
void main_c(void){
    kb_map_init();
    ramdisk_init();
    // shell will be started if scheduler returns to idle; but in this implementation scheduler jumps into tasks
    for(;;) asm volatile("hlt");
}
