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

void kstrncpy(char* dest, char* src, size_t n) {
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; ++i) dest[i] = src[i];
  for (; i < n; ++i) dest[i] = '\0';
}
