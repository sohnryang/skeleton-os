#include <libc/string.h>

size_t kstrlen(const char* s) {
  size_t i;
  for (i = 0; s[i]; ++i)
    ;
  return i;
}

void kstrcpy(char* dest, char* src) {
  for (size_t i = 0; src[i]; ++i) dest[i] = src[i];
}
