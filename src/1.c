#include "s21_string.h"
#include<stdio.h>

int main() {
    char data[1024];
    s21_sprintf(data,"%10s","Hello");
    printf("%s",data);
    
    return 0;
}



