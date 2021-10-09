#include <console/vga_terminal.h>
#include <logging/kprintf.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void kernel_main() {
  init_terminal();
  kprintf(INFO, "Welcome to skeletonOS %s!\n", "0.0.0");
}
