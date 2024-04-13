#include "string_suitecases.h"

START_TEST(strstr_1) {
  char str2[15] = "Hello";
  ck_assert_str_eq(s21_strstr(str2, "Hello"), strstr(str2, "Hello"));
}
END_TEST

START_TEST(strstr_2) {
  char str[15] = "Hello world";
  ck_assert_str_eq(s21_strstr(str, "Hello"), strstr(str, "Hello"));
}
END_TEST

START_TEST(strstr_3) {
  char str2[15] = "Hello";
  ck_assert_pstr_eq(s21_strstr(str2, "world"), strstr(str2, "world"));
}
END_TEST

START_TEST(strstr_4) {
  char str[15] = "Hello world";
  ck_assert_str_eq(s21_strstr(str, "world"), strstr(str, "world"));
}
END_TEST

START_TEST(strstr_5) {
  char st[150] =
      "The quick brown fox jumps over the lazy dog. Lorem ipsum dolor sit "
      "amet, consectetur adipiscing elit. Sed ac ligula sed ex malesuada ";
  char *ptr_st = st;
  ck_assert_str_eq(s21_strstr(ptr_st, " elit"), strstr(ptr_st, " elit"));
}
END_TEST

START_TEST(strstr_6) {
  char st2[170] =
      "This text is a mix of the original sentence and some Lorem "
      "Ipsum text, which is commonly used as placeholder text in "
      "the design and typesetting industry.";
  char *ptr_st2 = st2;
  ck_assert_str_eq(s21_strstr(ptr_st2, " text"), strstr(ptr_st2, " text"));
}
END_TEST

START_TEST(strstr_7) {
  char st2[170] =
      "This text is a mix of the original sentence and some Lorem "
      "Ipsum text, which is commonly used as placeholder text in "
      "the design and typesetting industry.";
  char *ptr_st2 = st2;
  ck_assert_str_eq(s21_strstr(ptr_st2, "d t"), strstr(ptr_st2, "d t"));
}
END_TEST

START_TEST(strstr_8) {
  char str2[15] = "!@#$%^&*()";
  ck_assert_pstr_eq(s21_strstr(str2, "%"), strstr(str2, "%"));
}
END_TEST

START_TEST(strstr_9) {
  char str[15] = "123456789";
  ck_assert_str_eq(s21_strstr(str, "89"), strstr(str, "89"));
}
END_TEST

START_TEST(strstr_10) {
  char str2[15] = "orld";
  ck_assert_pstr_eq(s21_strstr(str2, "world"), strstr(str2, "world"));
}
END_TEST

START_TEST(strstr_11) {
  char str[30] = {'H', 'e', 'l', 'l', 'o', 'o', 'o', 'o', 'o', 'o', '\0'};
  ck_assert_str_eq(s21_strstr(str, "Hello"), strstr(str, "Hello"));
}
END_TEST

START_TEST(strstr_12) {
  char *str[15] = {"Hello world"};
  ck_assert_str_eq(s21_strstr(*str, "Hello "), strstr(*str, "Hello "));
}
END_TEST

START_TEST(strstr_13) {
  char *str2[15] = {"Hello"};
  ck_assert_str_eq(s21_strstr(*str2, ""), strstr(*str2, ""));
}
END_TEST

START_TEST(strstr_14) {
  char *str[15] = {"Hello world"};
  ck_assert_str_eq(s21_strstr(*str, "d"), strstr(*str, "d"));
}
END_TEST

START_TEST(strstr_15) {
  char *str2[15] = {"Hello"};
  ck_assert_str_eq(s21_strstr(*str2, "lo"), strstr(*str2, "lo"));
}
END_TEST

START_TEST(strstr_16) {
  char *str2[15] = {"Hello"};
  ck_assert_str_eq(s21_strstr(*str2, "H"), strstr(*str2, "H"));
}
END_TEST

START_TEST(strstr_17) {
  char str[500] = {
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ut odio "
      "magna. Nullam scelerisque lobortis sem, quis aliquam leo. Maecenas eu "
      "lectus euismod, posuere massa ac, volutpat velit. Donec in aliquet "
      "nunc. Fusce vehicula justo ut purus pellentesque, nec sagittis mi "
      "malesuada. Proin ultricies condimentum felis, sed efficitur dolor "
      "vulputate quis."};
  ck_assert_str_eq(s21_strstr(str, "elit. Donec"), strstr(str, "elit. Donec"));
}
END_TEST

