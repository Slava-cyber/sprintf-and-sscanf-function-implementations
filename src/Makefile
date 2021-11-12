CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage


all:

test: Test
	./Test

gcov_report: Test
	./Test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage
	open coverage/index.html

Test: test.o s21_string.o s21_string.a
	$(CC) test.o s21_string.o s21_string.a -o Test -I../../.brew/include -L../../.brew/Cellar/check/0.15.2/lib -lcheck -fprofile-arcs -ftest-coverage

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c

test.o: test.c s21_string.h
	$(CC) -I$(HOME)/.brew/include $(CFLAGS) -c test.c

s21_string.a: s21_string.o
	ar -rcs s21_string.a s21_string.o

clean:
	rm -rf *.o *.a *.gcno *.gch *.gcda *.info coverage Test


rebuild: clean all









