#include "s21_string.h"
#define NULL ((char *)0)

//MARK: - MEMCPY
void * s21_memcpy(void *dest, const void *src, s21_size_t n) {
    
    char *p = (char*)dest;
    char *p1 = (char*)src;
    while (n--) {
        *p = *p1;
        p++;
        p1++;
    }
    
    return dest;
}

//MARK: - STRLEN
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len;
}

//MARK: - STRCHR
char * s21_strchr(const char * str,int c) {
    
    char const * buf = NULL;
    while (*str) {
        if (*str == c) {
            break;
        }
        str++;
    }
    
    if (*str == c) {
        buf = str;
    }
    return (char *) buf;
    
}


//MARK: - STRSPN
s21_size_t s21_strspn(const char* str1, const char* str2) {
    s21_size_t n;
    const char* p;
    for(n = 0; *str1; str1++, n++) {
        for(p = str2; *p && *p != *str1; p++);
        if (!*p)
            break;
    }
    return n;
}

//MARK: - STRCAT
char *s21_strcat(char *dest, const char *src) {
    s21_size_t l = s21_strlen(dest);
    int x = 0;
    for (int i = 0 ; src[i] != '\0' ; i++) {
        dest[l + i] = src[i];
        x++;
    }
    dest[l + x] = '\0';
    return dest;
}

//MARK: - STRCSPN
s21_size_t s_21strcspn(const char * str1,const char * str2) {
    
    s21_size_t lentght1 = s21_strlen(str1);
    s21_size_t lentght2 = s21_strlen(str2);
    
    int supp = 0;
    s21_size_t i;
    s21_size_t count;
    
    for( i = 0;i < lentght1;i++) {
        if(supp) {
            break;
        }
        for(s21_size_t j =0;j < lentght2;j++) {
            if(str1[i] == str2[j]) {
                count = i;
                supp ++;
                break;
            }
        }
    }
    if(!supp) {
        count = i;
    }
    
    
    
    return count;
}
