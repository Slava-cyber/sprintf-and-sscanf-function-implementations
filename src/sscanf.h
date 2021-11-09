#include<stdlib.h>
#include <stdarg.h>
#include "s21_string.h"


typedef unsigned s21_size_t;

typedef struct {
    int type;
    int star;
    int width;
    int leng;
    
} parsing;



int parser(char *src,char *format, ...);
int def_number(char c);
int leng(char c);
int form_number(char *str,int * lenght);
int spec(char c);
int calling_function(char *str,parsing pars, va_list args, int *len_buf,int point);
int d_func(char *str,parsing pars, va_list args, int *len_buf,int *point);
