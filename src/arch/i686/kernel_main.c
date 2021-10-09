#include <console/vga_terminal.h>
#include <logging/kprintf.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void kernel_main() {
  init_terminal();
  kprintf(INFO, "Welcome to skeletonOS %s!\n", "0.0.0");
  kprintf(DEBUG, "Hell world\n");
  kprintf(DEBUG, "%d %x %c\n", 42, 0xdeadbeef, '?');
  int x = 0;
  int* ptr = &x;
  kprintf(DEBUG, "Pointer to x: %p\n", ptr);
}
