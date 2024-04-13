#include "string_suitecases.h"

START_TEST(strncpy_1) {
  const char src[] = "Hello, World!";
  char dest_strncpy[20];
  char dest_s21_strncpy[20];
  size_t n = strlen(src) + 1;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_2) {
  const char src[] = "Hello, World!";
  char dest_strncpy[5];
  char dest_s21_strncpy[5];
  size_t n = 5;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_3) {
  const char src[] = "Hello,\nWorld!";
  char dest_strncpy[20];
  char dest_s21_strncpy[20];
  size_t n = 5;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_4) {
  const char src[] = "Hello\0World!";
  char dest_strncpy[20];
  char dest_s21_strncpy[20];
  size_t n = 5;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_5) {
  const char src[] = "HelloWorl\0d!";
  char dest_strncpy[20];
  char dest_s21_strncpy[20];
  size_t n = 0;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_6) {
  const char src[] = "";
  char dest_strncpy[20];
  char dest_s21_strncpy[20];
  size_t n = strlen(src) + 1;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_7) {
  const char src[] = "Hello, World!";
  char dest_strncpy[0];
  char dest_s21_strncpy[0];
  size_t n = 0;
  strncpy(dest_strncpy, src, n);
  s21_strncpy(dest_s21_strncpy, src, n);
  ck_assert_mem_eq(dest_strncpy, dest_s21_strncpy, n);
}
END_TEST

START_TEST(strncpy_8) {
  char str1[13] = "Hello, World!";
  char str2[3] = "Bye";
  size_t n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_9) {
  char str1[13] = "Hello,\nWorld!";
  char str2[3] = "Bye";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str1, str2, n));
}
END_TEST

START_TEST(strncpy_10) {
  char str1[] = "Hello,\nWorld!\0";
  char str2[] = "d\nef";
  char str3[] = "Hello,\nWorld!\0";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(strncpy_11) {
  char str1[] = "Hello,\nWorld!";
  char str2[] = "By\0e";
  char str3[] = "Hello,\nWorld!";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(strncpy_12) {
  char str1[9] = "";
  char str2[] = "Bye";
  char str3[9] = "";
  int n = 3;
  strncpy(str1, str2, n);
  s21_strncpy(str3, str2, n);
  ck_assert_str_eq(str1, str3);
}
END_TEST

START_TEST(strncpy_13) {
  char str1[] = "Hello,\nW\0rld!";
  char str2[] = "";
  char str3[] = "Hello,\nW\0rld!";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(strncpy_14) {
  char str1[9] = "";
  char str2[] = "Bye";
  char str3[9] = "";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(strncpy_15) {
  char str1[9] = "";
  char str2[] = "";
  char str3[9] = "";
  int n = 1;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

START_TEST(strncpy_16) {
  char str1[] = " ";
  char str2[] = " ";
  char str3[] = " ";
  int n = 0;
  ck_assert_str_eq(strncpy(str1, str2, n), s21_strncpy(str3, str2, n));
}
END_TEST

Suite *suite_s21_strncpy(void) {
  Suite *s_strncpy;
  TCase *tc_strncpy;
  s_strncpy = suite_create("s_strncpy");

  tc_strncpy = tcase_create("tc_strncpy");

  tcase_add_test(tc_strncpy, strncpy_1);
  tcase_add_test(tc_strncpy, strncpy_2);
  tcase_add_test(tc_strncpy, strncpy_3);
  tcase_add_test(tc_strncpy, strncpy_4);
  tcase_add_test(tc_strncpy, strncpy_5);
  tcase_add_test(tc_strncpy, strncpy_6);
  tcase_add_test(tc_strncpy, strncpy_7);
  tcase_add_test(tc_strncpy, strncpy_8);
  tcase_add_test(tc_strncpy, strncpy_9);
  tcase_add_test(tc_strncpy, strncpy_10);
  tcase_add_test(tc_strncpy, strncpy_11);
  tcase_add_test(tc_strncpy, strncpy_12);
  tcase_add_test(tc_strncpy, strncpy_13);
  tcase_add_test(tc_strncpy, strncpy_14);
  tcase_add_test(tc_strncpy, strncpy_15);
  tcase_add_test(tc_strncpy, strncpy_16);

  suite_add_tcase(s_strncpy, tc_strncpy);
  return s_strncpy;
}
