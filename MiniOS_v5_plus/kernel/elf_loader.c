#include <stdint.h>
#include <stddef.h>
#include "elf64.h"
extern void* kmalloc(size_t);
extern void console_write_str(const char*);
extern struct file_entry* ramdisk_find(const char* name);

int elf_run(const char* name){
    struct file_entry* f = ramdisk_find(name);
    if(!f){ console_write_str("ELF not found\n"); return -1; }
    unsigned char* data = (unsigned char*)f->data;
    Elf64_Ehdr* eh = (Elf64_Ehdr*)data;
    if(eh->e_ident[0]!=0x7f || eh->e_ident[1]!='E' || eh->e_ident[2]!='L' || eh->e_ident[3]!='F'){
        console_write_str("Not ELF\n"); return -1;
    }
    if(eh->e_type!=2){ console_write_str("Not ET_EXEC\n"); /* allow ET_EXEC only */ }
    // iterate program headers
    Elf64_Phdr* ph = (Elf64_Phdr*)(data + eh->e_phoff);
    for(int i=0;i<eh->e_phnum;i++){
        if(ph[i].p_type==1){ // PT_LOAD
            // allocate pages for segment (simple kmalloc)
            void* dest = kmalloc(ph[i].p_memsz + 0x1000);
            unsigned char* ds = (unsigned char*)dest;
            // zero mem
            for(size_t z=0; z<ph[i].p_memsz; z++) ds[z]=0;
            // copy file data
            for(size_t c=0; c<ph[i].p_filesz; c++) ds[c] = data[ph[i].p_offset + c];
        }
    }
    // jump to entry (note: assumes identity mapping)
    console_write_str("Jumping to ELF entry (flat)...\n");
    void (*entry)(void) = (void(*)(void)) (eh->e_entry);
    entry();
    return 0;
}
