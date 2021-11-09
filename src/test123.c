
#include<stdio.h>
#include<stdlib.h>
//double pi = 3.141592653589793;



int main() {
//    unsigned num  = 1434;
//    char src[] = "Hello";
//    char *data = malloc(sizeof(char *));
//
////    printf("%x\n",123);
//    int count = sprintf(data,"%o",342); // Flags = {'#','-','0','' }
////    printf("%#lx\n",&num);                     // Weight
//                                             // decision ,If decision > symbolLengh, empty field be equal '0'
                                              // if decision == 0,print all text
                              
    char *data = malloc(sizeof(char *));
    char *data1 = malloc(sizeof(char *));
    int  num;
    unsigned long p;
    int count = sscanf(" 123","%d",&num);
   
    printf("%d\n",num);
  
    

//    printf("%s",data1);
    
    return 0;
}


