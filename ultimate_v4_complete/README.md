Ultimate Mini OS v4 - Complete (Prototype)
-----------------------------------------
This archive contains an advanced prototype OS kernel with:
- IRQ-driven PIT timer and keyboard
- basic preemptive scheduler switching between two kernel tasks
- ring-buffer keyboard input + shell supporting 'ls' and 'cat' on a tiny RAM-disk
- modular, readable source (assembly + C)
Build prerequisites: nasm, gcc, ld, grub-mkrescue, xorriso, qemu-system-x86_64
Build & run:
  sudo apt install nasm build-essential grub-pc-bin xorriso qemu-system-x86
  make
  make run
Notes:
- This is a prototype. Paging enabling is left safe (no CR3 switch) to keep GRUB environment stable.
- The scheduler context-switch is functional within the prototype and switches two kernel tasks that print messages.
