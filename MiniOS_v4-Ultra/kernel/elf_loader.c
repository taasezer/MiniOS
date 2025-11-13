#include <stdint.h>
#include <stddef.h>
extern struct file_entry* ramdisk_find(const char* name);
extern void console_write_str(const char*);
typedef void (*entry_t)(void);
int elf_run(const char* name){
    struct file_entry* f = ramdisk_find(name);
    if(!f){ console_write_str("ELF not found\n"); return -1; }
    void* dest = (void*)0x400000;
    unsigned char* src = (unsigned char*)f->data;
    unsigned char* d = (unsigned char*)dest;
    for(size_t i=0;i<f->size;i++) d[i] = src[i];
    console_write_str("Jumping to flat program at 0x400000\n");
    entry_t e = (entry_t)dest;
    e();
    return 0;
}
