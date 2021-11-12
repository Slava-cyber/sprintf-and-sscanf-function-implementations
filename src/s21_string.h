#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>


typedef unsigned s21_size_t;


//MARK: -dogletho
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
void *s21_to_lower(const char *str);


//MARK: - rleonard
char *s21_strcat(char *dest, const char *src);
void * s21_memchr(const void* buf,int val, s21_size_t num);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_insert(const char* src, const char* str, s21_size_t start_index);
void *s21_to_upper(const char* str);


//MARK: - lashlyn
void * s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strspn(const char* str1, const char* str2);
char * s21_strchr(const char * str,int ch);
s21_size_t  s21_strcspn(const char * str1,const char * str2);


//MARK: - laerion
char * s21_strtok(char *str, const char *delim);
void *s21_memset(void* str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);


//MARK: - dzoraida
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strerror(int errnum);


//MARK: - Sprintf

typedef struct {
    int plus;
    int gird;
    int minus;
    int zero;
    int space;
    int leng;
    int width;
    int point;
    int precision;
    int type;
    int star;
} parsing;


int def_number(char c);
int form_number(char *str, int *len);
int spec(char c);
int leng(char c);

int s21_sprintf(char *str, char *format, ...);

int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, int *len_buf, char *str, double number);
int u_func(parsing pars, va_list args, int *len_buf, char *str);
int n_func(va_list args, int length);

char convertTox(int value);
char convertToX(int value);
int convert(long unsigned num , long unsigned divider,char *data, char spec);
int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str);
int e_or_E_func(parsing pars, int *len_buf, char *str, double number);
int g_or_G_func(parsing pars, int *len_buf, char *str, double number);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
int p_func(parsing pars, va_list args, int *len_buf, char *str);

int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length);


#endif
