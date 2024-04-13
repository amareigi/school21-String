#include "s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  const char *p = s21_NULL;
  for (s21_size_t i = 0; i < n; ++i) {
    if (c == *((const char *)arr + i)) {
      p = (const char *)arr + i;
      break;
    }
  }
  return (void *)p;
}
