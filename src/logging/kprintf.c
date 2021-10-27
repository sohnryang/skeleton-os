#include <console/vga_terminal.h>
#include <libc/string.h>
#include <logging/kprintf.h>
#include <stdarg.h>

static char log_prefix(int loglevel) {
  switch (loglevel) {
    case DEBUG:
      return 'D';
      break;
    case INFO:
      return 'I';
      break;
    case WARN:
      return 'W';
      break;
    case ERROR:
      return 'E';
      break;
    default:
      return '?';
  }
}

void kprintf(int loglevel, char* fmt, ...) {
  term_put_char(log_prefix(loglevel));
  term_put_str("> ");

  va_list ap;
  va_start(ap, fmt);
  while (*fmt) {
    char ch = *fmt++;
    char* s;
    char numstr[12];
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
          kitoa(d, numstr);
          term_put_str(numstr);
          break;
        case 'X':
          term_put_str("0x");
          // fall through
        case 'x':
          d = va_arg(ap, int);
          kitoa_hex(d, numstr);
          term_put_str(numstr);
          break;
        case 'p':
          p = va_arg(ap, void*);
          kitoa_hex((int)p,
                    numstr);  // FIXME: assumes pointer size equals int size
          term_put_str("0x");
          term_put_str(numstr);
          break;
      }
    } else
      term_put_char(ch);
  }
}
