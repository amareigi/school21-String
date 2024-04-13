#include "s21_string.h"
// поиск подстроки в строке. Возвращает NULL||указатель на первое вхождение
// подстроки
char *s21_strstr(const char *strA, const char *strB) {
  const char *ptr = strA;
  if (*strB == '\0') return (char *)ptr;
  while (*ptr != '\0') {
    if (*ptr == *strB) {
      const char *a = ptr;
      const char *b = strB;
      while (*a == *b) {
        a++;
        b++;
        if (*b == '\0') return (char *)ptr;
      }
    }
    ptr++;
  }
  return s21_NULL;
}