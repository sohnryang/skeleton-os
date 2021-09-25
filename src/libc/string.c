#include <libc/string.h>

size_t kstrlen(const char* s) {
  int i;
  for (i = 0; s[i]; ++i)
    ;
  return i;
}
