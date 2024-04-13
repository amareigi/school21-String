#include "s21_string.h"

/*копирует строки из src в dest с ограничением длины*/

char *s21_strncpy(char *destination, const char *source, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    destination[i] = source[i];
  }

  return destination;
}
