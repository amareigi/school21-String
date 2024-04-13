#include "string_suitecases.h"

START_TEST(strtok_1) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "c";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "abc";
  char str3[] = "abc";
  char str2[] = "d";
  ck_assert_str_eq(strtok(str1, str2), s21_strtok(str3, str2));
}
END_TEST

START_TEST(strtok_3) {
  char str_strtok_u[] = "abcdegabcdegabcde";
  char *razd = "g";
  char *s21_str = s21_strtok(str_strtok_u, razd);

  while (s21_str != s21_NULL) {
    s21_str = s21_strtok(s21_NULL, razd);
  }

  char str[] = "abcdegabcdegabcde";
  char *res = strtok(str, razd);

  while (res != NULL) {
    res = strtok(NULL, razd);
  }
  ck_assert_ptr_null(s21_str);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(strtok_4) {
  char str_strtok_u[] = "1/2:3(4)5";
  char *razd = "/(:)";
  char *s21_str = s21_strtok(str_strtok_u, razd);

  while (s21_str != s21_NULL) {
    s21_str = s21_strtok(s21_NULL, razd);
  }

  char str_strtok_o[] = "1/2:3(4)5";
  char *str = strtok(str_strtok_o, razd);

  while (str != NULL) {
    str = strtok(NULL, razd);
  }
  ck_assert_ptr_null(s21_str);
  ck_assert_ptr_null(str);
}
END_TEST

START_TEST(strtok_5) {
  char str_strtok_u[] = "1/2:3(4)5/";
  char *razd = "/(:)";
  char *s21_str = s21_strtok(str_strtok_u, razd);

  while (s21_str != s21_NULL) {
    s21_str = s21_strtok(s21_NULL, razd);
  }

  char str_strtok_o[] = "1/2:3(4)5/";
  char *str = strtok(str_strtok_o, razd);

  while (str != NULL) {
    str = strtok(NULL, razd);
  }
  ck_assert_ptr_null(s21_str);
  ck_assert_ptr_null(str);
}
END_TEST

START_TEST(strtok_6) {
  char str_strtok_u[] = "\0(1/2:3(4)5/";
  char *razd = "/(:)";
  char *s21_str = s21_strtok(str_strtok_u, razd);

  while (s21_str != s21_NULL) {
    s21_str = s21_strtok(s21_NULL, razd);
  }

  char str_strtok_o[] = "\0(1/2:3(4)5/";
  char *str = strtok(str_strtok_o, razd);

  while (str != NULL) {
    str = strtok(NULL, razd);
  }
  ck_assert_ptr_null(s21_str);
  ck_assert_ptr_null(str);
}
END_TEST

START_TEST(strtok_7) {
  char str_strtok_u[] = "\r\t\n";
  char str_strtok_o[] = "\r\t\n";
  char *razd = "\\";
  ck_assert_str_eq(strtok(str_strtok_o, razd), s21_strtok(str_strtok_u, razd));
}
END_TEST

START_TEST(strtok_8) {
  char str_strtok_u[] = "\r\t\n";
  char str_strtok_o[] = "\r\t\n";
  char *razd = "\r\t\n";
  char *s21_str = s21_strtok(str_strtok_u, razd);

  ck_assert_ptr_null(s21_str);
  char *str = s21_strtok(str_strtok_o, razd);

  ck_assert_ptr_null(str);
}
END_TEST

START_TEST(s21_strtok_1) {
  char str[] = "Ya/(v)/svoyem/poznanii/nastol'ko/preispolnilsya...";
  char sep[] = "/()";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_2) {
  char str[] = "Hello! World! YEEEEAAAA!!!!";
  char sep[] = "!";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_3) {
  char str[] = "Ya v svoyem poznanii nastol'ko preispolnilsya...";
  char sep[] = "s'.";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_4) {
  char str[] =
      "Chto|ya|kak|budto|uzhe!sto|trillionov milliardov|let+prozhivayu";
  char sep[] = "| +";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_5) {
  char str[] = " ";
  char sep[] = "NULL";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_6) {
  char str[] = "NULL";
  char sep[] = "NULL";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_mem_eq(copy, orig, 0);
}
END_TEST

START_TEST(s21_strtok_7) {
  char str[] = "Ya-v+svoyem-poznanii+nastol'ko-preispolnilsya...----------";
  char sep[] = "-";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_8) {
  char str[] = "Ya v svoyem poznanii nastol'ko\0 preispolnilsya...";
  char sep[] = ".";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

START_TEST(s21_strtok_9) {
  char str[] = "abc";
  char sep[] = "abc";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_mem_eq(copy, orig, 0);
}
END_TEST

START_TEST(s21_strtok_10) {
  char str[] = "|||| ";
  char sep[] = "|";

  char *orig = {0}, *copy = {0};
  orig = strtok(str, sep);
  copy = s21_strtok(str, sep);

  ck_assert_str_eq(copy, orig);
}
END_TEST

Suite *suite_s21_strtok(void) {
  Suite *s_strtok;
  TCase *tc_strtok;
  s_strtok = suite_create("s_strtok");

  tc_strtok = tcase_create("tc_strtok");

  tcase_add_test(tc_strtok, strtok_1);
  tcase_add_test(tc_strtok, strtok_2);
  tcase_add_test(tc_strtok, strtok_3);
  tcase_add_test(tc_strtok, strtok_4);
  tcase_add_test(tc_strtok, strtok_5);
  tcase_add_test(tc_strtok, strtok_6);
  tcase_add_test(tc_strtok, strtok_7);
  tcase_add_test(tc_strtok, strtok_8);

  tcase_add_test(tc_strtok, s21_strtok_1);
  tcase_add_test(tc_strtok, s21_strtok_2);
  tcase_add_test(tc_strtok, s21_strtok_3);
  tcase_add_test(tc_strtok, s21_strtok_4);
  tcase_add_test(tc_strtok, s21_strtok_5);
  tcase_add_test(tc_strtok, s21_strtok_6);
  tcase_add_test(tc_strtok, s21_strtok_7);
  tcase_add_test(tc_strtok, s21_strtok_8);
  tcase_add_test(tc_strtok, s21_strtok_9);
  tcase_add_test(tc_strtok, s21_strtok_10);

  suite_add_tcase(s_strtok, tc_strtok);
  return s_strtok;
}
