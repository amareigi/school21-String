#include "s21_string.h"

void *s21_memset(void *src, int c, s21_size_t n) {
  char *src_char = src;

  for (s21_size_t i = 0; i < n; ++i) {
    src_char[i] = c;
  }
  return src;
}
