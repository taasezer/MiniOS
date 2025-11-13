MiniOS v4 Ultra
================
This is a comprehensive, extensible prototype "MiniOS v4 Ultra". It contains assembly + C kernel
components, multiboot header, GDT/IDT/ISR scaffolding, PIC/PIT, VGA console, keyboard input,
a simple preemptive scheduler (PIT-driven), a RAM-disk, an ELF-flat-run stub, and a small shell.

Build & run (Linux/WSL):
  sudo apt install -y nasm build-essential grub-pc-bin xorriso qemu-system-x86
  make
  make run
