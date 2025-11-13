#include <stddef.h>
extern void register_file(struct file_entry*);
static const char prog_data[] = { 0xC3 };
static struct file_entry f1 = { "readme.txt", "MiniOS v4 Ultra sample file\n", 28 };
static struct file_entry f2 = { "prog.bin", (const char*)prog_data, sizeof(prog_data) };
void ramdisk_init(void){ register_file(&f1); register_file(&f2); }
