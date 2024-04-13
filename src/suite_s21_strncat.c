#include "string_suitecases.h"

START_TEST(strncat_1) {
  char str[15] = {""};
  char str2[15] = {""};
  ck_assert_str_eq(s21_strncat(str, "Hello", sizeof(str) - 1),
                   strncat(str2, "Hello", sizeof(str2) - 1));
}
END_TEST

START_TEST(strncat_2) {
  char str3[20] = {"Spurgerb"};
  char str4[20] = {"Spurgerb"};
  strncat(str3, "\n", sizeof(str3) - 1);
  s21_strncat(str4, "\n", sizeof(str4) - 1);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(strncat_3) {
  char str3[20] = {"some\ntext"};
  char str4[20] = {"some\ntext"};
  strncat(str3, "Hello", sizeof(str3) - 1);
  s21_strncat(str4, "Hello", sizeof(str4) - 1);
  ck_assert_int_eq(s21_strncmp(str3, str4, sizeof(str3) - 1),
                   strncmp(str3, str4, sizeof(str4) - 1));
}
END_TEST

START_TEST(strncat_4) {
  char str5[15] = {"Hello"};
  char str6[15] = {"Hello"};
  ck_assert_str_eq(s21_strncat(str5, " World", 5), strncat(str6, " World", 5));
}
END_TEST

START_TEST(strncat_5) {
  char str7[15] = {"\n\n\n"};
  char str8[15] = {"\n\n\n"};
  ck_assert_str_eq(s21_strncat(str7, " \0", 5), strncat(str8, " \0", 5));
}
END_TEST

START_TEST(strncat_6) {
  char str9[15] = {"\0"};
  char str10[15] = {"\0"};
  ck_assert_str_eq(s21_strncat(str9, "\0", 5), strncat(str10, "\0", 5));
}
END_TEST

START_TEST(strncat_7) {
  char str11[15] = {"Hello"};
  char str12[15] = {"Hello"};
  ck_assert_str_eq(s21_strncat(str11, "", 5), strncat(str12, "", 5));
}
END_TEST

START_TEST(strncat_8) {
  char str13[40] = {""};
  char str14[40] = {""};
  ck_assert_str_eq(s21_strncat(str13, "", 20), strncat(str14, "", 20));
}
END_TEST

START_TEST(strncat_9) {
  char str15[15] = {""};
  char str16[15] = {""};
  ck_assert_str_eq(s21_strncat(str15, " ", 5), strncat(str16, " ", 5));
}
END_TEST

START_TEST(strncat_10) {
  char st[15] = "!№ % :?";
  char st2[15] = "!№ % :?";
  char *ptr_st = st;
  char *ptr_st2 = st2;
  ck_assert_str_eq(s21_strncat(ptr_st, " World", 5),
                   strncat(ptr_st2, " World", 5));
}
END_TEST

START_TEST(strncat_11) {
  char st[15] = "!\t№ % :?\0";
  char st2[15] = "!\t№ % :?\0";
  char *ptr_st = st;
  char *ptr_st2 = st2;
  ck_assert_str_eq(s21_strncat(ptr_st, " \n", 5), strncat(ptr_st2, " \n", 5));
}
END_TEST

START_TEST(strncat_12) {
  char st[150] =
      "The quick brown fox jumps over the lazy dog. Lorem ipsum dolor sit "
      "amet, consectetur adipiscing elit. Sed ac ligula sed ex malesuada ";
  char st2[170] =
      "This text is a mix of the original sentence and some Lorem "
      "Ipsum text, which is commonly used as placeholder text in "
      "the design and typesetting industry.";
  char *ptr_st = st;
  char *ptr_st2 = st2;
  ck_assert_str_eq(s21_strncat(ptr_st, " World", sizeof(st) - 1),
                   strncat(ptr_st, " World", sizeof(st2) - 1));
  ck_assert_str_eq(s21_strncat(ptr_st2, " World", 5),
                   strncat(ptr_st2, " World", 5));
}
END_TEST

Suite *suite_s21_strncat() {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("s21_strncat");
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);
  tcase_add_test(tc, strncat_11);
  tcase_add_test(tc, strncat_12);

  suite_add_tcase(s, tc);
  return s;
}