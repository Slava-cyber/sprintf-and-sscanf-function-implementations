#include "s21_string.h"
#include <stdlib.h>
#include <ctype.h>
#define S21_NULL ((void *)0)
#if defined(__APPLE__)
    #define N 106
    #define error {"Undefined error: 0", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"Device not configured", \
"Argument list too long", \
"Exec format error", \
"Bad file descriptor", \
"No child processes", \
"Resource deadlock avoided", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Resource busy", \
"File exists", \
"Cross-device link", \
"Operation not supported by device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system", \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Result too large", \
"Resource temporarily unavailable", \
"Operation now in progress", \
"Operation already in progress", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol family", \
"Address already in use", \
"Can't assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Socket is already connected", \
"Socket is not connected", \
"Can't send after socket shutdown", \
"Too many references: can't splice", \
"Operation timed out", \
"Connection refused", \
"Too many levels of symbolic links", \
"File name too long", \
"Host is down", \
"No route to host", \
"Directory not empty", \
"Too many processes", \
"Too many users", \
"Disc quota exceeded", \
"Stale NFS file handle", \
"Too many levels of remote in path", \
"RPC struct is bad", \
"RPC version wrong", \
"RPC prog. not avail", \
"Program version wrong", \
"Bad procedure for program", \
"No locks available", \
"Function not implemented", \
"Inappropriate file type or format", \
"Authentication error", \
"Need authenticator", \
"Device power is off", \
"Device error", \
"Value too large to be stored in data type", \
"Bad executable (or shared library)", \
"Bad CPU type in executable", \
"Shared library version mismatch", \
"Malformed Mach-o file", \
"Operation canceled", \
"Identifier removed", \
"No message of desired type", \
"Illegal byte sequence", \
"Attribute not found", \
"Bad message", \
"EMULTIHOP (Reserved)", \
"No message available on STREAM", \
"ENOLINK (Reserved)", \
"No STREAM resources", \
"Not a STREAM", \
"Protocol error", \
"STREAM ioctl timeout", \
"Operation not supported on socket", \
"Policy not found", \
"State not recoverable", \
"Previous owner died", \
"Interface output queue is full"}
#elif defined(__linux__)
    #define N 133
    #define error {"Success", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"No such device or address", \
"Argument list too long", \
"Exec format error", \
"Bad file descriptor", \
"No child processes", \
"Resource temporarily unavailable", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Device or resource busy", \
"File exists", \
"Invalid cross-device link", \
"No such device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system", \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Numerical result out of range", \
"Resource deadlock avoided", \
"File name too long", \
"No locks available", \
"Function not implemented", \
"Directory not empty", \
"Too many levels of symbolic links", \
"Unknown error 41", \
"No message of desired type", \
"Identifier removed", \
"Channel number out of range", \
"Level 2 not synchronized", \
"Level 3 halted", \
"Level 3 reset", \
"Link number out of range", \
"Protocol driver not attached", \
"No CSI structure available", \
"Level 2 halted", \
"Invalid exchange", \
"Invalid request descriptor", \
"Exchange full", \
"No anode", \
"Invalid request code", \
"Invalid slot", \
"Unknown error 58", \
"Bad font file format", \
"Device not a stream", \
"No data available", \
"Timer expired", \
"Out of streams resources", \
"Machine is not on the network", \
"Package not installed", \
"Object is remote", \
"Link has been severed", \
"Advertise error", \
"Srmount error", \
"Communication error on send", \
"Protocol error", \
"Multihop attempted", \
"RFS specific error", \
"Bad message", \
"Value too large for defined data type", \
"Name not unique on network", \
"File descriptor in bad state", \
"Remote address changed", \
"Can not access a needed shared library", \
"Accessing a corrupted shared library", \
".lib section in a.out corrupted", \
"Attempting to link in too many shared libraries", \
"Cannot exec a shared library directly", \
"Invalid or incomplete multibyte or wide character", \
"Interrupted system call should be restarted", \
"Streams pipe error", \
"Too many users", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol", \
"Address already in use", \
"Cannot assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Transport endpoint is already connected", \
"Transport endpoint is not connected", \
"Cannot send after transport endpoint shutdown", \
"Too many references: cannot splice", \
"Connection timed out", \
"Connection refused", \
"Host is down", \
"No route to host", \
"Operation already in progress", \
"Operation now in progress", \
"Stale file handle", \
"Structure needs cleaning", \
"Not a XENIX named type file", \
"No XENIX semaphores available", \
"Is a named type file", \
"Remote I/O error", \
"Disk quota exceeded", \
"No medium found", \
"Wrong medium type", \
"Operation canceled", \
"Required key not available", \
"Key has expired", \
"Key has been revoked", \
"Key was rejected by service", \
"Owner died", \
"State not recoverable", \
"Operation not possible due to RF-kill", \
"Memory page has hardware error"}
#endif

