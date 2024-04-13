#include "s21_string.h"

char *strtok_back(char *str, const char *sep, char **last) {
  char *res;
  if (str == s21_NULL) str = *last;
  if (str == s21_NULL) return s21_NULL;

  while (*str != '\0' && s21_strchr(sep, *str) != s21_NULL) {
    ++str;
  }

  if (*str == '\0') return s21_NULL;
  res = str;
  str = s21_strpbrk(res, sep);

  if (str != s21_NULL) {
    *str = '\0';
    *last = str + 1;
  } else {
    *last = s21_NULL;
  }
  return res;
}

char *s21_strtok(char *str, const char *sep) {
  static char *last = s21_NULL;

  return strtok_back(str, sep, &last);
}
