#ifndef S21_STRING_H_
#define S21_STRING_H_

//#define NULL ((char *)0)
typedef unsigned s21_size_t;

//int sum(int a, int b);
void * s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s_21Strspn(const char* str1, const char* str2);
char * s_21Strchr(const char * str,int ch);
int s_21strcspn(const char * str1,const char * str2);
s21_size_t s21_strlen(const char *str);

#endif
