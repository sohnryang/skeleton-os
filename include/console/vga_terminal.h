/*
 * vga_terminal.h -- VGA terminal output functions
 */

#include <stddef.h>
#include <stdint.h>

#pragma once

enum vga_color {  // VGA color codes
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

extern size_t terminal_row, terminal_col;  // current locatio of cursor
extern uint8_t terminal_color;  // current background, foreground color of texts
                                // being printed
extern uint16_t *terminal_buf;  // terminal buffer.

static const size_t VGA_WIDTH = 80;   // VGA terminal width
static const size_t VGA_HEIGHT = 25;  // VGA terminal height

// Initializes the terminal output by setting terminal_* variables
void init_terminal();

// Sets color of texts being printed
void term_set_color(uint8_t color);

// Puts an entry to VGA terminal. An entry consists of char, color code, and
// location
void term_put_entry(char ch, uint8_t color, size_t x, size_t y);

// Puts a character to current cursor location, in colors set by term_set_color
void term_put_char(char ch);

// Puts a string to VGA terminal
void term_put_str(const char *data);