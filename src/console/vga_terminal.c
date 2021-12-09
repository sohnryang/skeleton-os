#include <console/vga_terminal.h>
#include <drivers/iobus.h>
#include <libc/string.h>
#include <stdint.h>

size_t terminal_row, terminal_col;
uint8_t terminal_color;
uint16_t *terminal_buf;

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
  return fg | (bg << 4);
}

static inline uint16_t vga_entry(unsigned char ch, uint8_t color) {
  return (uint16_t)ch | (uint16_t)color << 8;
}

static inline size_t pos_to_index(int x, int y) { return y * VGA_WIDTH + x; }

void init_terminal() {
  terminal_row = 0;
  terminal_col = 0;
  terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GRAY, VGA_COLOR_BLACK);
  terminal_buf = (uint16_t *)VGA_FRAMEBUF_ADDR;
  for (size_t y = 0; y < VGA_HEIGHT; ++y)
    for (size_t x = 0; x < VGA_WIDTH; ++x)
      terminal_buf[pos_to_index(x, y)] = vga_entry(' ', terminal_color);
  term_move_cursor(0);
}

void term_set_color(uint8_t color) { terminal_color = color; }

void term_put_entry(char ch, uint8_t color, size_t x, size_t y) {
  terminal_buf[pos_to_index(x, y)] = vga_entry(ch, color);
}

static inline void scroll_one_line() {
  terminal_row--;
  kmemmove(terminal_buf, terminal_buf + VGA_WIDTH,
           VGA_WIDTH * (VGA_HEIGHT - 1) * 16);
}

void term_put_char(char ch) {
  switch (ch) {
    case '\n':
      terminal_col = 0;
      if (++terminal_row == VGA_HEIGHT) scroll_one_line();
      break;
    default:
      term_put_entry(ch, terminal_color, terminal_col, terminal_row);
      if (++terminal_col == VGA_WIDTH) {
        terminal_col = 0;
        if (++terminal_row == VGA_HEIGHT) scroll_one_line();
      }
  }
  term_move_cursor(terminal_row * VGA_WIDTH + terminal_col);
}

void term_put_str(const char *data) {
  for (int i = 0; data[i]; ++i) term_put_char(data[i]);
}

void term_move_cursor(uint16_t pos) {
  outb(VGA_FRAMEBUF_CMD_PORT, VGA_HIGH_BYTE_CMD);
  outb(VGA_FRAMEBUF_DATA_PORT, (pos >> 8) & 0xff);
  outb(VGA_FRAMEBUF_CMD_PORT, VGA_LOW_BYTE_CMD);
  outb(VGA_FRAMEBUF_DATA_PORT, pos & 0xff);
}
