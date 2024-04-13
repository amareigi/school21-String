#include "s21_string.h"
// сравнивает первые n символов в строках, возвращает 0, если они идентичны,
// число>0, если код 1-го различаюшегося символа в 1-ой строке больше кода
// символа 2-ой строки (на той же позиции)
// число<0, если ... меньше ...
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int i = 0;
  int res = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  while (i < (int)n && res == 0 && (i != (int)len1 || i != (int)len2)) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
    }
    i++;
  }
  return res;
}