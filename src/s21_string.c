#include "s21_string.h"
#define NULL ((char *)0)

//MARK: - memcpy
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

//MARK: - strlen
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len;
}

//MARK: - strchr
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


//MARK: - strspn
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

//MARK: - strcat
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

//MARK: - strcspn
s21_size_t s21_strcspn(const char * str1,const char * str2) {
    
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

//MARK: - memcmp
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *str1_1 = (unsigned char *)str1;
    unsigned char *str2_1 = (unsigned char *)str2;
    unsigned char flag = 0;
    while (n--) {
        if (*str1_1 != *str2_1) {
            return *str1_1 - *str2_1;
        }
        str1_1++;
        str2_1++;
    }
    return flag;
}

//MARK: - strncat


char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0, j = 0;
    while (dest[i])
        i++;
    while (j < n && src[j]) {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

//MARK: - strncpy

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        ++i;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}


//MARK: - strrchr

char *s21_strrchr(const char *str, int c) {
    char *res = NULL;
    int i = s21_strlen(str);
    while (i >= 0) {
        if (str[i] == (char)c) {
            res = ((char*)(str + i));
            i = 0;
        }
        i--;
    }
    return res;
}

//MARK: - memmove

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *s_dest = (char*) dest;
    const char *s_src = (char*) src;
    if (s_dest <= s_src || s_dest >= s_src + n) {
        while (n--) {
            *s_dest = *s_src;
            s_dest++;
            s_src++;
        }
        //*(s_dest+1) = '\0';
    } else {
        s_dest = s_dest + n - 1;
        //*(s_dest + 1) = '\0';
        s_src = s_src + n - 1;
        while (n--) {
            *s_dest = *s_src;
            s_dest--;
            s_src--;
        }
    }
    return dest;
}

//MARK: - strcmp

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    int result =  *str1 - *str2;
    return result;
}



//MARK: - strstr
char *s21_strstr(const char *haystack, const char *needle) {
    const char *buf;
    int flag = 0;
    if (haystack == NULL || needle == NULL) {
        buf = NULL;
    } else {
        int len = 0;
        while (*(needle + len)) {
            len++;
        }
        if (len == 0) {
            buf = haystack;
            flag = 1;
        } else {
            while (*haystack) {
                if (*haystack == *needle) {
                    int j = 0;
                    while (*haystack == *(needle + j) && *(needle + j) != '\0') {
                        j++;
                        haystack++;
                    }
                    if (j == len) {
                        flag = 1;
                        haystack = haystack - len;
                        break;
                    }
                } else {
                    haystack++;
                }
            }
            buf = haystack;
        }
    }
    if (!flag) {
        buf = NULL;
    }
    return (char*)buf;
}

//MARK: - strtok
char * s21_strtok(char *str, const char *delim) {
    char * next = NULL;
    
    
    if ( *str ) {
        next = str;
        while ( *next && s21_strchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! s21_strchr(delim, *next) )
        ++next;
    while ( *next && s21_strchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}

//MARK: -memset
void *s21_memset(void* str, int c, s21_size_t n) {
    char *s = (char* ) str;
    for (s21_size_t i = 0; i < n; i++) {
        s[i] = c;
    }
    return 0;
}

//MARK: - strncmp

int s21_strncmp(const char* str1, const char* str2, s21_size_t n)
{
    const char* end = str1 + n;
    int result = 0;
    for(;result == 0 && str1 != end && (*str1 || *str2); result = *(str1++)-*(str2++));
    return result;
}

//MARK: - memchr

void *s21_memchr(const void *str, int c, s21_size_t n) {
    char* result;
    int flag = 1;
    for (s21_size_t i = 0; i <= n && flag != 0; i++) {
        if(*((char*)str + i) != c) {
            i++;
        } else {
            flag = 0;
            result = (char*)str + i;
        }
    } if(flag == 1){
        result = NULL;
    }
    return result;
}


//MARK: - strcpy

char *s21_strcpy(char *dest, const char *src) {
    s21_size_t l = s21_strlen(src);
    for (s21_size_t i = 0 ; i <= l && dest[i] != '\0'; i++) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            dest[i] = '\0';
        }
    }
    return dest;
}

//MARK: - strpbrk

char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char* result = NULL;
    for (int i = 0; str1[i] != '\0' && flag == 0; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if(str1[i] == str2[j]) {
                flag++;
                result = (char*)str1 + i;
            }
        }
    }
    return result;
}
