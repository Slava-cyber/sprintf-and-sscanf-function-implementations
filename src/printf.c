#include <stdio.h>
#include "s21_string.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned s21_size_t;

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
//typedef struct parsing parss;

int def_number(char c);
int form_number(char *str, int *len);
int spec(char c);
int leng(char c);

char *convert(unsigned int num, int base);

int parser(char *str, char *format, ...);

int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, va_list args, int *len_buf, char *str);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
double size_for_float(double number, int *whole, int *fraction);
int x_func(parsing pars, va_list args, int *len_buf, char *str);
int X_func(parsing pars, va_list args, int *len_buf, char *str);
int calling_function(parsing pars, va_list args, int *len_buf, char *str_add);
int o_func(parsing pars, va_list args, int *len_buf, char *str);

int main() {
    char *str = NULL;
    str = (char*)malloc(200 * sizeof(char));
    parser(str,"%o", 234);
    
    printf("\nout:%s", str);
    
    free(str);
    return 0;
}

int f_func(parsing pars, va_list args, int *len_buf, char *str) {
    printf("here\n");
    //int whole, fraction;
    double number = va_arg(args, double);
   
    
    char c;
    if (number < 0) {
        number = number * (-1);
        c = '-';
        pars.plus = 1;
        pars.space = 0;
    } else {
        c = '+';
    }
    
    if (!pars.point)
        pars.precision = 6;
    
    double buf;
    double ost = modf(number, &buf);
    int buf1 = (int)buf;
    int buff[100];
    int i = 0;
    int len;
    while (buf1) {
        buff[i] = buf1 % 10;
        buf1 = buf1 / 10;

        i++;
    }
    
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    if (!pars.precision) {
        str[i] = '\0';
        len = i;
    } else {
        str[i] = '.';
        for(int j = 1; j <= pars.precision; j++) {
            ost = ost * 10;
            ost = modf(ost, &buf);
            str[i + j] = (int)buf + 48;
        }
        i = i + pars.precision + 1;
    }
    str[i] = '\0';
 
    
    
    if (pars.plus || pars.space) {
        len = i + 1;
    } else {
        len = i;
    }
    pars.precision = i;
    
    if (pars.plus) {
        memmove(str + 1, str, i);
        str[0] = c;
        str[len] = '\0';
    } else {
        if (pars.space) {
            memmove(str + 1, str, i);
            str[0] = ' ';
            str[len + 1] = '\0';
        }
    }
    

    if (pars.width > len) {
        if (!pars.minus) {
  
            memmove(str + pars.width - len, str, len);
            
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.plus) {
                    str[0] = c;//+
                } else if (pars.space) {
                    str[0] = ' ';//+
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                
             
                
                if (pars.plus) {
                    str[pars.width - pars.precision - 1] = c;
                }
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}

int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {
    
    if (pars.point) {
        pars.zero = 0;
    }
    int number = va_arg(args, int);
  
    char c;
    if (number < 0) {
        number = number * (-1);
        c = '-';
        pars.plus = 1;
        pars.space = 0;
    } else {
        c = '+';
    }
    
    // size of number
    int buf = number;
    int i = 0;
    int buff[100];
    while (buf) {
        buff[i] = buf % 10;
        buf = buf / 10;
        i++;
    }
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    
 
    
    // precision solve
    if (pars.precision > i) {
        memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }
    
  
    
    // consider plus
    int len;
    if (pars.plus || pars.space) {
        len = pars.precision + 1;
    } else {
        len = pars.precision;
    }
    
    
    
    // str after with precision
    if (pars.plus) {
        memmove(str + 1, str, pars.precision);
        str[0] = c;
        str[pars.precision + 1] = '\0';
    } else {
        if (pars.space) {
            memmove(str + 1, str, pars.precision);
            str[0] = ' ';
            str[pars.precision + 1] = '\0';
        } else {
            str[pars.precision] = '\0';
        }
    }

    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            memmove(str + pars.width - len, str, len);
            
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.plus) {
                    str[0] = c;//+
                } else if (pars.space) {
                    str[0] = ' ';//+
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                
                
                if (pars.plus) {
                    str[pars.width - pars.precision - 1] = c;
                }
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}


int parser(char *str, char *format, ...) {
    va_list args;
    parsing pars;
    int len_add = 0;
    char *str_add;
    str_add = (char*)malloc(200*sizeof(char));
    int length = 0;
    va_start(args, format);
    
    while (*format) {
        //printf("%c", *format);
        // if '%' start the block
        if (*format == '%') {
            // the initialization of the struct
            pars.plus = 0;
            pars.gird = 0;
            pars.minus = 0;
            pars.zero = 0;
            pars.space = 0;
            pars.leng = 0;
            pars.width = 0;
            pars.point = 0;
            pars.precision = 0;
            pars.type = 0;
            pars.star = 0;
            
            format++;
            // start the filling struct using block
            int flag = 1;
            while (flag) {
                //printf("format%c\n", *format);
                //printf("min%d\n", pars.minus);
                //printf("wid%d\n", pars.width);
                // if after % will be ' '
                if (*format == ' ') {
                    if (!pars.plus)
                        pars.space = 1;
                    //*(str + length) = ' ';
                    //length++;
                    format++;
                    continue;
                }
                //if after % will be '0'
                if (*format == '0' && pars.width == 0 && pars.point == 0) {
                    pars.zero = 1;
                    format++;
                    continue;
                }
                // if after % will be '+'
                if (*format == '+') {
                    pars.plus = 1;
                    pars.space = 0;
                    format++;
                    continue;
                }
                //if after % will be '#'
                if (*format == '#') {
                    pars.gird = 1;
                    format++;
                    continue;
                }
                //if meet '.'
                if (*format == '.') {
                    pars.point = 1;
                    //pars.zero = 0;
                    format++;
                    // if we have *
                    if (*format == '*') {
                        pars.precision = va_arg(args, int);
                        format++;
                        continue;
                        //if we have to form number
                    } else {
                        int len = 0;
                        pars.precision = form_number(format, &len);
                        format = format + len;
                        continue;
                    }
                }
                // if meet '*' calculate width
                if (*format == '*') {
                    pars.star = 1;
                    pars.width = va_arg(args, int);
                    if ((pars.width < 0)) {
                        pars.width = (-1) * pars.width;
                        pars.minus = 1;
                        pars.zero = 0;
                    } else {
                    }
                    format++;
                    continue;
                }
                // if meet just digit
                if (def_number(*format)) {
                    if (pars.star == 1) {
                        pars.width = 0;
                        continue;
                    } else {
                        int len = 0;
                        pars.width = form_number(format, &len);
                        //printf("\nlen:%d\n", len);
                        //printf("\nlform:%c\n", *format);
                        
                        format = format + len;
                        continue;
                    }
                }
                // if we meet length block
                if (leng(*format)) {
                    pars.leng = *format;
                    format++;
                    continue;
                }
                
                //if after % will be '-'
                if (*format == '-') {
                    pars.minus = 1;
                    pars.zero = 0;
                    format++;
                    continue;
                }
                // if we meet spec
                if (spec(*format)) {
                    pars.type = *format;
                    format++;
                    flag = 0;
                    continue;
                }
                
            }
            // finish filling struct
            //  printf("mina%d\n", pars.minus);
            //printf("wida%d\n", pars.width);
            //printf("typer:%c\n", pars.type );
            // analyzing data and form str
            calling_function(pars, args, &len_add, str_add);
            strcat(str, str_add);
            //printf("len2:%d", len_add);
            //printf("\nstrfinnn:%s\n", str_add);
            
            //char_add(&str, str_add, length);
            //printf("adsdsa");
            length += len_add;
            //if we don't meet % just print symbols  until we can
        } else {
            *(str+length) = *format;
            //printf("format:%c\n %d\ns", *format, length);
            length++;
            format++;
            continue;
        }
    }
    //printf("lenout:%d", length);
    *(str+length) = '\0';
    //printf("outbef:%c", str[12]);
    va_end(args);
    free(str_add);
    return length;
}

int def_number(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

int form_number(char *str, int *len) {
    int factor = 0;
    char *tmp = str;
    int len1 = 0;
    while (def_number(*tmp)) {
        factor = (factor * 10) + (*tmp) - 48;
        tmp++;
        len1++;
    }
    *len = len1;
    return factor;
}

int spec(char c) {
    int result = 0;
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 11, 37};
    for (int i = 0; i <= 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

int leng(char c) {
    int result = 0;
    if (c == 'L' || c == 'I' || c == 'h') {
        result = 1;
    }
    return result;
}

char *convert(unsigned int num, int base) { 
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;
    
    ptr = &buffer[49];
    *ptr = '\0';
    
    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);
    
    return(ptr);
}


int calling_function(parsing pars, va_list args, int *len_buf, char *str_add) {
    
    switch(pars.type) {
        case 'c':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case '%':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case 'f':
            f_func(pars, args, len_buf, str_add);
            break;
        case 'd':
            d_or_i_func(pars, args, len_buf, str_add);
            break;
        case 'i':
            d_or_i_func(pars, args, len_buf, str_add);
            break;
        case 's':
            s_func(pars,args,len_buf,str_add);
            break;
        case 'x':
          x_func(pars,args,len_buf,str_add);
            break;
        case 'X':
            X_func(pars,args,len_buf,str_add);
            break;
        case 'o':
            o_func(pars,args,len_buf,str_add);
            break;
            /*case 'u':
             u_func(pars, args, len_buf, str_add);
             break;
             case 'd':
             d_func(str, length, pars);
             break;
             case 'd':
             d_func(str, length, pars);
             break;
             case 'd':
             d_func(str, length, pars);
             break;
             case 'd':
             d_func(str, length, pars);
             break;    */
    }
    return 1;
}

int s_func(parsing pars, va_list args, int *len_buf, char *str) {
    
    char *src;
    src = va_arg(args,char *);
    if(pars.precision || pars.point) {
        
        char *dest = malloc(sizeof(char*));
        
        if(pars.precision < 0) {
            dest = src;
        } else {
            for(int i = 0;i < pars.precision;i++) {
                dest[i] = src[i];
            }
        }
        if(pars.precision != 0 ) {
            src = dest;
        } else {
            src = " ";
        }
        
        if(pars.width) {
            
            int size = pars.width - s21_strlen(src);
            
            if(pars.minus) {
                
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                }
                for(int j = s21_strlen(src);j < pars.width;j++) {
                    str[j] = ' ';
                    
                }
            } else {
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                }
                for(int i = 0; i < size;i++) {
                    str[i + size] = str[i];
                }
                for(int i = 0;i< size;i++) {
                    str[i] = ' ';
                }
            }
        } else {
            for(int i = 0; i < s21_strlen(src);i++) {
                str[i] = src[i];
            }
        }
    } else {
        if(pars.width) {
            int size = pars.width - s21_strlen(src);
            if(pars.minus) {
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                }
                for(int j = s21_strlen(src);j < pars.width;j++) {
                    str[j] = ' ';
                }
            } else {
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                }
                
                for(int i = 0; i < size;i++) {
                    str[i + size] = str[i];
                }
                for(int i = 0;i< size;i++) {
                    str[i] = ' ';
                }
            }
        } else {
            for(int i = 0; i < s21_strlen(src);i++) {
                str[i] = src[i];
            }
        }
    }
    
    if (pars.width) {
        *len_buf = pars.width;
    }
    else {
        *len_buf = s21_strlen(str);
    }
    return 1;
}



