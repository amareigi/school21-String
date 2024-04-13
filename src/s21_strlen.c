#include "s21_string.h"
// подсчитывает все знаки, кроме нуля
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;

  const char *p = str;

  while (*p != '\0') {
    p++;
    i++;
  }

  return i;
}
