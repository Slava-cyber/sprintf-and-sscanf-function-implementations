
#include<stdio.h>
//double pi = 3.141592653589793;



int main() {
    unsigned num  = 234;
    char *data;
    char *src = "dasdasd";
    int count = sprintf(data,"%o", num);

    printf("%s",data);
    
    return 0;
}