int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str) {
    char c;
    if (pars.type == '%') {
        c = '%';
    } else {
        c = va_arg(args, int);
    }
    if (pars.width == 0)
        pars.width = 1;
    if (pars.minus) {
        str[0] = c;
        for (int i = 1; i < pars.width; i++) {
            str[i] = ' ';
        }
        str[pars.width] = '\0';
    } else {
        for (int i = 0; i < pars.width - 1 ; i++) {
            str[i] = ' ';
        }
        str[pars.width - 1] = c;
        str[pars.width] = '\0';
    }
    if (pars.width) {
        *len_buf = pars.width;
    }
    else {
        *len_buf = 1;
    }
    return 1;
}


int p_func(parsing pars, va_list args, int *len_buf, char *str) {
//
//    void * pointer =  va_arg(args,void *);

    return 1;
}


char convertTox(int value) {
    char ch;
    
    switch (value) {
        case 1:
           ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        case 10:
            ch = 'a';
            break;
        case 11:
            ch = 'b';
            break;
        case 12:
            ch = 'c';
            break;
        case 13:
            ch = 'd';
            break;
        case 14:
            ch = 'e';
            break;
        case 15:
            ch = 'f';
            break;
        default:
            break;
    }
    
    return ch;
}

char convertToX(int value) {
    char ch;
    
    switch (value) {
        case 1:
           ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        case 10:
            ch = 'A';
            break;
        case 11:
            ch = 'B';
            break;
        case 12:
            ch = 'C';
            break;
        case 13:
            ch = 'D';
            break;
        case 14:
            ch = 'E';
            break;
        case 15:
            ch = 'F';
            break;
        default:
            break;
    }
    return ch;
}

