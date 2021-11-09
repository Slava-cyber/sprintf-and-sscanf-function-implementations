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


int parser(char *str, char *format, ...);

int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str);
int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str);
int f_func(parsing pars, va_list args, int *len_buf, char *str);
int u_func(parsing pars, va_list args, int *len_buf, char *str);
int n_func(va_list args, int length);
int s_func(parsing pars, va_list args, int *len_buf, char *str);
int p_func(parsing pars, va_list args, int *len_buf, char *str);

char convertTox(int value);
char convertToX(int value);
int convert(unsigned long num ,unsigned  long divider,char *data, char spec);
int x_func(parsing pars, va_list args, int *len_buf, char *str);
int X_func(parsing pars, va_list args, int *len_buf, char *str);
int o_func(parsing pars, va_list args, int *len_buf, char *str);
int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length);


int main() {
    char *str = NULL;
    int num = 1532;
    str = (char*)malloc(200 * sizeof(char));
    printf("%40.30p\n",&num);
    parser(str,"%020p",&num);
    printf("%s",str);
    free(str);
    return 0;
}






char convertToX(int value) {
    char ch;
    if (value > 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 55;
    }
    return ch;
}

char convertTox(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 87;
    }
    return ch;
}

 int convert(unsigned long num ,unsigned  long divider,char *data, char spec) {
    
    //int res = num;
    unsigned long rem = num;
    char ch;
    int index = 0;
    
    while (num) {
        rem = num%divider;
        num = num /divider;
        if(spec == 'x' || spec == 'o' ){
            ch = convertTox(rem);
        }
        if  (spec == 'X') {
            ch = convertToX(rem);
        }
        data[index] = ch;
        index ++;       
    }
    return index - 1;
}


int p_func(parsing pars, va_list args, int *len_buf, char *str) {
    
    int size = 0;
    unsigned long num = va_arg(args,unsigned long);
    char *data = malloc(sizeof(char *));
    char *reverse = malloc(sizeof(char *));
    char *src = malloc(sizeof(char *));
    char *tmp = malloc(sizeof(char *));
    int index = convert(num,16,data,'x');
    
    for(int i = index; i >= 0; i--)
        reverse[index - i] = data[i];
    
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    s21_strcat(src,reverse);

    
    if(pars.width) {
        if(pars.width > s21_strlen(src)) {
            size = pars.width - s21_strlen(src);
        }
        if(pars.minus) {
            for(int i = 0; i < s21_strlen(src);i++) {
                str[i] = src[i];
            }
            for(int j = s21_strlen(src);j < pars.width;j++) {
                str[j] = ' ';
            }
        } else {
            for(int i = 0; i < s21_strlen(src);i++) {
                tmp[i] = src[i];
            }
            for(int i = 0; i < size ;i++) {
                str[i] = ' ';
            }
            int index = 0;
            for(int i = size;i< size + s21_strlen(tmp);i++) {
                str[i] =  tmp[index];
                index++;
            }
        }
    } else {
        for(int i = 0; i < s21_strlen(src);i++) {
            str[i] = src[i];
        }
    }
        *len_buf = s21_strlen(str);
    
    free(data);
    free(reverse);
    free(src);
    free(tmp);
    return 0;

}


