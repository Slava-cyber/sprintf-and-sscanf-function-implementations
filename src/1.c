#include "s21_string.h"
#include<stdio.h>

int main() {
    char data[100];
    char data1[100] = {"HEELLL"};
    s21_sprintf(data,"|%.2x",23323);
    sprintf(data1,"|%.2x|\n", 23323);
     
    printf(" data=%s\n",data);
    printf(" data1=%s\n",data1);
    return 0;
}



