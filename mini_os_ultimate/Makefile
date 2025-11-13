\
    NASM = nasm
    CC = gcc
    LD = ld
    CFLAGS = -ffreestanding -O2 -nostdlib -fno-builtin -nostartfiles -mno-red-zone -m64
    LDFLAGS = -T kernel/linker.ld -nostdlib

    OBJS = multiboot.o start.o gdt.o idt.o isr_common.o paging.o pit.o keyboard.o vga.o \
           scheduler.o heap.o stdio.o shell.o main.o

    all: iso

    multiboot.o: boot/multiboot_header.asm
    \t$(NASM) -f elf32 boot/multiboot_header.asm -o multiboot.o

    start.o: kernel/_start.asm
    \t$(NASM) -f elf64 kernel/_start.asm -o start.o

    gdt.o: kernel/gdt.asm
    \t$(NASM) -f elf64 kernel/gdt.asm -o gdt.o

    idt.o: kernel/idt.asm
    \t$(NASM) -f elf64 kernel/idt.asm -o idt.o

    isr_common.o: kernel/isr_common.asm
    \t$(NASM) -f elf64 kernel/isr_common.asm -o isr_common.o

    paging.o: kernel/paging.asm
    \t$(NASM) -f elf64 kernel/paging.asm -o paging.o

    pit.o: kernel/interrupts/pit.asm
    \t$(NASM) -f elf64 kernel/interrupts/pit.asm -o pit.o

    keyboard.o: kernel/keyboard/keyboard.asm
    \t$(NASM) -f elf64 kernel/keyboard/keyboard.asm -o keyboard.o

    vga.o: kernel/console/vga.asm
    \t$(NASM) -f elf64 kernel/console/vga.asm -o vga.o

    scheduler.o: kernel/scheduler/scheduler.c
    \t$(CC) $(CFLAGS) -c kernel/scheduler/scheduler.c -o scheduler.o

    heap.o: kernel/heap/heap.c
    \t$(CC) $(CFLAGS) -c kernel/heap/heap.c -o heap.o

    stdio.o: lib/stdio.c
    \t$(CC) $(CFLAGS) -c lib/stdio.c -o stdio.o

    shell.o: shell/shell.c
    \t$(CC) $(CFLAGS) -c shell/shell.c -o shell.o

    main.o: kernel/main.c
    \t$(CC) $(CFLAGS) -c kernel/main.c -o main.o

    kernel.elf: $(OBJS)
    \t$(LD) $(LDFLAGS) -o kernel.elf $(OBJS)

    iso: kernel.elf
    \trm -rf iso || true
    \tmkdir -p iso/boot/grub
    \tcp kernel.elf iso/boot/kernel.elf
    \tcp grub.cfg iso/boot/grub/grub.cfg
    \tgrub-mkrescue -o ultimate-mini-os.iso iso

    run: iso
    \tqemu-system-x86_64 -cdrom ultimate-mini-os.iso -m 1024M -serial stdio -smp 2

    clean:
    \trm -f *.o *.elf *.iso
    \trm -rf iso
