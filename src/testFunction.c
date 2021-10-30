#include "../groupProject/s21_string.h"
#include<stdio.h>


void testMemcpy() {
    char destination[15] ;
    char * src = "HELLO WORLD";
    s21_memcpy(destination,src,11);
    printf("%s",destination);
    
  
}


void testStrchr() {
    char *src = "HELLO WORLD";
    char *data = s_21Strchr(src,'O');
    printf("%s",data);
}

void testStrcspn() {
    char str1 [10]= "123456789";
    char str2 [10]= "452";
    int count = s_21strcspn(str1,str2);
    printf("%d",count);
    
}


void testLenght() {
    char *src = "HELLO WORLD";
    s21_size_t count =  s21_strlen(src);
    printf("%u",count);
}

void testStrspn() {
    char *src = "12345";
    char *digit = "123q4й5";
    s21_size_t count = s_21Strspn(src,digit);
    printf("%d",count);
    
}


int main() {
    testMemcpy();
    return 0;
}