char convertToO(int value) {
    char ch;
    
    switch (value) {
        case 0:
            ch = 0;
            break;
        case 1:
           ch = '1';
            break;
        case 2:
            ch = '2';
            break;
        case 3:
            ch = '3';
            break;
        case 4:
            ch = '4';
            break;
        case 5:
            ch = '5';
            break;
        case 6:
            ch = '6';
            break;
        case 7:
            ch = '7';
            break;
        case 8:
            ch = '8';
            break;
        case 9:
            ch = '9';
            break;
        default:
            break;
    }
    return ch;
}



int x_func(parsing pars, va_list args, int *len_buf, char *str) {
    unsigned num = va_arg(args,unsigned);
    
    int res = num;
    int rem = num;
    int index = 0;
    char ch;
    char *data = malloc(sizeof(char *));
   
    
    
      
    do {
        rem = num%16;
        num = num /16;
        ch = convertTox(rem);
        data[index] = ch;
        index ++;

    } while (num >= 16);
    ch = convertTox(num);
    data[index] = ch;
   

    for(int i = index;i >= 0;i--) {
        printf("%c",data[i]);
        str[i] = data[i];
    }
        
    return 0;
}


int X_func(parsing pars, va_list args, int *len_buf, char *str) {
    
    unsigned num = va_arg(args,unsigned);
    
    int res = num;
    int rem = num;
    int index = 0;
    char ch;
    char *data = malloc(sizeof(char *));
      
    do {
        rem = num%16;
        num = num /16;
        ch = convertTox(rem);
        data[index] = ch;
        index ++;

    } while (num >= 16);
    ch = convertTox(num);
    data[index] = ch;
   
    
    

    for(int i = index;i >= 0;i--) {
        printf("%c",data[i]);
        str[i] = data[i];
    }

    printf("\n");
    
    for(int i = 0;i <= index;i++) {
        printf("%c",data[i]);
    }
    return 0;
}


