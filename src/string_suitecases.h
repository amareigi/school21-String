#ifndef S_SRC_STRING_SUITECASES_H_
#define S_SRC_STRING_SUITECASES_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

Suite *suite_s21_memchr(void);
Suite *suite_s21_strncat();
Suite *suite_s21_memcpy(void);
Suite *suite_s21_strlen();
Suite *suite_s21_strchr();
Suite *suite_s21_strerror(void);
Suite *suite_s21_memset(void);
Suite *suite_s21_strrchr();
Suite *suite_s21_strstr();
Suite *suite_s21_strpbrk(void);
Suite *suite_s21_insert();
Suite *suite_s21_to_upper();
Suite *suite_s21_to_lower();
Suite *suite_s21_trim(void);
Suite *suite_s21_strcspn();
Suite *suite_s21_strncmp();
Suite *suite_s21_strncpy(void);
Suite *suite_s21_memcmp(void);
Suite *suite_s21_sprintf(void);
Suite *suite_s21_strtok(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