START_TEST(strstr_18) {
  char str2[500] = {
      "Suspendisse finibus lorem vel felis tristique, vel ullamcorper nisl "
      "volutpat. In eu viverra dui, vitae dignissim leo. Phasellus ultricies, "
      "mi et luctus posuere, metus ex venenatis nisi, id tempus velit ex at "
      "erat. Sed in sapien non ligula efficitur feugiat. Nam ullamcorper, "
      "mauris vitae congue finibus, nibh augue congue neque, a lacinia tellus "
      "metus vitae velit. Integer sit amet mauris massa. Sed semper vulputate "
      "odio, non placerat massa faucibus id."};
  ck_assert_str_eq(s21_strstr(str2, "ugiat. Nam ullamcorper"),
                   strstr(str2, "ugiat. Nam ullamcorper"));
}
END_TEST

START_TEST(strstr_19) {
  char *str[250] = {
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ut odio "
      "magna. Nullam scelerisque lobortis sem, quis aliquam leo. Maecenas eu "
      "lectus euismod, posuere massa ac, volutpat velit. Donec in aliquet "
      "nunc."};
  ck_assert_str_eq(s21_strstr(*str, "leo. "), strstr(*str, "leo. "));
}
END_TEST

START_TEST(strstr_20) {
  char *str2[250] = {
      "Suspendisse finibus lorem vel felis tristique, vel ullamcorper nisl "
      "volutpat. In eu viverra dui, vitae dignissim leo. Phasellus ultricies, "
      "mi et luctus posuere, metus ex venenatis nisi, id tempus velit ex at "
      "erat."};
  ck_assert_str_eq(s21_strstr(*str2, ", vitae"), strstr(*str2, ", vitae"));
}
END_TEST

START_TEST(strstr_21) {
  char *str[250] = {
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ut odio "
      "magna. Nullam scelerisque lobortis sem, quis aliquam leo. Maecenas eu "
      "lectus euismod, posuere massa ac, volutpat velit. Donec in aliquet "
      "nunc."};
  ck_assert_pstr_eq(s21_strstr(*str, ", vitae"), strstr(*str, ", vitae"));
}
END_TEST

START_TEST(strstr_22) {
  char *str2[250] = {
      "Suspendisse finibus lorem vel felis tristique, vel ullamcorper nisl "
      "volutpat. In eu viverra dui, vitae dignissim leo. Phasellus ultricies, "
      "mi et luctus posuere, metus ex venenatis nisi, id tempus velit ex at "
      "erat."};
  ck_assert_ptr_eq(s21_strstr(*str2, ", vitae"), strstr(*str2, ", vitae"));
}
END_TEST

START_TEST(strstr_23) {
  char *str2[250] = {
      "Suspendisse finibus lorem vel felis tristique, vel ullamcorper nisl "
      "volutpat. In eu viverra dui, vitae dignissim leo. Phasellus ultricies, "
      "mi et luctus posuere, metus ex venenatis nisi, id tempus velit ex at "
      "erat."};
  ck_assert_ptr_nonnull(s21_strstr(*str2, "."));
}
END_TEST

START_TEST(strstr_24) {
  char *str[250] = {
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ut odio "
      "magna. Nullam scelerisque lobortis sem, quis aliquam leo. Maecenas eu "
      "lectus euismod, posuere massa ac, volutpat velit. Donec in aliquet "
      "nunc."};
  ck_assert_ptr_null(s21_strstr(*str, "ex at"));
}
END_TEST

START_TEST(strstr_25) {
  char str[30] = "";
  ck_assert_str_eq(s21_strstr(str, ""), strstr(str, ""));
}
END_TEST

START_TEST(strstr_26) {
  char str2[15] = "orld";
  ck_assert_pstr_eq(s21_strstr(str2, "world"), strstr(str2, "world"));
}
END_TEST

START_TEST(strstr_27) {
  char str[30] = "";
  ck_assert_str_eq(s21_strstr(str, "\0"), strstr(str, "\0"));
}
END_TEST

START_TEST(strstr_28) {
  char str2[15] = "orld";
  ck_assert_pstr_eq(s21_strstr(str2, "\0"), strstr(str2, "\0"));
}
END_TEST

Suite *suite_s21_strstr() {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("s21_strstr");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);
  tcase_add_test(tc, strstr_12);
  tcase_add_test(tc, strstr_13);
  tcase_add_test(tc, strstr_14);
  tcase_add_test(tc, strstr_15);
  tcase_add_test(tc, strstr_16);
  tcase_add_test(tc, strstr_17);
  tcase_add_test(tc, strstr_18);
  tcase_add_test(tc, strstr_19);
  tcase_add_test(tc, strstr_20);
  tcase_add_test(tc, strstr_21);
  tcase_add_test(tc, strstr_22);
  tcase_add_test(tc, strstr_23);
  tcase_add_test(tc, strstr_24);
  tcase_add_test(tc, strstr_25);
  tcase_add_test(tc, strstr_26);
  tcase_add_test(tc, strstr_27);
  tcase_add_test(tc, strstr_28);

  suite_add_tcase(s, tc);
  return s;
}