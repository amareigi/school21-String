#include "s21_string.h"
//возвращает длину начального участка str, не содержащего символов строки
// symbols
s21_size_t s21_strcspn(const char *str, const char *symbols) {
  s21_size_t max_len_without_symbols = 0;
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_symbols = s21_strlen(symbols);

  int i = 0;
  int res = 0;

  while (i < (int)len_str) {
    for (int j = 0; j < (int)len_symbols; j++) {
      if (str[i] == symbols[j]) {
        res = 1;
        break;
      }
    }
    if (res == 0) {
      max_len_without_symbols++;
      i++;
    } else
      break;
  }

  return max_len_without_symbols;
}