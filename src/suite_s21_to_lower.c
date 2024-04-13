#include "string_suitecases.h"

START_TEST(to_lower_1) {
  char *str = "SpUrgErB";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "spurgerb");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_2) {
  char str[20] = {'a', 'M', 'a', 'r', 'E', 'i', 'g', 'i', '\0'};
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "amareigi");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_3) {
  char *str = "g0ren3G@";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "g0ren3g@");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_4) {
  char *str = "firstale";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "firstale");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_5) {
  char *str = "tEsT";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "test");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_6) {
  char *str = "AaAZzZ";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "aaazzz");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_7) {
  char *str = "{}[]||~~";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "{}[]||~~");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_8) {
  char *str = NULL;
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_9) {
  char *str = " ";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, " ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_10) {
  char *str = NULL;
  char *new_str = s21_to_lower(str);
  if (!new_str) {
    ck_assert_ptr_eq(new_str, NULL);
    free(new_str);
  }
}

START_TEST(to_lower_11) {
  char *str = s21_NULL;
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_12) {
  char *str = "\r\v3\t\f45";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "\r\v3\t\f45");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_13) {
  char *str = "   aAa   zZz   ";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "   aaa   zzz   ");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_14) {
  char *str = "K1K2K3K4K5K6K7K8K9";
  char *new_str = s21_to_lower(str);
  if (new_str) {
    ck_assert_str_eq(new_str, "k1k2k3k4k5k6k7k8k9");
    free(new_str);
  }
}
END_TEST

START_TEST(to_lower_15) {
  char *new_str = "HeRe w0 arE123\0";
  char *test01 = s21_to_lower(new_str);
  ck_assert_str_eq(test01, "here w0 are123");
  free(test01);
}
END_TEST

START_TEST(to_lower_16) {
  char *new_str = "Here w0 are\n\0";
  char *test02 = s21_to_lower(new_str);
  ck_assert_str_eq(test02, "here w0 are\n");
  free(test02);
}
END_TEST

START_TEST(to_lower_17) {
  char *new_str = "A\n\0";
  char *test03 = s21_to_lower(new_str);
  ck_assert_str_eq(test03, "a\n");
  free(test03);
}
END_TEST

START_TEST(to_lower_18) {
  char *new_str = " \n\0";
  char *test04 = s21_to_lower(new_str);
  ck_assert_str_eq(test04, " \n");
  free(test04);
}
END_TEST

START_TEST(to_lower_19) {
  char *new_str = " \0";
  char *test05 = s21_to_lower(new_str);
  ck_assert_str_eq(test05, " ");
  free(test05);
}
END_TEST

START_TEST(to_lower_20) {
  char *new_str = "\n\0";
  char *test06 = s21_to_lower(new_str);
  ck_assert_str_eq(test06, "\n");
  free(test06);
}
END_TEST

START_TEST(to_lower_21) {
  char *new_str = "\0";
  char *test07 = s21_to_lower(new_str);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

Suite *suite_s21_to_lower() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("s21_to_lower");

  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);
  tcase_add_test(tc, to_lower_4);
  tcase_add_test(tc, to_lower_5);
  tcase_add_test(tc, to_lower_6);
  tcase_add_test(tc, to_lower_7);
  tcase_add_test(tc, to_lower_8);
  tcase_add_test(tc, to_lower_9);
  tcase_add_test(tc, to_lower_10);
  tcase_add_test(tc, to_lower_11);
  tcase_add_test(tc, to_lower_12);
  tcase_add_test(tc, to_lower_13);
  tcase_add_test(tc, to_lower_14);
  tcase_add_test(tc, to_lower_15);
  tcase_add_test(tc, to_lower_16);
  tcase_add_test(tc, to_lower_17);
  tcase_add_test(tc, to_lower_18);
  tcase_add_test(tc, to_lower_19);
  tcase_add_test(tc, to_lower_20);
  tcase_add_test(tc, to_lower_21);

  suite_add_tcase(s, tc);
  return s;
}