// MARK: - memcpy
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
// MARK: - strlen
s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++)
    {};
    return len;
}
// MARK: - strchr
char* s21_strchr(const char * str, int c) {
    char const * buf = S21_NULL;
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
// MARK: - strspn
s21_size_t s21_strspn(const char* str1, const char* str2) {
    s21_size_t n;
    const char* p;
    for (n = 0; *str1; str1++, n++) {
        for (p = str2; *p && *p != *str1; p++)
        {};
        if (!*p)
            break;
    }
    return n;
}
// MARK: - strcat
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
// MARK: - wchstrcat
char *s21_wchstrcat(char *dest, const wchar_t *src) {
    s21_size_t l = s21_strlen(dest);
    int x = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[l + i] = src[i];
        x++;
    }
    dest[l + x] = '\0';
    return dest;
}
// MARK: - strcspn
s21_size_t s21_strcspn(const char * str1, const char * str2) {
    s21_size_t lentght1 = s21_strlen(str1);
    s21_size_t lentght2 = s21_strlen(str2);
    int supp = 0;
    s21_size_t i;
    s21_size_t count;
    for (i = 0; i < lentght1; i++) {
        if (supp) {
            break;
        }
        for (s21_size_t j =0; j < lentght2; j++) {
            if (str1[i] == str2[j]) {
                count = i;
                supp++;
                break;
            }
        }
    }
    if (!supp) {
        count = i;
    }
    return count;
}
// MARK: - memcmp
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *str1_1 = (unsigned char *)str1;
    unsigned char *str2_1 = (unsigned char *)str2;
    int flag = 0;
    while (n--) {
        if (*str1_1 != *str2_1) {
            flag = (int)(*str1_1 - *str2_1);
            n = 0;
        }
        str1_1++;
        str2_1++;
    }
    return flag;
}
// MARK: - strncat
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
// MARK: - strncpy

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
// MARK: - strrchr
char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
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
// MARK: - memmove
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *s_dest = (char*) dest;
    const char *s_src = (char*) src;
    if (s_dest <= s_src || s_dest >= s_src + n) {
        while (n--) {
            *s_dest = *s_src;
            s_dest++;
            s_src++;
        }
    } else {
        s_dest = s_dest + n - 1;
        s_src = s_src + n - 1;
        while (n--) {
            *s_dest = *s_src;
            s_dest--;
            s_src--;
        }
    }
    return dest;
}
// MARK: - strcmp
int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++) {}
    int result =  *str1 - *str2;
    return result;
}
// MARK: - strstr
char *s21_strstr(const char *haystack, const char *needle) {
    const char *buf;
    int flag = 0;
    if (haystack == S21_NULL || needle == S21_NULL) {
        buf = S21_NULL;
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
        buf = S21_NULL;
    }
    return (char*)buf;
}
// MARK: - strtok
char * s21_strtok(char *str, const char *delim) {
    char* next = S21_NULL;
    if (*str) {
        next = str;
        while ( *next && s21_strchr(delim, *next) )
            *next++ = '\0';
    }
    if (!*next)
        str = S21_NULL;

    str = next;
    while ( *next && !s21_strchr(delim, *next) )
        ++next;
    while ( *next && s21_strchr(delim, *next) )
        *next++ = '\0';
    return str;
}
// MARK: - memset
void *s21_memset(void* str, int c, s21_size_t n) {
    char *s = (char*) str;
    for (s21_size_t i = 0; i < n; i++) {
        s[i] = c;
    }
    return 0;
}
// MARK: - strncmp
int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
    const char* end = str1 + n;
    int result = 0;
    for (; result == 0 && str1 != end && (*str1 || *str2); result = *(str1++)-*(str2++))
    {};
    return result;
}
// MARK: - memchr
void *s21_memchr(const void *str, int c, s21_size_t n) {
    char* result;
    int flag = 1;
    for (s21_size_t i = 0; i <= n && flag != 0; i++) {
        if (*((char*)str + i) != c) {
            i++;
        } else {
            flag = 0;
            result = (char*)str + i;
        }
    }
    if (flag == 1) {
        result = S21_NULL;
    }
    return result;
}
// MARK: - strcpy
char *s21_strcpy(char *str1, const char *str2) {
    int i = 0;
    while (*(str2 + i) != '\0') {
        *(str1 + i) = *(str2 + i);
        i++;
    }
    *(str1 + i) = '\0';
    return str1;
}
// MARK: - strpbrk
char *s21_strpbrk(const char *str1, const char *str2) {
    int flag = 0;
    char* result = S21_NULL;
    for (int i = 0; str1[i] != '\0' && flag == 0; i++) {
        for (int j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                flag++;
                result = (char*)str1 + i;
            }
        }
    }
    return result;
}
// MARK: - strerror
char *s21_strerror(int errnum) {
    static char *arr[] = error;
    static char res[100];
    int i = 15;
    if (errnum < 0 || errnum > N) {
        int del;
        char ost[10]= "";
        char str[40] = "Unknown error: ";
        s21_memcpy(res, str, i);
        if (errnum < 0) {
            del = errnum * (-1);
            s21_memcpy(res + 15, "-", 1);
            i++;
        } else {
            del = errnum;
        }
        int n = 0;
        while (del / 10 != 0) {
            ost[n] = del % 10 + 48;
            del = del / 10;
            n++;
        }
        ost[n] = del + 48;
        for (int j = n; j >= 0; j--) {
            s21_memcpy(res + i, ost + j, 1);
            i++;
        }
        res[i] = '\0';
    } else {
        for (s21_size_t i = 0; i < 101; i++) {
            res[i] = '\0';
        }
        s21_memcpy(res, arr[errnum], s21_strlen(arr[errnum]));
    }
    return res;
}
// MARK: - to_upper
void *s21_to_upper(const char* str) {
    char c;
    int x = 0;
    char* result = S21_NULL;
    if (str != S21_NULL) {
        result = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 97 && str[i] <= 122) {
                result[i] = str[i];
                c = result[i];
                c = c - 32;
                result[i] = c;
            } else {
                result[i] = str[i];
            }
            x++;
        }
        result[x] = '\0';
    }
    return result;
}
// MARK: - insert
void *s21_insert(const char* src, const char* str, s21_size_t start_index) {
    char *result = S21_NULL;
    int x = 0;
    if (str != S21_NULL && src != S21_NULL && start_index <= s21_strlen(src)) {
        result = (char*)malloc((s21_strlen(str) + s21_strlen(src) + 1) * sizeof(char));
        for (int i = 0; *src || *str; i++) {
            if (src[i] == src[start_index] && *str) {
                start_index++;
                result[i] = *(str++);
            } else {
                result[i] = *(src++);
            }
            x++;
        }
        result[x] = '\0';
    }
    return result;
}
// MARK: - to_lower
void *s21_to_lower(const char *str) {
    char *lower_str = S21_NULL;
    if (str != S21_NULL) {
        int len = s21_strlen(str);
        lower_str = (char *)malloc(len * sizeof(char));
        int i = 0;
        while (i <= len) {
            if (str[i] >=65 && str[i] <= 91) {
                lower_str[i] = str[i] + 32;
            } else  {
                lower_str[i] = str[i];
            }
            i++;
        }
    } else {
    }
    return lower_str;
}
// MARK: - Trim
int isthere(char c, const char *trim_chars) {
    int res = 0;
    if ((trim_chars != S21_NULL) && (s21_strlen(trim_chars) > 0)) {
            int len = s21_strlen(trim_chars);
    for (int i = 0; i <=len; i++) {
        if (trim_chars[i] == c) {
            res = 1;
        }
    }
    } else {
       res = isspace(c);
    }
    return res;
}
void *s21_trim(const char *src, const char *trim_chars)  {
    char *result = S21_NULL;
    int i = 0, start_n = -1, temp = 0;
    if (src != S21_NULL) {
       int len = s21_strlen(src);
       int last_n = len;
       while (i <= len) {
           if (isthere(src[i], trim_chars) == 1) {
                start_n = i;
                i++;
            } else {
                i = len+1;
            }
       }
       i = len-1;
       while (i >= 0) {
           if (isthere(src[i], trim_chars) == 1) {
               last_n = i;
               i--;
           } else {
               i = -1;
           }
       }
       i = 0;
       result = (char *)calloc(1, sizeof(char*));
       for (int j = start_n+1; j < last_n; j++) {
           result = (char *)realloc(result, (temp+2)*sizeof(char*));
           result[temp] = src[j];
           temp++;
       }
       result[temp] = '\0';
       }
    return result;
}
