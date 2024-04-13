#include "s21_string.h"

void *ltrim(char *src, const char *trim_chars) {
  s21_size_t i = 0;
  int index = 0;
  for (i = 0; i < s21_strlen(src); ++i) {
    int counter = 0;
    for (s21_size_t k = 0; k < s21_strlen(trim_chars); ++k) {
      char c = trim_chars[k];
      if (src[i] == c) {
        counter++;
        break;
      }
    }
    index += counter;
    if (counter == 0) {
      break;
    }
  }
  if (index > 0) {
    s21_size_t j = 0;
    for (j = 0; j < s21_strlen(src); j++) {
      src[j] = src[j + index];
    }
    src[j] = '\0';
  }

  return (void *)src;
}

void *rtrim(char *src, const char *trim_chars) {
  s21_size_t index = s21_strlen(src) - 1;

  for (int i = index; i >= 0; i--) {
    int counter = 0;
    for (s21_size_t k = 0; k < s21_strlen(trim_chars); ++k) {
      char c = trim_chars[k];
      if (src[i] == c) {
        counter++;
        break;
      }
    }

    index -= counter;
    if (counter == 0) {
      break;
    }
  }
  if (index < (s21_strlen(src) - 1)) {
    src[index + 1] = '\0';
  }
  return (void *)src;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed_src = s21_NULL;
  if (src == s21_NULL) {
    return (void *)trimmed_src;
  }

  trimmed_src = (char *)malloc((s21_strlen(src) + 1) * sizeof(char));
  s21_memcpy(trimmed_src, src, (s21_strlen(src) + 1));
  trimmed_src[s21_strlen(src)] = '\0';
  if (trim_chars != s21_NULL) {
    if (s21_strlen(trim_chars) > 0) {
      ltrim(trimmed_src, trim_chars);
      rtrim(trimmed_src, trim_chars);
    }
  }
  return (void *)trimmed_src;
}
