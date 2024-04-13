#include "string_suitecases.h"

START_TEST(strchr_1) {
  char *str[9] = {"Spurgerb"};
  ck_assert_str_eq(s21_strchr(*str, 'u'), strchr(*str, 'u'));
}
END_TEST

START_TEST(strchr_2) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_str_eq(s21_strchr(*str, '%'), strchr(*str, '%'));
}
END_TEST

START_TEST(strchr_3) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_str_ne(s21_strchr(*str, '!'), strchr(*str, '%'));
}
END_TEST

START_TEST(strchr_4) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_ptr_null(s21_strchr(*str, '7'));
}
END_TEST

START_TEST(strchr_5) {
  char *str[12] = {"!@#$%^&*(%)"};
  s21_size_t x = s21_strchr(*str, '$') - *str;
  size_t y = strchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
}
END_TEST

START_TEST(strchr_6) {
  char *str[12] = {"%%%%%%%%%%"};
  s21_size_t x = s21_strchr(*str, '$') - *str;
  size_t y = strchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
}
END_TEST

START_TEST(strchr_7) {
  char *str[12] = {"%%%%%%%%%%"};
  s21_size_t x = s21_strchr(*str, '$') - *str;
  size_t y = strchr(*str, '$') - *str;
  ck_assert_uint_eq(x - y, 0);
}
END_TEST

START_TEST(strchr_8) {
  char *str[12] = {"$S$S$s$S$S"};
  ck_assert_ptr_nonnull(s21_strchr(*str, 's'));
}
END_TEST

START_TEST(strchr_9) {
  char *str[12] = {"!@#$%^&*(%)"};
  ck_assert_mem_eq(s21_strchr(*str, ')'), strchr(*str, ')'), 1);
}
END_TEST

START_TEST(strchr_10) {
  char *str[12] = {"tests\0 tests\n test$"};
  ck_assert_ptr_null(s21_strchr(*str, '$'));
  ck_assert_ptr_null(strchr(*str, '$'));
  s21_size_t x = s21_strchr(*str, '$') - *str;
  size_t y = strchr(*str, '$') - *str;
  ck_assert_uint_eq(x, y);
  ck_assert_uint_eq(y - x, 0);
}
END_TEST

START_TEST(strchr_11) {
  char str[50] = "Hello, World!";
  ck_assert_msg(strcmp(s21_strchr("", '\0'), s21_strchr("", '\0')) == 0,
                "FAILURE!");
  ck_assert_msg(strcmp(s21_strchr(str, '\0'), strchr(str, '\0')) == 0,
                "FAILURE! ");
  ck_assert_msg(strcmp(s21_strchr(str, ','), strchr(str, ',')) == 0,
                "FAILURE! ");
  ck_assert_msg(s21_strchr(str, 'h') == strchr(str, 'h'), "FAILURE! ");
  ck_assert_msg(strcmp(s21_strchr(str, ' '), strchr(str, ' ')) == 0,
                "FAILURE!");
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

Suite *suite_s21_strchr(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strchr");
  tc = tcase_create("case_strchr");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);
  tcase_add_test(tc, strchr_11);

  suite_add_tcase(s, tc);
  return s;
}