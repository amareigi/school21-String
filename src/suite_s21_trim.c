#include "string_suitecases.h"

START_TEST(trim_1) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "abcf";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "defg");
  free(res);
}
END_TEST

START_TEST(trim_2) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "fcba";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "defg");
  free(res);
}
END_TEST

START_TEST(trim_3) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "dfg";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "abcde");
  free(res);
}
END_TEST

START_TEST(trim_4) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "gfd";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "abcde");
  free(res);
}
END_TEST

START_TEST(trim_5) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "abcg";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "def");
  free(res);
}
END_TEST

START_TEST(trim_6) {
  char str1[100] = "abcdefg";
  char trim_part[100] = "abcdefg";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_7) {
  char str1[100] = "";
  char trim_part[100] = "";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_8) {
  char str1[100] = "";
  char trim_part[100] = "ergouqbrg*&^*&Teriug";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_9) {
  char str1[100] = "ergouqbrg*&^*&Teriug";
  char trim_part[100] = "";
  char *res = (char *)s21_trim(str1, trim_part);
  ck_assert_pstr_eq(res, "ergouqbrg*&^*&Teriug");
  free(res);
}
END_TEST

START_TEST(trim_10) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(trim_11) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_12) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIJKLMNOPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(trim_13) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZ";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(trim_14) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZABC";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(trim_15) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "ABC";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "DEFGHIabcABCPQRSTUVWXYZabc");
  free(str3);
}
END_TEST

START_TEST(trim_16) {
  char str1[] = "ABCDEFGHIabcABCPQRSTUVWXYZabc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ABCDEFGHIabcABCPQRSTUVWXYZ");
  free(str3);
}
END_TEST

START_TEST(trim_17) {
  char str1[] = "abc123abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123");
  free(str3);
}
END_TEST

START_TEST(trim_18) {
  char str1[] = "abc123abc456abc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456");
  free(str3);
}
END_TEST

START_TEST(trim_19) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "abc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "1bc123abc456a1");
  free(str3);
}
END_TEST

START_TEST(trim_20) {
  char str1[] = "a1bc123abc456a1bc";
  char str2[] = "a1bc";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "23abc456");
  free(str3);
}
END_TEST

START_TEST(trim_21) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab2c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "123abc456a1");
  free(str3);
}
END_TEST

START_TEST(trim_22) {
  char str1[] = "abc123abc456a1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "3abc456");
  free(str3);
}
END_TEST

START_TEST(trim_23) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "ab12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456aB");
  free(str3);
}
END_TEST

START_TEST(trim_24) {
  char str1[] = "abAc123abc456aB1bc";
  char str2[] = "aBb12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "Ac123abc456");
  free(str3);
}
END_TEST

START_TEST(trim_25) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "aBbA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(trim_26) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB3bA12c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(trim_27) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4aB37bA897c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA533322444456");
  free(str3);
}
END_TEST

START_TEST(trim_28) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB437bA189117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "533322444456");
  free(str3);
}
END_TEST

START_TEST(trim_29) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "4223aB6437bA1589117c";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_30) {
  char str1[] = "11222333444aaaBaabaA53332244445677Babab7878998";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "11222333444aaaBaabaA53332244445677Babab7878998");
  free(str3);
}
END_TEST

START_TEST(trim_31) {
  char str1[] = "";
  char str2[] = "jK";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_32) {
  char str1[] = "sdfghjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfghjk");
  free(str3);
}
END_TEST

START_TEST(trim_33) {
  char str1[] = "sdfg hjk";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "sdfg hjk");
  free(str3);
}
END_TEST

START_TEST(trim_34) {
  char str1[] = " ";
  char str2[] = " ";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_35) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333ab";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

START_TEST(trim_36) {
  char str1[] = "a231546yutiljkhgtyre565786oiu;jlkhb12";
  char str2[] = "12333333333333333333333333333333333abmmmmmm";
  char *str3 = s21_trim(str1, str2);
  ck_assert_str_eq(str3, "546yutiljkhgtyre565786oiu;jlkh");
  free(str3);
}
END_TEST

Suite *suite_s21_trim(void) {
  Suite *s_trim;
  TCase *tc_trim;
  s_trim = suite_create("s_trim");

  tc_trim = tcase_create("tc_trim");

  tcase_add_test(tc_trim, trim_1);
  tcase_add_test(tc_trim, trim_2);
  tcase_add_test(tc_trim, trim_3);
  tcase_add_test(tc_trim, trim_4);
  tcase_add_test(tc_trim, trim_5);
  tcase_add_test(tc_trim, trim_6);
  tcase_add_test(tc_trim, trim_7);
  tcase_add_test(tc_trim, trim_8);
  tcase_add_test(tc_trim, trim_9);
  tcase_add_test(tc_trim, trim_10);
  tcase_add_test(tc_trim, trim_11);
  tcase_add_test(tc_trim, trim_12);
  tcase_add_test(tc_trim, trim_13);
  tcase_add_test(tc_trim, trim_14);
  tcase_add_test(tc_trim, trim_15);
  tcase_add_test(tc_trim, trim_16);
  tcase_add_test(tc_trim, trim_17);
  tcase_add_test(tc_trim, trim_18);
  tcase_add_test(tc_trim, trim_19);
  tcase_add_test(tc_trim, trim_20);
  tcase_add_test(tc_trim, trim_21);
  tcase_add_test(tc_trim, trim_22);
  tcase_add_test(tc_trim, trim_23);
  tcase_add_test(tc_trim, trim_24);
  tcase_add_test(tc_trim, trim_25);
  tcase_add_test(tc_trim, trim_26);
  tcase_add_test(tc_trim, trim_27);
  tcase_add_test(tc_trim, trim_28);
  tcase_add_test(tc_trim, trim_29);
  tcase_add_test(tc_trim, trim_30);
  tcase_add_test(tc_trim, trim_31);
  tcase_add_test(tc_trim, trim_32);
  tcase_add_test(tc_trim, trim_33);
  tcase_add_test(tc_trim, trim_34);
  tcase_add_test(tc_trim, trim_35);
  tcase_add_test(tc_trim, trim_36);

  suite_add_tcase(s_trim, tc_trim);
  return s_trim;
}
