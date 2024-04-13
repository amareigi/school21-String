#include "string_suitecases.h"

START_TEST(strrchr_1) {
  char *str[9] = {"Spurgerb"};
  ck_assert_str_eq(s21_strrchr(*str, 'u'), strrchr(*str, 'u'));
}
END_TEST

START_TEST(strrchr_2) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_str_eq(s21_strrchr(*str, '%'), strrchr(*str, '%'));
}
END_TEST

START_TEST(strrchr_3) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_str_ne(s21_strrchr(*str, '!'), strrchr(*str, '%'));
}
END_TEST

START_TEST(strrchr_4) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_ptr_null(s21_strrchr(*str, '7'));
}
END_TEST

START_TEST(strrchr_5) {
  char *str[12] = {"!@#$%^&*(%)"};
  s21_size_t x = s21_strrchr(*str, '$') - *str;
  size_t y = strrchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
}
END_TEST

START_TEST(strrchr_6) {
  char *str[12] = {"%%%%%%%%%%"};
  s21_size_t x = s21_strrchr(*str, '$') - *str;
  size_t y = strrchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
}
END_TEST

START_TEST(strrchr_7) {
  char *str[12] = {"%%%%%%%%%%"};
  s21_size_t x = s21_strrchr(*str, '$') - *str;
  size_t y = strrchr(*str, '$') - *str;
  ck_assert_uint_eq(x - y, 0);
}
END_TEST

START_TEST(strrchr_8) {
  char *str[12] = {"$S$S$s$S$S"};
  ck_assert_ptr_nonnull(s21_strrchr(*str, 's'));
}
END_TEST

START_TEST(strrchr_9) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_mem_eq(s21_strrchr(*str, ')'), strrchr(*str, ')'), 1);
}
END_TEST

START_TEST(strrchr_10) {
  char *str[12] = {"tests\0 tests\n test$"};
  ck_assert_ptr_null(s21_strrchr(*str, '$'));
  ck_assert_ptr_null(strrchr(*str, '$'));
  s21_size_t x = s21_strrchr(*str, '$') - *str;
  size_t y = strrchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
  ck_assert_uint_eq(y - x, 0);
}
END_TEST

START_TEST(strrchr_11) {
  char *str[12] = {""};
  ck_assert_str_eq(s21_strrchr(*str, '\0'), strrchr(*str, '\0'));
  ck_assert_ptr_null(s21_strrchr(*str, 'g'));
  ck_assert_ptr_null(strrchr(*str, 'g'));
}
END_TEST

START_TEST(strrchr_12) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

START_TEST(strrchr_13) {
  char *s1 = "School-21";
  char *s2 = "";
  char *s3 = "spurgerb";

  ck_assert_msg(s21_strrchr(s1, 's') == strrchr(s1, 's'),
                "1st strrchr test failed");
  ck_assert_msg(s21_strrchr(s1, 'p') == strrchr(s1, 'p'),
                "2nd strrchr test failed");
  ck_assert_msg(s21_strrchr(s2, 'r') == strrchr(s2, 'r'),
                "3rd strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, ' ') == strrchr(s3, ' '),
                "4rth strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, 'b') == strrchr(s3, 'b'),
                "5th strrchr test failed");
}
END_TEST

START_TEST(strrchr_14) {
  char *str[9] = {"Spurgerb"};
  ck_assert_str_eq(s21_strrchr(*str, 'u'), strrchr(*str, 'u'));
}
END_TEST

Suite *suite_s21_strrchr() {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("s21_strrchr");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);
  tcase_add_test(tc, strrchr_11);
  tcase_add_test(tc, strrchr_12);
  tcase_add_test(tc, strrchr_13);
  tcase_add_test(tc, strrchr_14);

  suite_add_tcase(s, tc);
  return s;
}