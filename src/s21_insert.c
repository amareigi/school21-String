#include "s21_string.h"
// вставляет строку str в строку src начиная с позиции start_index
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  const char *p_src = src;
  const char *s_str = str;
  char *end = s21_NULL;
  if (p_src && s_str && start_index <= s21_strlen(src)) {
    char *peach = calloc(s21_strlen(src) + s21_strlen(str) + 1, 1);
    end = peach;
    while ((start_index--) > 0) {
      *peach = *p_src;
      peach++;
      p_src++;
    }
    while (*s_str != '\0') {
      *peach = *s_str;
      peach++;
      s_str++;
    }
    while (*p_src != '\0') {
      *peach = *p_src;
      peach++;
      p_src++;
    }
    *peach = '\0';
  }
  return end;
}