#include "string_suitecases.h"

START_TEST(strncmp_1) {
  char *str1 = "abcde";
  char *str2 = "abcde";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_2) {
  char *str1 = "abcde";
  char *str2 = "avcde";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_3) {
  char *str1 = "abmde";
  char *str2 = "abcde";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_4) {
  char *str1 = "abcde";
  char *str2 = "abcde";
  ck_assert_int_eq(s21_strncmp(str1, str2, 18), strncmp(str1, str2, 18));
}
END_TEST

START_TEST(strncmp_5) {
  char *str1 = "abcde";
  char *str2 = "abcdef";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(strncmp_6) {
  char *str1 = "abc";
  char *str2 = "abv";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_7) {
  char *str1 = "";
  char *str2 = "abcdef";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_8) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(strncmp_9) {
  char *str1 = "n";
  char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_10) {
  char *str1 = "abcde";
  char *str2 = "abcdg";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_11) {
  char *str1 = "abcde";
  char *str2 = "abcdg";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_12) {
  char *str1 = "ab  e";
  char *str2 = "abcdg";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_13) {
  char *str1 = "abcde";
  char *str2 = "ab \tcdg";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(strncmp_14) {
  char *str1 = "abcd\n";
  char *str2 = "abcd\n";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_15) {
  char *str1 = "abcde\n";
  char *str2 = "abcde\n";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_16) {
  char *str1 = "abcd\0";
  char *str2 = "abcde\n";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_17) {
  char *str1 = "ab\rd\0";
  char *str2 = "ab\rde\n";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(strncmp_18) {
  char *str1 = "!@#$%^&()[]";
  char *str2 = "!@#$%&*()[]";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(strncmp_19) {
  char *str1 = "    ";
  char *str2 = "    ";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_20) {
  char *str1 = "\t\t";
  char *str2 = "\t\t";
  ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(strncmp_21) {
  char *str1 = "spurgerb";
  char *str2 = "NULL";
  ck_assert_int_eq(s21_strncmp(str1, str2, 1), strncmp(str1, str2, 1));
}
END_TEST

Suite *suite_s21_strncmp() {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("s21_strncmp");

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);
  tcase_add_test(tc, strncmp_12);
  tcase_add_test(tc, strncmp_13);
  tcase_add_test(tc, strncmp_14);
  tcase_add_test(tc, strncmp_15);
  tcase_add_test(tc, strncmp_16);
  tcase_add_test(tc, strncmp_17);
  tcase_add_test(tc, strncmp_18);
  tcase_add_test(tc, strncmp_19);
  tcase_add_test(tc, strncmp_20);
  tcase_add_test(tc, strncmp_21);

  suite_add_tcase(s, tc);
  return s;
}