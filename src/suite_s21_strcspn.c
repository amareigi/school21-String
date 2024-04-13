#include "string_suitecases.h"

START_TEST(strcspn_1) {
  ck_assert_uint_eq(s21_strcspn("abcde", "abcde"), strcspn("abcde", "abcde"));
}
END_TEST

START_TEST(strcspn_2) {
  ck_assert_uint_eq(s21_strcspn("abcde", "de"), strcspn("abcde", "de"));
}
END_TEST

START_TEST(strcspn_3) {
  ck_assert_uint_eq(s21_strcspn("abcde", ""), strcspn("abcde", ""));
}
END_TEST

START_TEST(strcspn_4) {
  ck_assert_uint_eq(s21_strcspn("abcde", "12"), strcspn("abcde", "12"));
}
END_TEST

START_TEST(strcspn_5) {
  char test1[] = "0123456789";
  char test2[] = "9876";
  char test3[] = "LOST: 4-8-15-16-23-42";
  char test4[] = "1234567890";
  char test5[] = "0/";
  char test6[] = "%%\\#";
  char test7[] = " ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST

START_TEST(strcspn_6) {
  ck_assert_uint_eq(s21_strcspn("abcde", "c d"), strcspn("abcde", "c d"));
}
END_TEST

Suite *suite_s21_strcspn() {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("s21_strcspn");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);

  suite_add_tcase(s, tc);
  return s;
}