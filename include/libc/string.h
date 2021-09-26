/*
 * string.h -- string related functions
 */

#pragma once

#include <stddef.h>

size_t kstrlen(const char* s);        // Calculates the length of given string.
void kstrcpy(char* dest, char* src);  // Copies string in src to dest
void kstrncpy(char* dest, char* src,
              size_t n);       // Copies n characters from string in src to dest
void kitoa(int x, char* out);  // Converts int to string.
