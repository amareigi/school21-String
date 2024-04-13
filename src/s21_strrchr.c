#include "s21_string.h"
// возвращает последнее вхождение символа в строку
char *s21_strrchr(const char *str, int sym) {
  if (sym == '\0' && *str == '\0') return (char *)str;
  const char *p = str + s21_strlen(str);
  while (p >= str) {
    if (*p == sym) {
      return (char *)p;
    }
    p--;
  }
  return s21_NULL;
}
