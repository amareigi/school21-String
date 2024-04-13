#include "string_suitecases.h"

START_TEST(insert_1) {
  char *src = "Hello. Is it me you're looking for?";
  char *str = " world";
  char *ins = "Hello world. Is it me you're looking for?";
  char *new_str = s21_insert(src, str, 5);
  ck_assert_str_eq(new_str, ins);
  free(new_str);
}
END_TEST

START_TEST(insert_2) {
  char *src = "Hello\n. Is it me you're looking for?";
  char *str = " world";
  char *ins = "Hello world\n. Is it me you're looking for?";
  char *new_str = s21_insert(src, str, 5);
  ck_assert_str_eq(new_str, ins);
  free(new_str);
}
END_TEST

START_TEST(insert_3) {
  char *src = "Hello. Is it me you're looking for?";
  char *str = "";
  char *ins = "Hello. Is it me you're looking for?";
  char *new_str = s21_insert(src, str, 5);
  ck_assert_str_eq(new_str, ins);
  free(new_str);
}
END_TEST

START_TEST(insert_4) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }
}
END_TEST

START_TEST(insert_5) {
  char *src = "Hello!";
  char *new_str = s21_insert(src, "", 15);
  ck_assert(new_str == NULL);
  free(new_str);
}
END_TEST

START_TEST(insert_6) {
  char *new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }
}
END_TEST

START_TEST(insert_7) {
  char *new_str = s21_insert("\ta\ta\ta", " !!!!!", 5);
  ck_assert_str_eq(new_str, "\ta\ta\t !!!!!a");
  free(new_str);
}
END_TEST

START_TEST(insert_8) {
  char *new_str = s21_insert("Hello!", ", world!!", 25);
  ck_assert(new_str == s21_NULL);
  free(new_str);
}
END_TEST

START_TEST(insert_9) {
  char *new_str = s21_insert("", "", 0);
  ck_assert_str_eq(new_str, "");
  free(new_str);
}
END_TEST

START_TEST(insert_10) {
  char *src = "";
  char *str = "";
  s21_size_t index = 100;
  char *expected = NULL;
  char *new_str = s21_insert(src, str, index);
  ck_assert_ptr_eq(new_str, expected);
  if (new_str) free(new_str);
}
END_TEST

START_TEST(insert_11) {
  char *new_str = s21_insert("lo", "hel", 0);
  ck_assert_str_eq(new_str, "hello");
  free(new_str);
}
END_TEST

START_TEST(insert_12) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 6);
  ck_assert_str_eq(new_str, "Hello!, world");
  free(new_str);
}
END_TEST

START_TEST(insert_13) {
  char *src = "Hello!";
  char *new_str = s21_insert("", src, 15);
  ck_assert(new_str == NULL);
  free(new_str);
}
END_TEST

START_TEST(insert_14) {
  char *new_str = s21_insert("\n", " !!!!!", -1);
  ck_assert(new_str == NULL);
  free(new_str);
}
END_TEST

START_TEST(insert_15) {
  char *src = NULL;
  char *str = NULL;
  char *new_str = s21_insert(src, str, 0);
  if (new_str) {
    ck_assert(new_str == NULL);
    free(new_str);
  }
}
END_TEST

START_TEST(insert_16) {
  char *src = NULL;
  char *str = "vbn";
  char *new_str = s21_insert(src, str, 0);
  if (new_str) {
    ck_assert(new_str == NULL);
    free(new_str);
  }
}
END_TEST

START_TEST(insert_17) {
  char *src = "vbn";
  char *str = NULL;
  char *new_str = s21_insert(src, str, 0);
  if (new_str) {
    ck_assert(new_str == NULL);
    free(new_str);
  }
}
END_TEST

Suite *suite_s21_insert() {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("s21_insert");
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);
  tcase_add_test(tc, insert_9);
  tcase_add_test(tc, insert_10);
  tcase_add_test(tc, insert_11);
  tcase_add_test(tc, insert_12);
  tcase_add_test(tc, insert_13);
  tcase_add_test(tc, insert_14);
  tcase_add_test(tc, insert_15);
  tcase_add_test(tc, insert_16);
  tcase_add_test(tc, insert_17);

  suite_add_tcase(s, tc);
  return s;
}