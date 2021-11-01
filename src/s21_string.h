#ifndef S21_STRING_H_
#define S21_STRING_H_

//#define NULL ((char *)0)
typedef unsigned s21_size_t;

char *s21_strcat(char *dest, const char *src);
void * s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strspn(const char* str1, const char* str2);
char * s21_strchr(const char * str,int ch);
s21_size_t  s_21strcspn(const char * str1,const char * str2);
s21_size_t s21_strlen(const char *str);

#endif