int s_func(parsing pars, va_list args, int *len_buf, char *str) {
    int size = 0;
    char *src;
    src = va_arg(args,char *);
    char *tmp = malloc(sizeof(char*));
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
        free(dest);
        if(pars.width) {
            if(pars.width > s21_strlen(src)) {
                size = pars.width - s21_strlen(src);
            }
            if(pars.minus) {
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                }
                for(int j = s21_strlen(src);j < pars.width;j++) {
                    str[j] = ' ';
                }
            } else {
                for(int i = 0; i < s21_strlen(src);i++) {
                    tmp[i] = src[i];
                }
                for(int i = 0; i < size ;i++) {
                    str[i] = ' ';
                }
                int index = 0;
                for(int i = size;i< size + s21_strlen(tmp);i++) {
                    str[i] =  tmp[index];
                    index++;
                }
            }
        } else {
            for(int i = 0; i < s21_strlen(src);i++) {
                str[i] = src[i];
            }
        }
    } else {
        if(pars.width) {
            if(pars.width > s21_strlen(src)) {
                size = pars.width - s21_strlen(src);
            }
            if(pars.minus) {
                for(int i = 0; i < s21_strlen(src);i++) {
                    str[i] = src[i];
                    
                }
                for(int j = s21_strlen(src);j < pars.width;j++) {
                    str[j] = ' ';
                }
            } else {
                for(int i = 0; i < s21_strlen(src);i++) {
                    tmp[i] = src[i];
                }
                for(int i = 0; i < size ;i++) {
                    str[i] = ' ';
                }
                int index = 0;
                for(int i = size;i < size + s21_strlen(tmp);i++) {
                    str[i] =  tmp[index];
                    index++;
                }
            }
        } else {
            for(int i = 0; i < s21_strlen(src);i++) {
                str[i] = src[i];
            }
        }
    }
    free(tmp);
    if (pars.width) {
        if(pars.width > s21_strlen(str)) {
            *len_buf = pars.width ;
        } else {
            *len_buf = s21_strlen(str);
        }
    }
    else {
        *len_buf = s21_strlen(str);
    }
    return 1;
}



