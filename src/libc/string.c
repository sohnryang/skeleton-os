#include <libc/string.h>

size_t kstrlen(const char* s) {
  size_t i;
  for (i = 0; s[i]; ++i)
    ;
  return i;
}
