#include "s21_string.h"

// ищет первое вхождение символа из массива символов в строке
char *s21_strpbrk(const char *str1, const char *str2) {
  char *src_char = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str1); ++i) {
    for (s21_size_t j = 0; j < s21_strlen(str2); ++j) {
      char c = str2[j];
      if (str1[i] == c) {
        src_char = (char *)&str1[i];
        return src_char;
      }
    }
  }
  return s21_NULL;
}
