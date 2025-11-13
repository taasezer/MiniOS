NASM = nasm
CC = gcc
LD = ld
CFLAGS = -ffreestanding -O2 -nostdlib -fno-builtin -nostartfiles -mno-red-zone -m64
LDFLAGS = -T kernel/linker.ld -nostdlib

ASMS = boot/multiboot_header.asm kernel/_start.asm kernel/gdt.asm kernel/idt.asm kernel/isr_common.asm kernel/pic.asm kernel/pit.asm kernel/console.asm kernel/keyboard.asm kernel/context_switch.asm kernel/paging.asm
ASMO = $(ASMS:.asm=.o)

COBJS = lib/stdio.c kernel/heap/heap.c kernel/modules.c kernel/kb_map.c kernel/kb_buffer.c kernel/interrupts.c sched/scheduler.c shell/shell.c kernel/ramdisk.c kernel/elf_loader.c kernel/main.c

OBJS = multiboot.o $(ASMO) $(COBJS:.c=.o)

all: iso

%.o: %.asm
	$(NASM) -f elf64 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

multiboot.o: boot/multiboot_header.asm
	$(NASM) -f elf32 boot/multiboot_header.asm -o multiboot.o

kernel.elf: multiboot.o $(ASMO) $(COBJS:.c=.o) kernel/linker.ld
	$(LD) $(LDFLAGS) -o kernel.elf multiboot.o $(ASMO) $(COBJS:.c:.o)

iso: kernel.elf
	rm -rf iso || true
	mkdir -p iso/boot/grub
	cp kernel.elf iso/boot/kernel.elf
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o mini-os-v4-ultra.iso iso

run: iso
	qemu-system-x86_64 -cdrom mini-os-v4-ultra.iso -m 1536M -serial stdio -smp 2 -net none

clean:
	rm -f *.o */*.o */*/*.o kernel.elf mini-os-v4-ultra.iso
	rm -rf iso
