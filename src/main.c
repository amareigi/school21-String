#include "s21_string.h"
#include "string_suitecases.h"

int main(void) {
  Suite *cases[] = {
      suite_s21_memchr(),   suite_s21_strchr(),  suite_s21_strncat(),
      suite_s21_memcpy(),   suite_s21_strlen(),  suite_s21_strerror(),
      suite_s21_memset(),   suite_s21_strpbrk(), suite_s21_strrchr(),
      suite_s21_strstr(),   suite_s21_insert(),  suite_s21_to_upper(),
      suite_s21_to_lower(), suite_s21_trim(),    suite_s21_strcspn(),
      suite_s21_strncmp(),  suite_s21_strncpy(), suite_s21_memcmp(),
      suite_s21_sprintf(),  suite_s21_strtok(),  NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