int o_func(parsing pars, va_list args, int *len_buf, char *str) {
    
    unsigned num = va_arg(args,unsigned);
    
    int res = num;
    int rem = num;
    int index = 0;
    char ch;
    char *data = malloc(sizeof(char *));
      
    do {
        rem = num%8;
        num = num /8;
        ch = convertToO(rem);
        data[index] = ch;
        index ++;

    } while (num >= 8);
    ch = convertToO(num);
    data[index] = ch;
   
    
    for(int i = index;i >= 0;i--) {
        printf("%c",data[i]);
        str[i] = data[i];
    }

    printf("\n");
    
//    for(int i = 0;i <= index;i++) {
//        printf("%c",data[i]);
//    }
    return 0;
}



double size_for_float(double number, int *whole, int *fraction) {
    double buf;
    double ost = modf(number, &buf);
    int buf1 = (int)buf;
    printf("buf:%d\n", buf1);
    int i = 0;
    while (buf1) {
        buf1 = buf1 / 10;
        printf("\nbuf:%d\n", buf1);
        i++;
    }
    *whole = i;
    printf("whole:%d\n", *whole);
    printf("ost:%f\n", ost);
    double ost_to_save = ost;
    i = 0;
    while(modf(ost, &buf)!=0) {
        ost = ost * 10;
        printf("ost:%f\n", ost);
        i++;
    }
    *fraction = i;
    printf("fraction:%d\n", *fraction);
    ost_to_save = ost * (*fraction);
    return ost_to_save;
}
