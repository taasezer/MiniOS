#include <stddef.h>
struct file_entry { const char* name; const char* data; size_t size; };
static struct file_entry* files[16];
static int fcount = 0;
void register_file(struct file_entry* f){ if(fcount<16) files[fcount++] = f; }
struct file_entry* ramdisk_find(const char* name){ for(int i=0;i<fcount;i++){ const char* a=files[i]->name; const char* b=name; int eq=1; for(; *a||*b; a++,b++){ if(*a!=*b){ eq=0; break; } } if(eq) return files[i]; } return 0; }
int ramdisk_ls(char* out,int max){ int pos=0; for(int i=0;i<fcount;i++){ const char* n=files[i]->name; while(*n && pos<max-1) out[pos++]=*n++; if(pos<max-1) out[pos++]='\n'; } if(pos<max) out[pos]=0; return pos; }
int ramdisk_cat(const char* name,char* out,int max){ struct file_entry* f=ramdisk_find(name); if(!f) return -1; int tocopy=(f->size<(size_t)(max-1))?f->size:(max-1); for(int i=0;i<tocopy;i++) out[i]=f->data[i]; out[tocopy]=0; return tocopy; }
