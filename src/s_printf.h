//#ifdef S_PRINTF_H
//#define S_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef unsigned s21_size_t;

struct convert
{
    char *sym;
    int (*f)(char *,va_list);
};
typedef struct convert conver_t;



void _write_char(char * buf,char c);
int parser(char *buf,const char *format, conver_t f_list[], va_list arg_list);
int _sprintf(char *buf,const char *format, ...);
int _sprintf_char(char *buf,va_list list);
//int _sprintf_integer(va_list);
//int _print_number(va_list args);
//int _sprint_octal(va_list list);
//unsigned int base_len(unsigned int num, int base);
//char *rev_string(char *s);
//void * s21_memcpy(void *dest, const void *src, s21_size_t n);
//void write_base(char *str);
//int _sprint_hex(va_list list);
//int hex_check(int num, char x);
//int _sprint_heX(va_list list);
//int _sprint_string(va_list list);
//int _sprint_percent(__attribute__((unused))va_list list);
//int _sprint_unsigned_integer(va_list list);
