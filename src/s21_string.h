#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <check.h>

typedef unsigned s21_size_t;
// MARK: - dogletho
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_wchstrcat(char *dest, const wchar_t *src);
// MARK: - rleonard
char *s21_strcat(char *dest, const char *src);
void * s21_memchr(const void* buf, int val, s21_size_t num);
char *s21_strcpy(char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
void *s21_insert(const char* src, const char* str, s21_size_t start_index);
void *s21_to_upper(const char* str);
// MARK: - lashlyn
void * s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strspn(const char* str1, const char* str2);
char * s21_strchr(const char * str, int ch);
s21_size_t  s21_strcspn(const char * str1, const char * str2);
// MARK: - laerion
char * s21_strtok(char *str, const char *delim);
void *s21_memset(void* str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
// MARK: - dzoraida
void *s21_memmove(void *dest, const void *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strerror(int errnum);
// MARK: - Sprintf
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
long double subst_input(parsing pars, va_list args);
char sign_func_subst(long double *number, int *plus, int *space);
int whole_part(long double number, int *buff);
int round_number(int *buff, int len, int *buff1, int *whole);
int str_form(parsing pars, int *buff1, int whole, char c, char *str, int *len_str);
int consider_g(char *str, int *len_str, int *len, int from_g_gird);
int form_power(int power, char e, char *str, int *len_buf);
int form_number_d(parsing pars, long int number, char *str);
int consider_precision_d(parsing pars, int i, char sign, char *str, int *precision);
int format_d(parsing pars, int len, char *str, char sign, int *len_buf);
int format_x(parsing pars, int len, char *str, int *len_buf);
char sign_func_whole(long int *number, int *plus, int *space);
int consider_precision_x(parsing pars, int i, int *precision, char *str);
int s21_sprintf(char *str, char *format, ...);
int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int u_func(parsing pars, va_list args, int *len_buf, char *str);
int n_func(va_list args, int length);
char convertTox(int value);
char convertToX(int value);
int convert(parsing pars, long unsigned num, long unsigned divider, char *data, char spec);
int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str);
int e_or_E_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
int p_func(parsing pars, va_list args, int *len_buf, char *str);
int g_or_G_func(parsing pars, int *len_buf, char *str, long double number);
int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length);
// MARK: - Sscanf
char convertToXScanf(int value);
char convertToxScanf(int value);
int convertScanf(long unsigned num, long unsigned divider, char *data, char spec);
int x_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int i_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int o_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int convertFrom16Scanf(char value);
int f_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int def_number_16Scanf(char c);
int def_number_8Scanf(char c);
int def_numberScanf(char c);
int lengScanf(char c);
int form_numberScanf(char *str, int * lenght);
int specScanf(char c);
int calling_functionScanf(char *str, parsing pars, va_list args, int *len_buf,
                          int point, int length, int *error);
int s21_sscanf(char *src, char *format, ...);
int d_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int lenght, int *error);
int c_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int s_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int n_funcScanf(va_list args, parsing pars, int point);
int p_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error);
int u_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int *error);

// MARK: - Suite
Suite *example_suite_create();
Suite *example_suite_create2();
Suite *f_example_suite_create();
Suite *sscanf_suite_create();
#endif  // SRC_S21_STRING_H_