int x_func(parsing pars, va_list args, int *len_buf, char *str) {
      unsigned long  number = va_arg(args,unsigned long );
   
    char *data = malloc(sizeof(char *));

    int index = convert(number, 16, data, 'x');
    printf("index:%d\n", index);
    for(int i = index; i >= 0; i--)
        str[index - i] = data[i];
    
    str[index + 1] = '\0';
    int i = index+1;

    if (pars.point) {
        pars.zero = 0;
    }

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
    if (pars.gird) {
        len = pars.precision + 2;
    } else {
        len = pars.precision;
    }

    printf("len:%d\n", len);
    printf("plus:%d\n", pars.plus);

    // str after with precision 
    if (pars.gird) {
        memmove(str + 2, str, pars.precision);
        str[0] = '0';
        str[1] = 'x';
        str[pars.precision + 2] = '\0';
    } else {
        str[pars.precision] = '\0';
    }
    
    

    printf("strafterprecision:%s\n", str);
    printf("pars.minus:%d\n", pars.minus);

    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            printf("precision:%d\n", pars.precision);
            memmove(str + pars.width - len, str, len);
            printf("str:%s\n", str);
            printf("zero:%d\n", pars.zero);
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.gird) {
                    str[0] = '0';
                    str[1] = 'x'; 
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                    
                    printf("str:%s\n", str);

                if (pars.gird) {
                    str[pars.width - pars.precision - 1] = 'x';
                    str[pars.width - pars.precision - 2] = '0';
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
    free(data);   
    return *len_buf;
}



int X_func(parsing pars, va_list args, int *len_buf, char *str) {
    unsigned number = va_arg(args,unsigned);

    printf("unsig:%u\n", number);
    // form number 16-system
    char *data = malloc(sizeof(char *));
    int index = convert(number, 16, data, 'X');
    printf("index:%d\n", index);
    for(int i = index; i >= 0; i--)
        str[index - i] = data[i];
    
    str[index + 1] = '\0';
    int i = index+1;

    if (pars.point) {
        pars.zero = 0;
    }

    // precision solve
    if (pars.precision > i) {
        memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }

    printf("str:%s\n", str);

    // consider plus
    int len;
    if (pars.gird) {
        len = pars.precision + 2;
    } else {
        len = pars.precision;
    }

    printf("len:%d\n", len);
    printf("plus:%d\n", pars.plus);

    // str after with precision
    if (pars.gird) {
        memmove(str + 2, str, pars.precision);
        str[0] = '0';
        str[1] = 'x';
        str[pars.precision + 2] = '\0';
    } else {
        str[pars.precision] = '\0';
    }
    
    

    printf("strafterprecision:%s\n", str);
    printf("pars.minus:%d\n", pars.minus);

    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            printf("precision:%d\n", pars.precision);
            memmove(str + pars.width - len, str, len);
            printf("str:%s\n", str);
            printf("zero:%d\n", pars.zero);
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.gird) {
                    str[0] = '0';
                    str[1] = 'x';
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                    
                    printf("str:%s\n", str);

                if (pars.gird) {
                    str[pars.width - pars.precision - 1] = 'x';
                    str[pars.width - pars.precision - 2] = '0';
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
    free(data);
    return *len_buf;
}



int o_func(parsing pars, va_list args, int *len_buf, char *str) {
    unsigned number = va_arg(args,unsigned);

    printf("unsig:%u\n", number);
    // form number 16-system
    char *data = malloc(sizeof(char *));
    int index = convert(number, 8, data, 'o');
    printf("index:%d\n", index);
    for(int i = index; i >= 0; i--)
        str[index - i] = data[i];
    
    str[index + 1] = '\0';
    int i = index+1;

    if (pars.point) {
        pars.zero = 0;
    }

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
    if (pars.gird) {
        len = pars.precision + 2;
    } else {
        len = pars.precision;
    }
    
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            memmove(str + pars.width - len, str, len);
           
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
               
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                    
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
    free(data);
    return *len_buf;
}




int n_func(va_list args, int length) {
    int *number = va_arg(args, int*);
    *number = length;
    return 1;
}


int u_func(parsing pars, va_list args, int *len_buf, char *str) {
    printf("here\n");
    
    if (pars.point) {
        pars.zero = 0;
    }
    unsigned int number = va_arg(args, unsigned int);

    // parsing number
    unsigned int buf = number;
    int i = 0;
    int buff[100];
    while (buf) {
        buff[i] = buf % 10;
        buf = buf / 10;
        i++;
    }

    // switch numbers to the right direction
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';

    printf("str:%s\n", str);
    printf("i:%d\n", i);

    printf("precision:%d\n", pars.precision);

    // precision solve
    if (pars.precision > i) {
        memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }

    printf("str:%s\n", str);

    int len = pars.precision;
    str[pars.precision] = '\0';

    printf("len:%d\n", len);
    printf("plus:%d\n", pars.plus);

    // str after with precision 

    printf("strafterprecision:%s\n", str);
    printf("pars.minus:%d\n", pars.minus);
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            printf("precision:%d\n", pars.precision);
            memmove(str + pars.width - len, str, len);
            printf("str:%s\n", str);
            printf("zero:%d\n", pars.zero);

            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                    printf("str:%s\n", str);//+
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


int f_func(parsing pars, va_list args, int *len_buf, char *str) {
    double number = va_arg(args, double);
    printf("number%.10f\n", number);
    
    // save sign
    char c;
    if (number < 0) {
        number = number * (-1);
        c = '-'; 
        pars.plus = 1;
        pars.space = 0;
    } else {
        c = '+'; 
    }

    // save precision
    if (!pars.point || pars.precision < 0) 
        pars.precision = 6;


    double buf, ost = modf(number, &buf);
    int buf1 = (int)buf;  
    int buff[100], buff1[100], i = 0, len;
    
    //parsing of whole part of number
    while (buf1) {
        buff1[i] = buf1 % 10;
        buf1 = buf1 / 10;
        i++;
    }

    int whole = i;

    printf("whole:%d\n", i);

    // switch to true direction
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];
    }
    
    // free buffer;
    for (int j = 0; j < 100; j++)
        buff1[j] = 0;

    printf("precision:%d\n\n", pars.precision);
    
    // add fraction part of number and parsing
    for(int j = 0; j <= pars.precision; j++) {
        ost = ost * 10.0; 
        ost = modf(ost, &buf);
        buff[i + j] = (int)buf; 
    }


    for (int j = 0; j <= i + pars.precision; j++) {
        printf("buff:%d\n", buff[j]);
    }


    printf("last:%d\n\n", buff[i + pars.precision]);
    
    // round using size of precision
    int all = i + pars.precision;
    if (buff[i + pars.precision] >= 5) {
        int flag = 1;
        while(flag) {
            all--;
            if (all == -1)
                break;
            buff[all]++;
            if (buff[all] > 9 && all != 0) {
                buff[all] = 0;
                continue;                         
            } else {
                break;
            }
        }
    }

    for (int j = 0; j <= i + pars.precision; j++) {
        printf("buff:%d\n", buff[j]);
    }

    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        for (int j = 1; j < whole + pars.precision; j++) 
            buff1[j + 1] = buff[j];
        whole++;
    } else {
        for (int j = 0; j < whole + pars.precision; j++) 
            buff1[j] = buff[j];
    }

    for (int j = 0; j < whole; j++) {
        str[j] = buff1[j] + 48;
        printf("buff1:%d\n", buff1[j] + 48);
    }

        printf("str:%s\n", str);
    printf("whole:%d\n", whole);

    // consider the existence of point
    if (!pars.precision) {
        str[whole] = '\0';
        len = whole;
    } else {
        str[whole] = '.';
        for (int j = 0; j < pars.precision; j++) {
            printf("drob:%d\n", buff1[whole+j]);
            str[whole + 1 + j] = buff1[whole + j] + 48;
        }
        str[whole + pars.precision  + 1] = '\0';
        len = whole + pars.precision + 1;
    }

    printf("strprom:%s\n", str);

    printf("len:%d\n", len);
    // consider plus and space
    int len1 = len;
    if (pars.plus || pars.space) {
        len1 = len + 1;
    }
    //pars.precision = i;

    if (pars.plus) {
        memmove(str + 1, str, len);
        str[0] = c;
        str[len + 1] = '\0';
    } else {
        if (pars.space) {
            memmove(str + 1, str, len);
            str[0] = ' ';
            str[len + 1] = '\0';
        } 
    } 
    
        printf("strafter:%s\n", str);
    
    
    
    if (pars.width > len) {
        if (!pars.minus) {
            printf("precision:%d\n", pars.precision);
            printf("len:%d\n", len);
                    printf("len1:%d\n", len1);

            printf("width%d\n", pars.width);
            memmove(str + pars.width - len1, str, len1);
            printf("str12:%s\n", str);
            printf("zero:%d\n", pars.zero);
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = '0';
                                printf("str:%s\n", str);
                if (pars.plus) {
                    str[0] = c;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = ' ';
                    
                    printf("str:%s\n", str);

                if (pars.plus) {
                    str[pars.width - len - 1] = c;
                }
            }
        } else {
            for (int j = len1; j < pars.width; j++) {
                str[j] = ' ';
            }
        }
        *len_buf = pars.width;
        str[pars.width] = '\0';
    } else {
        *len_buf = len1;
    }
    printf("strend:%s\n", str);
    return 1;
}

