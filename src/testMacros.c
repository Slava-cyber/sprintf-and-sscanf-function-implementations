#include "s21_string.h"
#include<string.h>
#include<stdio.h>




int main() {
   
    char src[1024]="первая строка\0вторая строка";
     
       // Массив приемник данных
       char dst[1024]= "";

       // Копируем строку из массива src в массив dst. Обратите внимание,
       //что скопируется только строка «первая строка\0».
       s21_strcpy(dst, src);

       // Вывод массива src на консоль
       printf ("src: %s %s\n",src, &src[14]);

       // Вывод массива dst на консоль
       printf ("dst: %s %s\n",dst, &dst[14]);
   
    return 0;
}
