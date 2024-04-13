#include "s21_string.h"
// объединяет строки, возвращает указатель на объединенную строку
char *s21_strncat(char *dest, const char *app, s21_size_t n) {
  char *p = dest;
  while (*p != '\0') {
    p++;
  }
  while (*app != '\0' && n > 0) {
    *p = *app;
    p++;
    app++;
    n--;
  }
  *p = '\0';
  return dest;
}