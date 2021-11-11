#include"sscanf.h"
#include<stdio.h>


int main() {
    int num = 1, num1 = 2, num2 = 3;
    int n = 1, n1, n2;
    double n3= 2.4;
    char s[100] =  "111 222 333";
    char s1[100] = "%1d%1d%d";
    int count = parser(s,s1,&num, &num1, &num2);
    sscanf(s,s1, &n, &n1, &n2);
    printf("num:%d\n",num);
    printf("num1:%d\n",num1);
    printf("num2:%d\n",num2);
    
    printf("n:%d\n",n);
    printf("n1:%d\n",n1);
    printf("n2:%d\n",n2);
    //printf("n2:%f\n",n3);
    printf(" count = %d\n",count);
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


int calling_function(char *str,parsing pars, va_list args, int *len_buf, int point) {
    switch (pars.type) {
        case 'd':
            point = d_func(str,pars,args,len_buf, point);
            break;
    
            
    }
    
    return point;
}


int parser(char *src,char *format, ...) {
    va_list args;
    int pointer = 0;
    parsing pars;
  
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
            pointer = calling_function(src,pars,args,&length_buf, pointer);
      
            
        }
    }
    
    
    va_end(args);
    return length_buf;
}


int d_func(char *str,parsing pars, va_list args, int *len_buf, int point) {
    int * num = va_arg(args,int *);
    int number;
    int length = 0;
    char *numbers = malloc((s21_strlen(str) + 1) * sizeof(char *));
    int index = 0;
    int i = point;
    int j = 0;
    int flag = 1;
    int flag_number = 1;
    

    while (flag) {
        printf("i :%d\n", i);
        if (str[i] == ' ' && flag == 1) {
            i++;
            continue;
        }

        if(str[i] == '\0') {
            break;
        }

        if (!def_number(str[i]) && str[i] != ' ') {
            flag_number = 2;
        }
                        
            printf("fn: %d\n", flag_number);
            printf("flag: %d\n", flag);


        if(def_number(str[i]) && flag_number == 1) {
            numbers[j] = str[i];
            //form_number(numbers,&length);
            //i = i + length + 1; 
            j++;
            flag = 2;
        }
        
        if(str[i] == ' ' && flag == 2)
            break;
        i++;
    }
    point = i;
    *len_buf +=1;
    number = form_number(numbers,&length);
    *num = number;
   // printf("\n%d\n",point);
//    printf("%d",number);
//
    return i;
}
