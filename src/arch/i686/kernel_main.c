#include <console/vga_terminal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void kernel_main() {
  init_terminal();
  term_put_str("Hell world!\n");
}
