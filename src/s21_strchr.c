#include "s21_string.h"
// возвращает первое вхождение символа в строку
char *s21_strchr(const char *str, int sym) {
  if (!sym) return "";
  const char *p = str;
  while (*p) {
    if (*p == sym) {
      return (char *)p;
    }
    p++;
  }
  return s21_NULL;
}
