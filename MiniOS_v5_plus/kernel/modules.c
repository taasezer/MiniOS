#include <stddef.h>
struct module { const char* name; void (*init)(void); };
static struct module modules[16];
static int modcount=0;
void register_module(const char* name, void(*init)(void)){ if(modcount<16){ modules[modcount].name=name; modules[modcount].init=init; modcount++; } }
void modules_init(void){ for(int i=0;i<modcount;i++) if(modules[i].init) modules[i].init(); }
