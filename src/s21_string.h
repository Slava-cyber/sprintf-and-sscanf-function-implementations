#ifndef S21_STRING_H_
#define S21_STRING_H_

//#define NULL ((char *)0)
typedef unsigned s21_size_t;


//MARK: -dogletho
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);


//MARK: - rleonard
char *s21_strcat(char *dest, const char *src);
void * s21_memchr(const void* buf,int val,s21_size_t num);
char *s21_strcpy(char *dest, const char *src);
char *s21_strpbrk(const char *str1, const char *str2);


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

#endif
