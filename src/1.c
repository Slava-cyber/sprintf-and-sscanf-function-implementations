#include "s21_string.h"
#include<stdio.h>

int main() {
<<<<<<< HEAD
    char data[100];
    char data1[100] = {"HEELLL"};
    s21_sprintf(data,"|%.2x",23323);
    sprintf(data1,"|%.2x|\n", 23323);
     
    printf(" data=%s\n",data);
    printf(" data1=%s\n",data1);
=======
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
    
>>>>>>> lashlyn_develop
    return 0;
}



