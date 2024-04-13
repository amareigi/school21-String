#include "string_suitecases.h"

START_TEST(strlen_1) {
  char *str[9] = {"Spurgerb"};
  ck_assert_uint_eq(s21_strlen(*str), strlen(*str));
}
END_TEST

START_TEST(strlen_2) {
  char str[9] = {'A', 'm', 'a', 'r', 'e', 'i', 'g', 'i', '\0'};
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[9] = {'\0', 'D', '0', 'r', 'e', 'e', 'g', '@'};
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[10] = {'F', 'i', 'r', '$', 't', '@', 'l', 'e', '\t', '\0'};
  size_t nine = 9;
  ck_assert_uint_eq(s21_strlen(str), nine);
}
END_TEST

START_TEST(strlen_5) {
  char str[28] = {"M@rselsh - our fifth ranger"};
  size_t nine = 27;
  ck_assert_uint_eq(s21_strlen(str), nine);
}
END_TEST

START_TEST(strlen_6) {
  char str1[] = "00000";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_7) {
  char str1[] = ".....";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_8) {
  char str1[] = "+_@$)@)(%*";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_9) {
  char str1[] = "\n";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_10) {
  char str1[] = " 0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_11) {
  char str1[] = "0 ";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_12) {
  char str1[] = "j ";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_13) {
  char str1[] = " k";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_14) {
  char str1[] = "";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_15) {
  char str1[] = "!";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_16) {
  char str1[] = "\'";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_17) {
  char str1[] = "\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_18) {
  char str1[] = "k\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_19) {
  char str1[] = "\0 0n";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_20) {
  char str1[] = "\n klj";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_21) {
  char str1[] = "\n\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_22) {
  char str1[] = "\n\0";
  char str2[] = "1/0";
  char str3[] = "  ";
  char str4[] = "hhh\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
  ck_assert_int_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

START_TEST(strlen_23) {
  char *str1 = "0123456789";
  char *str2 = "";
  char *str3 = "spurgerb";
  char *str4 = "one + two";

  ck_assert_msg(strlen(str1) == s21_strlen(str1), "1st strlen test failed");
  ck_assert_msg(strlen(str2) == s21_strlen(str2), "2st strlen test failed");
  ck_assert_msg(strlen(str3) == s21_strlen(str3), "3st strlen test failed");
  ck_assert_msg(strlen(str4) == s21_strlen(str4), "4st strlen test failed");
}
END_TEST

Suite *suite_s21_strlen(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strlen");
  tc = tcase_create("case_strlen");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);
  tcase_add_test(tc, strlen_8);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_11);
  tcase_add_test(tc, strlen_12);
  tcase_add_test(tc, strlen_13);
  tcase_add_test(tc, strlen_14);
  tcase_add_test(tc, strlen_15);
  tcase_add_test(tc, strlen_16);
  tcase_add_test(tc, strlen_17);
  tcase_add_test(tc, strlen_18);
  tcase_add_test(tc, strlen_19);
  tcase_add_test(tc, strlen_20);
  tcase_add_test(tc, strlen_21);
  tcase_add_test(tc, strlen_22);
  tcase_add_test(tc, strlen_23);

  suite_add_tcase(s, tc);
  return s;
}