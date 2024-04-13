#include "s21_string.h"

// memcmp - функция для сравнения массивчиков
/* возвращает:
0 - если массивы идентичны
иначе - если массивы отличаются */

int s21_memcmp(const void *array1, const void *array2, s21_size_t n) {
  const unsigned char *arr1, *arr2;
  arr1 = array1;
  arr2 = array2;
  int flag = 0;
  for (; n--; arr1++, arr2++) {
    if (*arr1 != *arr2) {
      flag = *arr1 - *arr2;
      return flag;
    }
  }
  return flag;
}
