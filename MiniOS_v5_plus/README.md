MiniOS v5 - FINAL+ (ELF loader, paging, FPU-safe context switch, network demo skeleton)
====================================================================================
This release (v5) extends the previous prototype with:

  - ELF64 loader that parses ELF headers and maps PT_LOAD segments into memory then jumps to entry.
  - Paging: builds simple 4-level page tables using 2MB pages for identity mapping low memory and
    a higher-half mapping for kernel code region. CR3 is loaded (careful: tested in QEMU).
  - Page-fault handler that prints CR2 and error code to VGA console for debugging.
  - Context switch uses FXSAVE / FXRSTOR to preserve SSE/FPU state between tasks.
  - Network demo skeleton: a virtio-net driver scaffold and instructions on starting QEMU with
    a user-mode network backend. The driver is a stub showing where to plug virtio initialization.
    (Full TCP/IP stack is out of scope for a short prototype; see next steps in README.)

Build & run (Linux/WSL):
  sudo apt install -y nasm build-essential grub-pc-bin xorriso qemu-system-x86
  unzip MiniOS_v5.zip -d MiniOS_v5
  cd MiniOS_v5
  make
  make run

Notes:
 - This is a learning/prototyping system. Do not expect production-grade security or robustness.
 - The virtio-net driver is a scaffold: to test networking you'll need to run QEMU with a virtio-net device and further implement the virtio queue handling.
 - If you want, I will implement a simple minimal TCP echo client or integrate lwIP next.
