CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
s21_STRING_C = s21_*.c 
s21_STRING_O = s21_*.o
SUITE_CASES_C = suite_*.c
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit



all: clean gcov_report

s21_string.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(s21_STRING_C) 
	ar rc s21_string.a $(s21_STRING_O)
	ranlib s21_string.a

test: s21_string.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c
# $(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_STRING_C) main.o $(SUITE_CASES_O) $(FLAG_TESTS) $(ASAN)
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_STRING_C) main.o $(SUITE_CASES_O) $(FLAG_TESTS)
	./tests

valgrind_test: s21_string.a
	$(CC) $(FLAG_C) $(FLAG_ER) $(SUITE_CASES_C) main.c -g
	$(CC) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests $(s21_STRING_C) main.o $(SUITE_CASES_O) $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./tests

gcov_report: test
	gcovr --html-details -o report.html

cpp_check:
	cppcheck --enable=all --force *.h *.c

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +
