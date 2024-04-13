#include "string_suitecases.h"

START_TEST(strpbrk_1) {
  char str1[] = "this is a test";
  char str2[] = "this";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[] = "this is a test";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[] = "abc";
  char str2[] = "ccc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[] = "abc123";
  char str2[] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[] = "abglk1erw233c";
  char str2[] = "321";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str1[] = "ab\nc";
  char str2[] = "\n";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  char str1[] = "a8yuoiytu5u6rtyfkguhubc";
  char str2[] = "123i6t5";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
  char str1[] = "a77777bc";
  char str2[] = "177723";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_9) {
  char str1[] = "ab7itgkhm.,c";
  char str2[] = "12hjv3";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_10) {
  char str1[] = "ab.,c";
  char str2[] = "127863";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_11) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_12) {
  char str1[] = " ";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_13) {
  char str1[] = "abc";
  char str2[] = " ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_14) {
  char str1[] = "9087";
  char str2[] = "657";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_15) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_16) {
  char str1[] = " ";
  char str2[] = " ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_17) {
  char str1[] = "abc ";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_18) {
  char str1[] = "abc";
  char str2[] = "abc ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_19) {
  char str1[] = " abc";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_20) {
#line 2644
  char str1[] = "abc";
  char str2[] = " abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_21) {
  char str1[] = "123";
  char str2[] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_22) {
  char str1[] = "123";
  char str2[] = "321";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_23) {
  char str1[] = "321";
  char str2[] = "321";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_24) {
  char str1[] = "321";
  char str2[] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_25) {
  char str1[] = "1234";
  char str2[] = "123";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_26) {
  char str1[] = "132";
  char str2[] = "1234";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_27) {
  char str1[] = "abcd";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_28) {
  char str1[] = "abc";
  char str2[] = "abcd";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_29) {
  char str1[] = "12ab";
  char str2[] = "12ab";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_30) {
  char str1[] = "ab12";
  char str2[] = "12ab";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_31) {
  char str1[] = "abc";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_32) {
  char str1[] = " ";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_33) {
  char str1[] = "abc";
  char str2[] = " ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_34) {
  char str1[] = "9087";
  char str2[] = "657";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_35) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_36) {
  char str1[] = " ";
  char str2[] = " ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_37) {
  char str1[] = "abc ";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_38) {
  char str1[] = "abc";
  char str2[] = "abc ";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_39) {
  char str1[] = " abc";
  char str2[] = "abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_40) {
  char str1[] = "abc";
  char str2[] = " abc";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *suite_s21_strpbrk(void) {
  Suite *s_strpbrk;
  TCase *tc_strpbrk;
  s_strpbrk = suite_create("s_strpbrk");

  tc_strpbrk = tcase_create("tc_strpbrk");

  tcase_add_test(tc_strpbrk, strpbrk_1);
  tcase_add_test(tc_strpbrk, strpbrk_2);
  tcase_add_test(tc_strpbrk, strpbrk_3);
  tcase_add_test(tc_strpbrk, strpbrk_4);
  tcase_add_test(tc_strpbrk, strpbrk_5);
  tcase_add_test(tc_strpbrk, strpbrk_6);
  tcase_add_test(tc_strpbrk, strpbrk_7);
  tcase_add_test(tc_strpbrk, strpbrk_8);
  tcase_add_test(tc_strpbrk, strpbrk_9);
  tcase_add_test(tc_strpbrk, strpbrk_10);
  tcase_add_test(tc_strpbrk, strpbrk_11);
  tcase_add_test(tc_strpbrk, strpbrk_12);
  tcase_add_test(tc_strpbrk, strpbrk_13);
  tcase_add_test(tc_strpbrk, strpbrk_14);
  tcase_add_test(tc_strpbrk, strpbrk_15);
  tcase_add_test(tc_strpbrk, strpbrk_16);
  tcase_add_test(tc_strpbrk, strpbrk_17);
  tcase_add_test(tc_strpbrk, strpbrk_18);
  tcase_add_test(tc_strpbrk, strpbrk_19);
  tcase_add_test(tc_strpbrk, strpbrk_20);
  tcase_add_test(tc_strpbrk, strpbrk_21);
  tcase_add_test(tc_strpbrk, strpbrk_22);
  tcase_add_test(tc_strpbrk, strpbrk_23);
  tcase_add_test(tc_strpbrk, strpbrk_24);
  tcase_add_test(tc_strpbrk, strpbrk_25);
  tcase_add_test(tc_strpbrk, strpbrk_26);
  tcase_add_test(tc_strpbrk, strpbrk_27);
  tcase_add_test(tc_strpbrk, strpbrk_28);
  tcase_add_test(tc_strpbrk, strpbrk_29);
  tcase_add_test(tc_strpbrk, strpbrk_30);
  tcase_add_test(tc_strpbrk, strpbrk_31);
  tcase_add_test(tc_strpbrk, strpbrk_32);
  tcase_add_test(tc_strpbrk, strpbrk_33);
  tcase_add_test(tc_strpbrk, strpbrk_34);
  tcase_add_test(tc_strpbrk, strpbrk_35);
  tcase_add_test(tc_strpbrk, strpbrk_36);
  tcase_add_test(tc_strpbrk, strpbrk_37);
  tcase_add_test(tc_strpbrk, strpbrk_38);
  tcase_add_test(tc_strpbrk, strpbrk_39);
  tcase_add_test(tc_strpbrk, strpbrk_40);

  suite_add_tcase(s_strpbrk, tc_strpbrk);
  return s_strpbrk;
}
