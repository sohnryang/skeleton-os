#include <stddef.h>
#include <stdint.h>

#pragma once

enum vga_color {
  VGA_COLOR_BLACK = 0,
  VGA_COLOR_BLUE,
  VGA_COLOR_GREEN,
  VGA_COLOR_CYAN,
  VGA_COLOR_RED,
  VGA_COLOR_MAGENTA,
  VGA_COLOR_BROWN,
  VGA_COLOR_LIGHT_GRAY,
  VGA_COLOR_DARK_GRAY,
  VGA_COLOR_LIGHT_BLUE,
  VGA_COLOR_LIGHT_GREEN,
  VGA_COLOR_LIGHT_CYAN,
  VGA_COLOR_LIGHT_RED,
  VGA_COLOR_LIGHT_MAGENTA,
  VGA_COLOR_LIGHT_BROWN,
  VGA_COLOR_WHITE
};

extern size_t terminal_row, terminal_col;
extern uint8_t terminal_color;
extern uint16_t *terminal_buf;

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

void init_terminal();
void term_set_color(uint8_t color);
void term_put_entry(char ch, uint8_t color, size_t x, size_t y);
void term_put_char(char ch);
void term_put_str(const char *data);
