
#include<stdio.h>
#include<stdlib.h>
//double pi = 3.141592653589793;



int main() {
//
         
    
    char *data = malloc(sizeof(char *));
    char *data1 = malloc(sizeof(char *));
    int  num;
    int  num1;
    int  num3;
    int  num4;
    unsigned long p;
    int count = sscanf("111 222 333 444","%*d%1d%1d%d",&num,&num1,&num3);
   
    
    printf("%d\n",num);
    printf("%d\n",num1);
    printf("%d\n",num3);
   
  
    

//    printf("%s",data1);
    
    return 0;
}


