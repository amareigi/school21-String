#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_char = dest;
  const char *src_char = src;

  for (s21_size_t i = 0; i < n; ++i) {
    dest_char[i] = src_char[i];
  }
  return dest;
}
