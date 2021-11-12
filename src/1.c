#include "s21_string.h"
#include<stdio.h>

int main() {
    char data[100] = {"HEELLL"};
    char data1[100] = {"HEELLL"};
    s21_sprintf(data,"%s\n","hejhdsjfgu");
    printf("%s\n",data);
    s21_sprintf(data,"fgsdg |%s| hdhsjg\n","hsjhjfgjshd");
    printf("%s\n\n",data);
    sprintf(data1,"%s\n","hejhdsjfgu");
    printf("%s\n",data1);
    sprintf(data1,"fgsdg |%s| hdhsjg\n","hsjhjfgjshd");
    printf("%s\n\n",data1);
    
    return 0;
}



