#include "string_suitecases.h"

START_TEST(memcmp_1) {
  char *str1 = "Hello, World!";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmp_2) {
  char *str1 = "Hello, World!";
  char *str2 = "Goodbye, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 15), memcmp(str1, str2, 15));
}
END_TEST

START_TEST(memcmp_3) {
  char *str1 = "Hello, Peer!";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 14), memcmp(str1, str2, 14));
}
END_TEST

START_TEST(memcmp_4) {
  char *str1 = "";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmp_5) {
  char *str1 = "Hello, World!";
  char *str2 = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmp_6) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(memcmp_7) {
  char *str1 = "Hell0, W0rld!";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 13), memcmp(str1, str2, 13));
}
END_TEST

START_TEST(memcmp_8) {
  char *str1 = "Hello, World!";
  char *str2 = "Hello,\tWorld!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(memcmp_9) {
  char *str1 = "Hello,\nWorld!";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(memcmp_10) {
  char *str1 = "Hello, World!\n";
  char *str2 = "Hello, World!\n";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(memcmp_11) {
  char *str1 = "Hello, World!\0";
  char *str2 = "Hello, World!\n";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(memcmp_12) {
  char *str1 = "Hello,\rWorld!\n\0";
  char *str2 = "Hello, World!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

START_TEST(memcmp_13) {
  char *str1 = "!@#$%^&()[]";
  char *str2 = "!@#$%&*()[]";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(memcmp_14) {
  char *str1 = "    ";
  char *str2 = "    ";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

START_TEST(memcmp_15) {
  char *str1 = "\t\t";
  char *str2 = "\t\t";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

START_TEST(memcmp_16) {
  char *str1 = "NULL";
  char *str2 = "NULL";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
}
END_TEST

START_TEST(memcmp_17) {
  char *str1 = "Hello, World!";
  char *str2 = "NULL";
  ck_assert_int_eq(s21_memcmp(str1, str2, 1), memcmp(str1, str2, 1));
}
END_TEST

Suite *suite_s21_memcmp() {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("s21_memcmp");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);
  tcase_add_test(tc, memcmp_13);
  tcase_add_test(tc, memcmp_14);
  tcase_add_test(tc, memcmp_15);
  tcase_add_test(tc, memcmp_16);
  tcase_add_test(tc, memcmp_17);

  suite_add_tcase(s, tc);
  return s;
}