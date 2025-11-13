#include <stdint.h>
extern char _heap_start, _heap_end;
static uintptr_t heap_ptr;
void heap_init(void){ heap_ptr = (uintptr_t)&_heap_start; }
void* kmalloc(size_t n){ uintptr_t p = heap_ptr; heap_ptr = (heap_ptr + ((n+0xFFF)&~0xFFF)); return (void*)p; }
void kfree(void* p){ (void)p; }
