#include "string_suitecases.h"

START_TEST(memcpy_1) {
  const char src[] = "Hello, World!";
  char dest_memcpy[20];
  char dest_s21_memcpy[20];
  size_t n = strlen(src) + 1;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_2) {
  const char src[] = "Hello, World!";
  char dest_memcpy[5];
  char dest_s21_memcpy[5];
  size_t n = 5;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_3) {
  const char src[] = "Hello, World!";
  char dest_memcpy[20];
  char dest_s21_memcpy[20];
  size_t n = 5;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_4) {
  const char src[] = "Hello\0World!";
  char dest_memcpy[20];
  char dest_s21_memcpy[20];
  size_t n = 5;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_5) {
  const char src[] = "Hello\0World!";
  char dest_memcpy[20];
  char dest_s21_memcpy[20];
  size_t n = 0;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_6) {
  const char src[] = "";
  char dest_memcpy[20];
  char dest_s21_memcpy[20];
  size_t n = strlen(src) + 1;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_7) {
  const char src[] = "Hello, World!";
  char dest_memcpy[0];
  char dest_s21_memcpy[0];
  size_t n = 0;
  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_8) {
  int src[] = {11, 12, 13, 14, 15};
  int dest_memcpy[5];
  int dest_s21_memcpy[5];
  size_t n = sizeof(src);

  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_9) {
  int src[] = {111, 112, 113, 114, 115};
  int dest_memcpy[2];
  int dest_s21_memcpy[2];
  size_t n = 2;

  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_10) {
  int src[] = {1111, 1112, 1113, 1114, 1115};
  int dest_memcpy[10];
  int dest_s21_memcpy[10];
  size_t n = sizeof(src);

  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_11) {
  int src[] = {11111, 11112, 11113, 11114, 11115};
  int dest_memcpy[5];
  int dest_s21_memcpy[5];
  size_t n = 3;

  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_12) {
  int src[] = {111111, 111112, 111113, 111114, 111115};
  int dest_memcpy[5];
  int dest_s21_memcpy[5];
  size_t n = 10;

  memcpy(dest_memcpy, src, n);
  s21_memcpy(dest_s21_memcpy, src, n);
  ck_assert_mem_eq(dest_memcpy, dest_s21_memcpy, n);
}
END_TEST

START_TEST(memcpy_13) {
  char src[] = "Hello, World!";
  char dest[20];
  size_t n = strlen(src) + 1;
  char *memcpy_result = memcpy(dest, src, n);
  char *s21_memcpy_result = s21_memcpy(dest, src, n);
  ck_assert_ptr_eq(memcpy_result, s21_memcpy_result);
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *s_memcpy;
  TCase *tc_memcpy;
  s_memcpy = suite_create("s_memcpy");

  tc_memcpy = tcase_create("tc_memcpy");

  tcase_add_test(tc_memcpy, memcpy_1);
  tcase_add_test(tc_memcpy, memcpy_2);
  tcase_add_test(tc_memcpy, memcpy_3);
  tcase_add_test(tc_memcpy, memcpy_4);
  tcase_add_test(tc_memcpy, memcpy_5);
  tcase_add_test(tc_memcpy, memcpy_6);
  tcase_add_test(tc_memcpy, memcpy_7);
  tcase_add_test(tc_memcpy, memcpy_8);
  tcase_add_test(tc_memcpy, memcpy_9);
  tcase_add_test(tc_memcpy, memcpy_10);
  tcase_add_test(tc_memcpy, memcpy_11);
  tcase_add_test(tc_memcpy, memcpy_12);
  tcase_add_test(tc_memcpy, memcpy_13);

  suite_add_tcase(s_memcpy, tc_memcpy);
  return s_memcpy;
}
