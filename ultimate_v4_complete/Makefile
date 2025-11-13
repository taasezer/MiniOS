NASM = nasm
CC = gcc
LD = ld
CFLAGS = -ffreestanding -O2 -nostdlib -fno-builtin -nostartfiles -mno-red-zone -m64
LDFLAGS = -T kernel/linker.ld -nostdlib

ASMS = boot/multiboot_header.asm kernel/gdt.asm kernel/_start.asm kernel/idt.asm kernel/isr_common.asm kernel/pic.asm kernel/pit.asm kernel/keyboard.asm kernel/console.asm kernel/context_switch.asm kernel/paging.asm

ASMO = $(ASMS:.asm=.o)
COBJS = lib/stdio.c kernel/interrupts.c kernel/kb_map.c kernel/kb_buffer.c sched/scheduler.c fs/ramdisk.c fs/init_files.c shell/shell.c kernel/main.c

OBJS = multiboot.o $(ASMO) $(COBJS:.c=.o)

all: iso

%.o: %.asm
	$(NASM) -f elf64 $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

multiboot.o: boot/multiboot_header.asm
	$(NASM) -f elf32 boot/multiboot_header.asm -o multiboot.o

kernel.elf: multiboot.o $(ASMO) $(COBJS:.c=.o) kernel/linker.ld
	$(LD) $(LDFLAGS) -o kernel.elf multiboot.o $(ASMO) $(COBJS:.c=.o)

iso: kernel.elf
	rm -rf iso || true
	mkdir -p iso/boot/grub
	cp kernel.elf iso/boot/kernel.elf
	cp grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o ultimate-mini-os-v4-complete.iso iso

run: iso
	qemu-system-x86_64 -cdrom ultimate-mini-os-v4-complete.iso -m 1536M -serial stdio -smp 2 -net none

clean:
	rm -f *.o */*.o */*/*.o kernel.elf ultimate-mini-os-v4-complete.iso
	rm -rf iso
