/*
 * vga_terminal.h -- VGA terminal output functions
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

#define VGA_FRAMEBUF_ADDR 0xb8000
#define VGA_FRAMEBUF_CMD_PORT 0x3d4
#define VGA_FRAMEBUF_DATA_PORT 0x3d5
#define VGA_HIGH_BYTE_CMD 14
#define VGA_LOW_BYTE_CMD 15
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

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

// Moves the cursor to specified location
void term_move_cursor(uint16_t pos);
