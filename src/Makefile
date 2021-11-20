CC=gcc
CFLAGS=-c -Wall -Werror -Wextra

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
else
	LINUX_LIBS=
endif

all: clean s21_string.a test

s21_string.a: s21_string.o s21_sscanf.o s21_sprintf.o
	@ar -rcs s21_string.a s21_string.o s21_sscanf.o s21_sprintf.o

test: s21_test.o test_sprintf.o test_string.o test_sscanf.o s21_string.a
	@$(CC) s21_test.o test_sscanf.o test_sprintf.o test_string.o s21_string.a -o Test -lcheck $(LINUX_LIBS)
	@./Test

gcov_report: s21_string.c s21_sprintf.c s21_sscanf.c test_string.c test_sprintf.c test_sscanf.c s21_test.c s21_string.h 
	$(CC) s21_test.c s21_string.c s21_sprintf.c s21_sscanf.c test_string.c test_sprintf.c test_sscanf.c -o Test -lcheck $(LINUX_LIBS) -fprofile-arcs -ftest-coverage 
	./Test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage
	open coverage/index.html

s21_string.o: s21_string.c s21_string.h
	@$(CC) $(CFLAGS) s21_string.c

s21_test.o: s21_string.h s21_test.c
	@$(CC) $(CFLAGS) s21_test.c

test_sprintf.o: s21_string.h test_sprintf.c
	@$(CC) $(CFLAGS) test_sprintf.c

test_string.o: s21_string.h test_string.c
	@$(CC) $(CFLAGS) test_string.c

test_sscanf.o: s21_string.h test_sscanf.c
	@$(CC) $(CFLAGS) test_sscanf.c

s21_sprintf.o: s21_sprintf.c s21_string.h
	@$(CC) $(CFLAGS) s21_sprintf.c

s21_sscanf.o: s21_sscanf.c s21_string.h
	@$(CC) $(CFLAGS) s21_sscanf.c

clean:
	@rm -rf *.o *.a *.gcno *.gch *.gcda *.info coverage Test


rebuild: clean all
