#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <console/vga_terminal.h>

void kernel_main() {
  init_terminal();
  term_put_str("Hell world!\n");
}
