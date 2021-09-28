#include <libc/string.h>
#include <stdbool.h>

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

void kitoa(int x, char* out) {
  char result[12] = {0};  // 10 digits max + sign + null termination
  int current = 0;
  int power = 1000000000;  // start from 10^9
  bool leading_zero = true;
  if (x < 0) {
    result[0] = '-';
    current++;
    x = -x;
  }
  while (power >= 1) {
    int digit = x / power % 10;
    if (leading_zero && digit != 0) leading_zero = false;
    if (!leading_zero) result[current++] = '0' + (char)digit;
    power /= 10;
  }
  if (current == 0) result[current++] = '0';
  kstrncpy(out, result, current + 1);
}

static const char* hexchar = "0123456789abcdef";

void kitoa_hex(int x, char* out) {
  char result[9] = {0};  // 8 digits max + null termination
  bool leading_zero = true;
  size_t current = 0;
  for (int i = 0; i < 8; ++i) {
    size_t digit = (x >> ((7 - i) * 4)) & 15;
    if (leading_zero && digit != 0) leading_zero = false;
    if (!leading_zero) result[current++] = hexchar[digit];
  }
  if (current == 0) result[current++] = '0';
  kstrncpy(out, result, current + 1);
}
