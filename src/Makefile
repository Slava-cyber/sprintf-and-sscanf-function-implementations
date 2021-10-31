CC=gcc
CFLAGS=-c -Wall -Werror -Wextra



all: String s21_string.o
	$(CC) testFunction.o s21_string.o  -o ../src/all 

test: Test
	./Test



s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) s21_string.c



String: s21_string.c
	$(CC) $(CFLAGS) testFunction.c

Test: test.o s21_string.o
	gcc -o Test s21_string.o test.o -I../../.brew/include -L../../.brew/Cellar/check/0.15.2/lib -lcheck

test.o: test.c s21_string.h
	gcc -I$(HOME)/.brew/include $(CFLAGS) -c test.c

clean:
	rm -rf *.o 

rebuild: clean all









