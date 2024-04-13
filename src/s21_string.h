#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#include "s21_string.h"

typedef struct config {
  bool is_negative;
  bool plus;
  bool minus;
  bool hash;
  bool space;
  bool zero;
  bool dzero;  //для %f отдельный, так как там точность по другому работает
  bool dot;
  bool set_accuracy;
  bool up_case;
  bool is_nan;
  bool is_inf;
  bool error_digit;
  bool format_error;
  char length;
  int place_for_sign;
  int number_base;
  int width;
  int accuracy;
} config;

#define S21_INF (1.0 / 0.0)
#define S21_NINF (-1.0 / 0.0)
#define s21_size_t unsigned long int
#define s21_NULL ((void *)0)

void *s21_memchr(const void *arr, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *app, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int sym);
char *s21_strerror(int errnum);
void *s21_memset(void *src, int c, s21_size_t n);
char *s21_strrchr(const char *str, int sym);
char *s21_strstr(const char *strA, const char *strB);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
s21_size_t s21_strcspn(const char *str, const char *symbols);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n);
int s21_sprintf(char *str, const char *format, ...);
char *s21_strtok(char *arr, const char *sep);
char *strtok_back(char *str, const char *sep, char **last);

#endif
