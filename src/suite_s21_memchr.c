#include "string_suitecases.h"

START_TEST(memchr_1) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str1[] = "abc";
  int c = 'b';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str1[] = "abc";
  int c = 'c';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str1[] = "abc";
  int c = 'b';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str1[] = "abc";
  int c = 'a';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_10) {
  char str1[] = "abc";
  int c = 'd';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_11) {
  char str1[] = "";
  int c = 'd';
  size_t n = 0;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_12) {
  char str1[] = "abc";
  int c = '\0';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_13) {
  char *str1 = "";
  int c = '\0';
  size_t n = 4;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_14) {
  char str1[] = " ";
  int c = 'd';
  size_t n = 1;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_15) {
  char str1[] = "abcabc";
  int c = 'b';
  size_t n = 6;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_16) {
  char str1[] = "abcabc";
  int c = 'b';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_17) {
  char str1[] = "abc\nabc";
  int c = 'a';
  size_t n = 7;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_18) {
  char str1[] = "abc\nabc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_19) {
  char str1[] = "abc\0abc";
  int c = 'a';
  size_t n = 7;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_20) {
  char str1[] = "abc\0abc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_21) {
  char str1[] = "\0abcabc";
  int c = 'a';
  size_t n = 7;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_22) {
  char str1[] = "\0abcabc";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_23) {
  char str1[] = "abcabc\0";
  int c = 'a';
  size_t n = 7;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

START_TEST(memchr_24) {
  char str1[] = "abcabc\0";
  int c = 'a';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str1, c, n), s21_memchr(str1, c, n));
}
END_TEST

Suite *suite_s21_memchr(void) {
  Suite *s_memchr;
  TCase *tc_memchr;
  s_memchr = suite_create("s_memchr");

  tc_memchr = tcase_create("tc_memchr");

  tcase_add_test(tc_memchr, memchr_1);
  tcase_add_test(tc_memchr, memchr_2);
  tcase_add_test(tc_memchr, memchr_3);
  tcase_add_test(tc_memchr, memchr_4);
  tcase_add_test(tc_memchr, memchr_5);
  tcase_add_test(tc_memchr, memchr_6);
  tcase_add_test(tc_memchr, memchr_7);
  tcase_add_test(tc_memchr, memchr_8);
  tcase_add_test(tc_memchr, memchr_9);
  tcase_add_test(tc_memchr, memchr_10);
  tcase_add_test(tc_memchr, memchr_11);
  tcase_add_test(tc_memchr, memchr_12);
  tcase_add_test(tc_memchr, memchr_13);
  tcase_add_test(tc_memchr, memchr_14);
  tcase_add_test(tc_memchr, memchr_15);
  tcase_add_test(tc_memchr, memchr_16);
  tcase_add_test(tc_memchr, memchr_17);
  tcase_add_test(tc_memchr, memchr_18);
  tcase_add_test(tc_memchr, memchr_19);
  tcase_add_test(tc_memchr, memchr_20);
  tcase_add_test(tc_memchr, memchr_21);
  tcase_add_test(tc_memchr, memchr_22);
  tcase_add_test(tc_memchr, memchr_23);
  tcase_add_test(tc_memchr, memchr_24);

  suite_add_tcase(s_memchr, tc_memchr);
  return s_memchr;
}
