#include "string_suitecases.h"

START_TEST(memset_1) {
  char src_memset[20];
  char src_s21_memset[20];
  int c = 0;
  size_t n = 20;
  memset(src_memset, c, n);
  s21_memset(src_s21_memset, c, n);
  ck_assert_mem_eq(src_memset, src_s21_memset, n);
}
END_TEST

START_TEST(memset_2) {
  char src_memset[20];
  char src_s21_memset[20];
  int c = 10000;
  size_t n = 20;
  memset(src_memset, c, n);
  s21_memset(src_s21_memset, c, n);
  ck_assert_mem_eq(src_memset, src_s21_memset, n);
}
END_TEST

START_TEST(memset_3) {
  char src_memset[20];
  char src_s21_memset[20];
  int c = 10000;
  size_t n = 10;
  memset(src_memset, c, n);
  s21_memset(src_s21_memset, c, n);
  ck_assert_mem_eq(src_memset, src_s21_memset, n);
}
END_TEST

START_TEST(memset_4) {
  char src_memset[3] = "abc";
  char src_s21_memset[3] = "abc";
  int c = 0;
  size_t n = 3;
  memset(src_memset, c, n);
  s21_memset(src_s21_memset, c, n);
  ck_assert_mem_eq(src_memset, src_s21_memset, n);
}
END_TEST

START_TEST(memset_5) {
  char src_memset[20];
  char src_s21_memset[20];
  int c = 0;
  size_t n = 0;
  memset(src_memset, c, n);
  s21_memset(src_s21_memset, c, n);
  ck_assert_mem_eq(src_memset, src_s21_memset, n);
}
END_TEST

START_TEST(memset_6) {
  char src[] = "Hello, World!";
  int c = 0;
  size_t n = strlen(src) + 1;
  char *memset_result = memset(src, c, n);
  char *s21_memset_result = s21_memset(src, c, n);
  ck_assert_ptr_eq(memset_result, s21_memset_result);
}
END_TEST

Suite *suite_s21_memset(void) {
  Suite *s_memset;
  TCase *tc_memset;
  s_memset = suite_create("s_memset");

  tc_memset = tcase_create("tc_memset");

  tcase_add_test(tc_memset, memset_1);
  tcase_add_test(tc_memset, memset_2);
  tcase_add_test(tc_memset, memset_3);
  tcase_add_test(tc_memset, memset_4);
  tcase_add_test(tc_memset, memset_5);
  tcase_add_test(tc_memset, memset_6);

  suite_add_tcase(s_memset, tc_memset);
  return s_memset;
}
