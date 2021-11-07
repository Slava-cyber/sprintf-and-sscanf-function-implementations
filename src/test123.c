
#include<stdio.h>
//double pi = 3.141592653589793;



int main() {
    unsigned int num  = 1;
    char *data;
  
    printf("%p\n",&num);
    int count = sprintf(data,"%x",&num); // Flags = {'#','-','0','' }
                                          // Weight
                                             // decision ,If decision > symbolLengh, empty field be equal '0'
                                              // if decision == 0,print all text
                                 

    printf("%s\n",data);
//    printf("%s",data1);
    
    return 0;
}

