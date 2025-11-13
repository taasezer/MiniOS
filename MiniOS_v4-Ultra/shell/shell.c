#include <stdint.h>
extern void console_write_str(const char*);
extern int kb_buffer_pop_nonblock(void);
extern int ramdisk_ls(char*, int);
extern int ramdisk_cat(const char*, char*, int);
extern int elf_run(const char*);
void shell_main_c(void){
    console_write_str("\nMiniOS Shell v4 Ultra\n> ");
    char buf[128]; int idx=0; char tmp[512];
    while(1){
        int c = kb_buffer_pop_nonblock();
        if(c==0){ asm volatile("hlt"); continue; }
        if(c==10){ buf[idx]=0; if(idx>0){ if(strcmp(buf,"ls")==0){ int n=ramdisk_ls(tmp,512); tmp[n]=0; console_write_str(tmp);} else if(strncmp(buf,"cat ",4)==0){ ramdisk_cat(buf+4,tmp,512); console_write_str(tmp);} else if(strncmp(buf,"run ",4)==0){ elf_run(buf+4); } else { console_write_str("Unknown\n"); } } idx=0; console_write_str("\n> "); continue; }
        if(c==8){ if(idx>0){ idx--; console_write_str("\b \b"); } continue; }
        buf[idx++]=(char)c;
        char s[2]={(char)c,0}; console_write_str(s);
    }
}
int strcmp(const char* a,const char* b){ for(; *a||*b; a++,b++){ if(*a!=*b) return (*a)-(*b); } return 0; }
int strncmp(const char* a,const char* b,int n){ for(int i=0;i<n;i++){ if(a[i]!=b[i]) return a[i]-b[i]; if(a[i]==0) return 0; } return 0; }
