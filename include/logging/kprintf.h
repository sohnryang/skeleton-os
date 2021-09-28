/*
 * kprintf.h -- implementation of kernel logging
 */

#pragma once

enum loglevel {
  DEBUG = 0,
  INFO,
  WARN,
  ERROR
};  // Log level DEBUG, INFO, WARN, ERROR.

// Logs a kernel message. Usage is similar to printf.
void kprintf(int loglevel, char *fmt, ...);
