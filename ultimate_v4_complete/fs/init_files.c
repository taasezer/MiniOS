#include <stddef.h>
extern void register_file(struct file_entry*);
static struct file_entry f1 = { "readme.txt", "Ultimate V4 complete sample file\n", 30 };
void ramdisk_init(void){ register_file(&f1); }
