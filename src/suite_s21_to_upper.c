#include "string_suitecases.h"

START_TEST(to_upper_1) {
  char *str = "SpUrgErB";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "SPURGERB");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_2) {
  char str[20] = {'a', 'M', 'a', 'r', 'E', 'i', 'g', 'i', '\0'};
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "AMAREIGI");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_3) {
  char *str = "g0ren3G@";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "G0REN3G@");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_4) {
  char *str = "FIRSTALE";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "FIRSTALE");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_5) {
  char *str = "tEsT";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "TEST");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_6) {
  char *str = "AaAZzZ";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "AAAZZZ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_7) {
  char *str = "{}[]||~~";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "{}[]||~~");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_8) {
  char *str = NULL;
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_9) {
  char *str = " ";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, " ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_10) {
  char *str = NULL;
  char *new_str = s21_to_upper(str);
  if (!new_str) {
    ck_assert_ptr_eq(new_str, NULL);
    free(new_str);
  }
}

START_TEST(to_upper_11) {
  char *str = s21_NULL;
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_12) {
  char *str = "\r\v3\t\f45";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "\r\v3\t\f45");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_13) {
  char *str = "aaazzz";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "AAAZZZ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_14) {
  char *str = "AAAZZZ";
  char *new_str = s21_to_upper(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "AAAZZZ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_upper_15) {
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);
}
END_TEST

START_TEST(to_upper_16) {
  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);
}
END_TEST

START_TEST(to_upper_17) {
  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);
}
END_TEST

START_TEST(to_upper_18) {
  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);
}
END_TEST

START_TEST(to_upper_19) {
  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);
}
END_TEST

START_TEST(to_upper_20) {
  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);
}
END_TEST

START_TEST(to_upper_21) {
  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

Suite *suite_s21_to_upper() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("s21_to_upper");

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);
  tcase_add_test(tc, to_upper_5);
  tcase_add_test(tc, to_upper_6);
  tcase_add_test(tc, to_upper_7);
  tcase_add_test(tc, to_upper_8);
  tcase_add_test(tc, to_upper_9);
  tcase_add_test(tc, to_upper_10);
  tcase_add_test(tc, to_upper_11);
  tcase_add_test(tc, to_upper_12);
  tcase_add_test(tc, to_upper_13);
  tcase_add_test(tc, to_upper_14);
  tcase_add_test(tc, to_upper_15);
  tcase_add_test(tc, to_upper_16);
  tcase_add_test(tc, to_upper_17);
  tcase_add_test(tc, to_upper_18);
  tcase_add_test(tc, to_upper_19);
  tcase_add_test(tc, to_upper_20);
  tcase_add_test(tc, to_upper_21);

  suite_add_tcase(s, tc);
  return s;
}
