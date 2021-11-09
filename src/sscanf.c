#include"sscanf.h"
#include<stdio.h>


int main() {
    int num;
    int count = parser(" 228","%d",&num);
    printf("%d",num);
    return 0;
}


int def_number(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
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


int form_number(char *str,int * lenght) {
    int factor = 0;
    char *tmp = str;
    int length1 = 0;
    while (def_number(*tmp)) {
        factor = (factor * 10) + (*tmp) - 48;
        tmp++;
        length1++;
    }
    *lenght = length1;
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


int calling_function(char *str,parsing pars, va_list args, int *len_buf,int point) {
    switch (pars.type) {
        case 'd':
            d_func(str,pars,args,len_buf,&point);
            break;
    
            
    }
    
    return 1;
}


int parser(char *src,char *format, ...) {
    va_list args;
    int pointer = 0;
    parsing pars;
    int rElements = 0;
    int length_buf = 0;
    va_start(args,format);
    
    while (*format) {
        
        // if we meet %
        if(*format == '%') {
            pars.type = 0;
            pars.star = 0;
            pars.width = 0;
            pars.leng = 0;
            
            format++;
            int flag = 1;
            
            while (flag) {
                // if we meet *
                if(*format == '*') {
                    pars.star = 1;
                    format++;
                    continue;
                }
                
                if(def_number(*format)) {
                    int len;
                    pars.width = form_number(format,&len);
                    format += len;
                    continue;
                }
                
                if(leng(*format)) {
                    pars.leng = *format;
                    format++;
                    continue;
                }
                
                if(spec(*format)) {
                    pars.type = *format;
                    format++;
                    flag = 0;
                    continue;
                }
                
                
            }
            calling_function(src,pars,args,&length_buf,pointer);
            rElements += length_buf;
            
        }
    }
    
    
    va_end(args);
    return rElements;
}


int d_func(char *str,parsing pars, va_list args, int *len_buf,int *point) {
    int * num = va_arg(args,int *);
    int number;
    int lenght = 0;
    char *numbers = malloc(sizeof(char *));
    int index = 0;

    
    for(int i = 0;i < s21_strlen(str) + 1;i++) {
        
        
        if(str[*point] == ' ' || str[*point] == '\0') {
            break;
        }
        
        if(def_number(str[*point])) {
            numbers[*point] = str[*point];
        }
        
       
        
        
        *point = i;
        
        
    }
    
    number = form_number(numbers,&lenght);
    *num = number;
    printf("\n%d\n",*point);
//    printf("%d",number);
//
    return 1;
}
