#include "s21_string.h"
#include<stdio.h>

int main() {
    char data[1024];
    s21_sprintf(data,"%p",NULL);
    printf("%s",data);
    
    return 0;
}



