#include <console/vga_terminal.h>
#include <logging/kprintf.h>
#include <stdarg.h>

void kprintf(int loglevel, const char* fmt, ...) {
  term_put_str("> ");

  va_list ap;
  va_start(ap, fmt);
  while (*fmt) {
    char ch = *fmt++;
    char* s;
    char c;
    int d;
    void* p;
    if (ch == '%') {
      switch (*fmt++) {
        case '%':
          term_put_char('%');
          break;
        case 'c':
          c = (char)va_arg(ap, int);
          term_put_char(c);
          break;
        case 's':
          s = va_arg(ap, char*);
          term_put_str(s);
          break;
        case 'd':
          d = va_arg(ap, int);
          break;
        case 'p':
          p = va_arg(ap, void*);
          break;
      }
    }
  }
}