int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {
    printf("here\n");
    if (pars.point) {
        pars.zero = 0;
    }
    int number = va_arg(args, int);
    printf("number:%d\n", number);
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

    printf("str:%s\n", str);
    printf("i:%d\n", i);

    printf("precision:%d\n", pars.precision);

    // precision solve
    if (pars.precision > i) {
        memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }

    printf("str:%s\n", str);

    // consider plus 
    int len;
    if (pars.plus || pars.space) {
        len = pars.precision + 1;
    } else {
        len = pars.precision;
    }

    printf("len:%d\n", len);
    printf("plus:%d\n", pars.plus);

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
    printf("strafterprecision:%s\n", str);
    printf("pars.minus:%d\n", pars.minus);
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            printf("precision:%d\n", pars.precision);
            memmove(str + pars.width - len, str, len);
            printf("str:%s\n", str);
            printf("zero:%d\n", pars.zero);
            
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
                    
                    printf("str:%s\n", str);//+

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
   
        if (*format == '%') {
            
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
            //free bufer after last step
            for (int i = 0; i < 200; i++) 
                str_add[i]='\0';
                len_add = 0;

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
            
            calling_function(pars, args, &len_add, str_add, length);
            strcat(str, str_add);
           
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
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 112, 37};
    for (int i = 0; i <= 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

int leng(char c) {
    int result = 0;
    if (c == 'L' || c == 'l' || c == 'h') {
        result = 1;
    }
    return result;
}



int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length) {
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
        case 'u':
            u_func(pars, args, len_buf, str_add);
            break;
        case 'n':
            n_func(args, length);
            break;
        case 'x':
            x_func(pars, args, len_buf, str_add);
            break;
        case 's':
            s_func(pars,args,len_buf,str_add);
            break;
        case 'X':
            X_func(pars, args,len_buf,str_add);
            break;
        case 'o':
            o_func(pars,args,len_buf,str_add);
            break;
        case 'p':
            p_func(pars,args,len_buf,str_add);
            break;
            
       
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
        if (pars.zero) {
            for (int i = 0; i < pars.width - 1 ; i++)
                str[i] = '0';
        } else {
            for (int i = 0; i < pars.width - 1 ; i++)
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
