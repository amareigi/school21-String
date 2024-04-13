#include "s21_string.h"
#define UP (32)
// возвращает строку в нижнем регистре
void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str != s21_NULL) {
    char *new_str = calloc(s21_strlen(str) + 1, sizeof(char));
    res = new_str;
    while (*str != '\0') {
      if ((*str >= 'A') && (*str <= 'Z'))
        *new_str = *str + UP;
      else
        *new_str = *str;
      str++;
      new_str++;
    }
    *new_str = '\0';
  }
  return res;
}
