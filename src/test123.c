#include"s_printf.h"
#include<stdio.h>




int main() {
    int num  = 1;
    char *data;
    int count =  _sprintf(data,"%c %c",'1','2');
    printf("%c %c",'1','2');
    for(int i = 0;i < 1;i++) {
        printf("%c",data[i]);
    }
    
//    printf("%d",5);
    return 0;
}
