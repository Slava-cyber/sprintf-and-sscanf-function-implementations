#include "s21_string.h"


int o_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args,long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int)number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int)number;
    }
  
    
    // form number 8-system
    char *data = malloc(200*sizeof(char *));
    int index = convert(pars, number, 8, data, pars.type);
    for(int i = index; i >= 0; i--)
        str[index - i] = data[i];
    
    str[index + 1] = '\0';
    int i = index+1;


    if (pars.point) {
        pars.zero = 0;
    }
    
    
    
    if (pars.precision < 0)
        pars.precision = i;

    // consider gird
    if (pars.gird && number != 0) {
        s21_memmove(str + 1, str, i);
        str[0] = '0';
        i++;
        str[i] = '\0';
    } else {
        str[i] = '\0';
    }




    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }


    int len = pars.precision;

    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
                
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    free(data);
    return *len_buf;
}



int p_func(parsing pars, va_list args, int *len_buf, char *str) {

    int size = 0;
    unsigned long num = va_arg(args,unsigned long);
    char *data = malloc(200*sizeof(char *));
    char *reverse = malloc(200* sizeof(char *));
    char *src = malloc(sizeof(char *));
    char *tmp = malloc(sizeof(char *));
    int index = convert(pars, num,16,data,'x');
    
    for(int i = index; i >= 0; i--)
        reverse[index - i] = data[i];
    
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    src[2] = '\0';
    if((void *)num == NULL) {
            src[2] = '0';
            src[3] = '\0';
        }

    s21_strcat(src,reverse);

    
    if(pars.width) {
        if(pars.width > (int)s21_strlen(src)) {
            size = pars.width - (int)s21_strlen(src);
        }
        if(pars.minus) {
            for(int i = 0; i < (int)s21_strlen(src);i++) {
                str[i] = src[i];
            }
            for(int j = (int)s21_strlen(src);j < pars.width;j++) {
                str[j] = ' ';
            }
        } else {
            for(int i = 0; i < (int)s21_strlen(src);i++) {
                tmp[i] = src[i];
            }
            for(int i = 0; i < size ;i++) {
                str[i] = ' ';
            }
            int index = 0;
            for(int i = size;i< size + (int)s21_strlen(tmp);i++) {
                str[i] =  tmp[index];
                index++;
            }
        }
    } else {
        for(int i = 0; i < (int)s21_strlen(src);i++) {
            str[i] = src[i];
        }
    }
        *len_buf = (int)s21_strlen(str);
    
    free(data);
    free(reverse);
    free(src);
    free(tmp);
    return 0;

}



int s_func(parsing pars, va_list args, int *len_buf, char *str) {
    char *src;
    src = va_arg(args,char *);
    s21_strcat(str, src);
    if (pars.precision >= (int)s21_strlen(str) || (pars.precision == 0 && pars.point == 0) || pars.precision < 0)
        pars.precision = (int) s21_strlen(str);
    str[pars.precision] = '\0';

    if (pars.width > pars.precision) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - pars.precision, str, pars.precision);
            if (pars.zero) {
                for (int i = 0; i < pars.width - pars.precision; i++)
                    str[i] = '0';
            } else {
                for (int i = 0; i < pars.width - pars.precision; i++)
                    str[i] = ' ';
            }
        } else {
                for (int i = pars.precision; i < pars.width; i++)
                    str[i] = ' ';
        }
        str[pars.width] = '\0';
        *len_buf = pars.width;
    } else {
        *len_buf = pars.precision;
    }
    return 1;
}



int g_or_G_func(parsing pars, int *len_buf, char *str, double number) {
    int len_e = 0;
    char *str_e = NULL;
    str_e = (char*) malloc(200 * sizeof(char));
    // save sign
    //char c;
    double save_number = number;
    if (number < 0)
        number = number * (-1);
    if (pars.type == 'g') {
        pars.type = 'e';
    } else {
        pars.type = 'E';
    }
    
    // save precision
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    
    if (!pars.precision)
        pars.precision = 1;

    double buf, ost = modf(number, &buf);
    long int buf1 = (long int)buf;
    int buff[100], buff1[100], i = 0, whole = 0;
    //parsing of whole part of number

    if (buf1) {
        while (buf1) {
            buff1[i] = buf1 % 10;
            buf1 = buf1 / 10;
            i++;
        }
    } else {
        buff1[i] = 0;
        i++;
    }

    whole = i;

    // switch to true direction
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];
    }

    int non_zero = whole;
    if (!buff[0])
        non_zero = 0;

    // free buffer;
    for (int j = 0; j < 100; j++)
        buff1[j] = 0;
    
    int j = 0;

    int last, shortage;
    if (non_zero == pars.precision) {
        shortage = 1;
    } else if (non_zero > pars.precision) {
        shortage = 0;
    } else {
        shortage = pars.precision - non_zero + 1;
    }

    // add fraction part of number and parsing
        if (!non_zero) {
            last = 0;
            int flag = 0;
            while (non_zero!=shortage) {
                ost = ost * 10.0;
                ost = modf(ost, &buf);
                buff[i + last] = (int)buf;
                if (flag) {
                    non_zero++;
                } else if (buff[i+last]) {
                    flag = 1;
                    non_zero++;
                }
                last++;
            }
        } else {
            for(last = 0; last < shortage; last++) {
                ost = ost * 10.0;
                ost = modf(ost, &buf);
                buff[i + last] = (int)buf;
            }
        }
    last--;
    last = i + last;
    for (int j = 0; j <= last; j++) {

    }

    // round using size of precision
    // take the last element
    int all = last;
    if (buff[last] >= 5) {
        int flag = 1;
        while(flag) {
            all--;
            if (all == -1)
                break;
            buff[all]++;
            if (buff[all] > 9 && all != 0) {
                buff[all] = 0;
                continue;
            } else {
                break;
            }
        }
    }
    for (int j = 0; j <= last; j++) {

    }
    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        last++;
        for (int j = 1; j < last; j++)
            buff1[j + 1] = buff[j];
        whole++;
    } else {
        for (int j = 0; j < last; j++)
            buff1[j] = buff[j];
    }
    
    
    buff1[last] = 0;
    for (int j = 0; j < last; j++) {
    }
    // free buffer;
    for (int j = 0; j < 100; j++)
        buff[j] = 0;
    //calculate negative power
    j = 0;
    while (!buff1[j])
        j++;


    if (whole > pars.precision || j > 4) {
            pars.precision--;
            e_or_E_func(pars, &len_e, str_e, save_number, pars.gird + 1);
        s21_strcat(str, str_e);
        *len_buf = len_e;
    } else {


        
            if (j != 0) {
                pars.precision = pars.precision + j - 1;
            } else {
                pars.precision = pars.precision - whole;
            }
            f_func(pars, &len_e, str_e, save_number, pars.gird + 1);
        s21_strcat(str, str_e);
        *len_buf = len_e;
    }
    free(str_e);
    return 1;
}








int e_or_E_func(parsing pars, int *len_buf, char *str, double number, int from_g_gird) {

    *len_buf = 0;
    char e = pars.type;
    //printf("precision:%d\n", pars.precision);
    // save sign
    char c;
    if (number < 0) {
        number = number * (-1);
        c = '-';
        pars.plus = 1;
        pars.space = 0;
    } else {
        c = '+';
    }

    // save precision
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;


    double buf, ost = modf(number, &buf);
    long int buf1 = (long int)buf;
    int buff[100], buff1[100], i = 0;

    
    //parsing of whole part of number
    if (buf1) {
        while (buf1) {
            buff1[i] = buf1 % 10;
            buf1 = buf1 / 10;
            i++;
        }
    } else {
        buff1[i] = 0;
        i++;
    }

    int whole = i;


    // switch to true direction
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];

    }
    
    // free buffer;
    for (int j = 0; j < 100; j++)
        buff1[j] = 0;

        
    int non_zero = whole;
    if (!buff[0])
        non_zero = 0;

    int last, shortage;
    if (non_zero == pars.precision) {
        shortage = 2;
    } else if (non_zero == pars.precision + 1) {
        shortage = 1;
    } else if (non_zero > pars.precision + 1) {
        shortage = 0;
    } else {
        shortage = pars.precision + 2 - non_zero;
    }

    // add fraction part of number and parsing
        if (!non_zero) {
            last = 0;
            int flag = 0;
            while (non_zero!=shortage) {
                ost = ost * 10.0;
                ost = modf(ost, &buf);
                buff[i + last] = (int)buf;
                if (flag) {
                    non_zero++;
                } else if (buff[i+last]) {
                    flag = 1;
                    non_zero++;
                }
                last++;
            }
        } else {
            for(last = 0; last < shortage; last++) {
                ost = ost * 10.0;
                ost = modf(ost, &buf);
                buff[i + last] = (int)buf;
            }
        }

    last--;
    last = i + last;
    for (int j = 0; j <= last; j++) {
    }
    

    // round using size of precision
    // take the last element

    int all = last;
    if (buff[last] >= 5) {
        int flag = 1;
        while(flag) {
            all--;
            if (all == -1)
                break;
            buff[all]++;
            if (buff[all] > 9 && all != 0) {
                buff[all] = 0;
                continue;
            } else {
                break;
            }
        }
    }

    for (int j = 0; j <= last; j++) {
    }

    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        last++;
        for (int j = 1; j < last; j++)
            buff1[j + 1] = buff[j];
        whole++;
    } else {
        for (int j = 0; j < last; j++)
            buff1[j] = buff[j];
    }

    buff1[last] = 0;

    for (int j = 0; j < last; j++) {
    }

    // free buffer;
    for (int j = 0; j < 100; j++)
        buff[j] = 0;
   
    //calculate negative power
    int j = 0;
    while (!buff1[j])
        j++;
    

    // change array for %e
    int flag = 0, k = 0;
    for (int j = 0; j < last; j++) {
        if (flag) {
            buff[k] = buff1[j];
            k++;
        } else if (buff1[j]) {
            buff[k] = buff1[j];
            k++;
            flag++;
        }
    }

        for (int j = 0; j < k; j++) {
    //    str[j] = buff1[j] + 48;
    }
   
    // form power value
    int power;
    char sign;
    if (k == last) {
        power = whole - 1;
        sign = '+';
    } else {
        power = last - k;
        sign = '-';

    }

        // from g change
    if (from_g_gird == 1) {
        while(buff[k - 1] == 0 && pars.precision >=0) {
            pars.precision--;
            k--;
        }
    }


    // form power array;
    int pow[2];
    i = 0;
    if (power >= 10) {
        while (i != 2) {
            pow[1 - i] = power % 10;
            power = power / 10;
            i++;
        }
    } else {
        pow[0] = 0;
        pow[1] = power;
    }

    int len;
    // consider the existence of point
    str[0] = buff[0] + 48;
    if (pars.precision == 0 && pars.gird == 0) {
        str[1] = e;
        str[2] = sign;
        str[3] = pow[0] + 48;
        str[4] = pow[1] + 48;
        str[5] = '\0';
        len = 5;
    } else {
        str[1] = '.';
        for (int j = 0; j < pars.precision; j++) {
            str[1 + 1 + j] = buff[1 + j] + 48;
        }
        str[2 + pars.precision] = e;
        str[2 + pars.precision + 1] = sign;
        str[2 + pars.precision + 2] = pow[0] + 48;
        str[2 + pars.precision + 3] = pow[1] + 48;
        str[6 + pars.precision] = '\0';
        len = pars.precision + 6;
    }

    // consider plus and space
    int len1 = len;
    if (pars.plus || pars.space) {
        len1 = len + 1;
    }
    //pars.precision = i;

    if (pars.plus) {
        s21_memmove(str + 1, str, len);
        str[0] = c;
        str[len + 1] = '\0';
    } else {
        if (pars.space) {
            s21_memmove(str + 1, str, len);
            str[0] = ' ';
            str[len + 1] = '\0';
        }
    }
    

    
    
    if (pars.width > len) {
        if (!pars.minus) {
 
            s21_memmove(str + pars.width - len1, str, len1);

            
            if (pars.zero) {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = '0';

                if (pars.plus) {
                    str[0] = c;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = ' ';


                if (pars.plus) {
                    str[pars.width - len - 1] = c;
                }
            }
        } else {
            for (int j = len1; j < pars.width; j++) {
                str[j] = ' ';
            }
        }
        *len_buf = pars.width;
        str[pars.width] = '\0';
    } else {
        *len_buf = len1;
    }

    return 1;
}




int f_func(parsing pars, int *len_buf, char *str, double number, int from_g_gird) {

    // save sign
    char c;
    if (number < 0) {
        number = number * (-1);
        c = '-';
        pars.plus = 1;
        pars.space = 0;
    } else {
        c = '+';
    }
    // save precision
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;

    double buf, ost = modf(number, &buf);
    long int buf1 = (long int)buf;
    int buff[100], buff1[100], i = 0, len;
    
    //parsing of whole part of number
    if (buf1) {
        while (buf1) {
            buff1[i] = buf1 % 10;
            buf1 = buf1 / 10;
            i++;
        }
    } else {
        buff1[i] = 0;
        i++;
    }

    int whole = i;

    // switch to true direction
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];
    }
    
    // free buffer;
    for (int j = 0; j < 100; j++)
        buff1[j] = 0;

    
    // add fraction part of number and parsing
    for(int j = 0; j <= pars.precision; j++) {
        ost = ost * 10.0;
        ost = modf(ost, &buf);
        buff[i + j] = (int)buf;
    }


    //for (int j = 0; j <= i + pars.precision; j++) {
    //    printf("buff:%d\n", buff[j]);
    //}

    
    // round using size of precision
    int all = i + pars.precision;
    if (buff[i + pars.precision] >= 5) {
        int flag = 1;
        while(flag) {
            all--;
            if (all == -1)
                break;
            buff[all]++;
            if (buff[all] > 9 && all != 0) {
                buff[all] = 0;
                continue;
            } else {
                break;
            }
        }
    }

    for (int j = 0; j <= i + pars.precision; j++) {

    }

    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        for (int j = 1; j < whole + pars.precision; j++)
            buff1[j + 1] = buff[j];
        whole++;
    } else {
        for (int j = 0; j < whole + pars.precision; j++)
            buff1[j] = buff[j];
    }

    for (int j = 0; j < whole; j++) {
        str[j] = buff1[j] + 48;
    }


            // from g change
    int k = whole + pars.precision;
    if (from_g_gird == 1) {
        while(buff[k - 1] == 0 && pars.precision >= 0) {
            pars.precision--;
            k--;
        }
    }

    // consider the existence of point
    if (pars.precision == 0 && pars.gird == 0) {
        str[whole] = '\0';
        len = whole;
    } else {
        str[whole] = '.';
        for (int j = 0; j < pars.precision; j++) {

            str[whole + 1 + j] = buff1[whole + j] + 48;
        }
        str[whole + pars.precision  + 1] = '\0';
        len = whole + pars.precision + 1;
    }


    // consider plus and space
    int len1 = len;
    if (pars.plus || pars.space)
        len1 = len + 1;
    //pars.precision = i;

    if (pars.plus) {
        s21_memmove(str + 1, str, len);
        str[0] = c;
        str[len + 1] = '\0';
    } else {
        if (pars.space) {
            s21_memmove(str + 1, str, len);
            str[0] = ' ';
            str[len + 1] = '\0';
        }
    }

    
    if (pars.width > len) {
        if (!pars.minus) {

            s21_memmove(str + pars.width - len1, str, len1);

            
            if (pars.zero) {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = '0';

                if (pars.plus) {
                    str[0] = c;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - len; j++)
                    str[j] = ' ';


                if (pars.plus) {
                    str[pars.width - len - 1] = c;
                }
            }
        } else {
            for (int j = len1; j < pars.width; j++) {
                str[j] = ' ';
            }
        }
        *len_buf = pars.width;
        str[pars.width] = '\0';
    } else {
        *len_buf = len1;
    }

    return 1;
}



char convertToX(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 55;
    }
    return ch;
}

char convertTox(int value) {
    char ch;
    if (value >= 0 && value < 10) {
        ch = value + 48;
    } else {
        ch = value + 87;
    }
    return ch;
}

int convert(parsing pars, long unsigned num ,long unsigned divider,char *data, char spec) {
    
    //int res = num;
    long unsigned rem = num;
    char ch;
    int index = 0;
    if (num) {
        while (num) {
            rem = num%divider;
            num = num /divider;
            if(spec == 'x' || spec == 'o' ){
                ch = convertTox(rem);
            }
            if  (spec == 'X') {
                ch = convertToX(rem);
            }
            data[index] = ch;
            index ++;
        }
    } else {
        if (pars.precision <0) {
            data[index] = '0';
            index++;
        }
    }
    return index - 1;
}





int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args,long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int)number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int)number;
    }

    // form number 16-system
    char *data = malloc(sizeof(char *));
    int index = convert(pars, number, 16, data, pars.type);
    for(int i = index; i >= 0; i--)
        str[index - i] = data[i];
    
    str[index + 1] = '\0';
    int i = index+1;

    if (pars.point != 0 && pars.precision >= 0) {
        pars.zero = 0;
    }

    if (number == 0)
        pars.gird = 0;
    if (pars.precision < 0)
        pars.precision = i;

    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else if (pars.precision == 0 && number == 0) {
        str[0] = ' ';
        pars.precision = i;
    } else {
        pars.precision = i;
    }


    // consider gird
    int len;
    if (pars.gird) {
        len = pars.precision + 2;
    } else {
        len = pars.precision;
    }


    // str after with precision
    if (pars.gird) {
        s21_memmove(str + 2, str, pars.precision);
        str[0] = '0';
        str[1] = 'x';
        str[pars.precision + 2] = '\0';
    } else {
        str[pars.precision] = '\0';
    }

    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.gird) {
                    
                        str[0] = '0';
                        str[1] = 'x';
                    
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';

                if (pars.gird) {
                    str[pars.width - pars.precision - 1] = 'x';
                    str[pars.width - pars.precision - 2] = '0';
                }
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    free(data);
    return *len_buf;
}








int n_func(va_list args, int length) {
    int *number = va_arg(args, int*);
    *number = length;
    return 1;
}



int u_func(parsing pars, va_list args, int *len_buf, char *str) {


    if (pars.point && pars.precision >=0) {
        pars.zero = 0;
    }
    
    long unsigned int number = va_arg(args, long unsigned int);
    
    if (pars.leng == 0) {
        number = (unsigned int)number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int)number;
    }
    // parsing number
    unsigned int buf = number;
    int i = 0;
    int buff[100];
    if (buf) {
        while (buf) {
            buff[i] = buf % 10;
            buf = buf / 10;
            i++;
        }
    } else {
        if (pars.precision != 0 || pars.point == 0) {
            buff[i] = 0;
            i++;
        }
    }

    // switch numbers to the right direction
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';


    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        pars.precision = i;
    }


    int len = pars.precision;
    str[pars.precision] = '\0';


    // str after with precision


    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {

            s21_memmove(str + pars.width - len, str, len);


            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';
            }
        } else {
            for (int j = len; j < pars.width; j++) {
                str[j] = ' ';
            }
            str[pars.width] = '\0';
        }
        *len_buf = pars.width;
    } else {
        *len_buf = len;
    }
    return 1;
}








int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {

    
       if (pars.point && pars.precision >= 0)
           pars.zero = 0;

       long int number = va_arg(args, long int);

           
       if (pars.leng == 0) {
           number = (int)number;
       } else if (pars.leng == 'h') {
           number = (short int)number;
       }

       char c;
       if (number < 0) {
           number = number * (-1);
           c = '-';
           pars.plus = 1;
           pars.space = 0;
       } else {
           c = '+';
       }

       // size of number
       long int buf = number;
       int i = 0;
       long int buff[100];
       if (buf) {
           while (buf) {
               buff[i] = buf % 10;
               buf = buf / 10;
               i++;
           }
       } else {
           if (pars.precision != 0 || pars.point == 0) {
               buff[i] = 0;
               i++;
           }
       }

       for (int j = 0; j < i; j++) {
           str[j] = buff[i - j - 1] + 48;
       }
       str[i] = '\0';



       // precision solve
       if (pars.precision > i) {
           s21_memmove(str + pars.precision - i, str, i);
           for (int j = 0; j < pars.precision - i; j++) {
               str[j] = '0';
           }
       } else {
           pars.precision = i;
       }


       // consider plus
       int len;
       if (pars.plus || pars.space) {
           len = pars.precision + 1;
       } else {
           len = pars.precision;
       }


       // str after with precision
       if (pars.plus) {
           s21_memmove(str + 1, str, pars.precision);
           str[0] = c;
           str[pars.precision + 1] = '\0';
       } else {
           if (pars.space) {
               s21_memmove(str + 1, str, pars.precision);
               str[0] = ' ';
               str[pars.precision + 1] = '\0';
           } else {
               str[pars.precision] = '\0';
           }
       }

       // if width > len
       if (pars.width > len) {
           if (!pars.minus) {

               s21_memmove(str + pars.width - len, str, len);

               
               if (pars.zero) {
                   for (int j = 0; j < pars.width - pars.precision; j++)
                       str[j] = '0';
                   if (pars.plus) {
                       str[0] = c;//+
                   } else if (pars.space) {
                       str[0] = ' ';//+
                   }
               } else {
                   for (int j = 0; j < pars.width - pars.precision; j++)
                       str[j] = ' ';

                   if (pars.plus) {
                       str[pars.width - pars.precision - 1] = c;
                   }
               }
           } else {
               for (int j = len; j < pars.width; j++) {
                   str[j] = ' ';
               }
               str[pars.width] = '\0';
           }
           *len_buf = pars.width;
       } else {
           *len_buf = len;
       }

       return 1;
}







int s21_sprintf(char *str, char *format, ...) {
    va_list args;
    parsing pars;
    int len_add = 0;
    char *str_add;
    str_add = (char*)malloc(200*sizeof(char));
    int length = 0;
    va_start(args, format);
    
    for(int q = 0;q < (int)s21_strlen(str);q++) {
        str[q] = '\0';
    }
    
    while (*format) {
        //printf("%c", *format);
        // if '%' start the block
        if (*format == '%') {
            // the initialization of the struct
            pars.plus = 0;
            pars.gird = 0;
            pars.minus = 0;
            pars.zero = 0;
            pars.space = 0;
            pars.leng = 0;
            pars.width = 0;
            pars.point = 0;
            pars.precision = 0;
            pars.type = 0;
            pars.star = 0;
            
            format++;
            // start the filling struct using block
            int flag = 1;
            //free bufer after last step
            for (int i = 0; i < 200; i++)
                str_add[i]='\0';
            len_add = 0;
            
            while (flag) {
                
                // if after % will be ' '
                if (*format == ' ') {
                    if (!pars.plus)
                        pars.space = 1;
                    //*(str + length) = ' ';
                    //length++;
                    format++;
                    continue;
                }
                //if after % will be '0'
                if (*format == '0' && pars.width == 0 && pars.point == 0) {
                    pars.zero = 1;
                    format++;
                    continue;
                }
                // if after % will be '+'
                if (*format == '+') {
                    pars.plus = 1;
                    pars.space = 0;
                    format++;
                    continue;
                }
                //if after % will be '#'
                if (*format == '#') {
                    pars.gird = 1;
                    format++;
                    continue;
                }
                //if meet '.'
                if (*format == '.') {
                    pars.point = 1;
                    //pars.zero = 0;
                    format++;
                    // if we have *
                    if (*format == '*') {
                        pars.precision = va_arg(args, int);
                        format++;
                        continue;
                        //if we have to form number
                    } else {
                        int len = 0;
                        pars.precision = form_number(format, &len);
                        format = format + len;
                        continue;
                    }
                }
                // if meet '*' calculate width
                if (*format == '*') {
                    pars.star = 1;
                    pars.width = va_arg(args, int);
                    if ((pars.width < 0)) {
                        pars.width = (-1) * pars.width;
                        pars.minus = 1;
                        pars.zero = 0;
                    } else {
                    }
                    format++;
                    continue;
                }
                // if meet just digit
                if (def_number(*format)) {
                    if (pars.star == 1) {
                        pars.width = 0;
                        continue;
                    } else {
                        int len = 0;
                        pars.width = form_number(format, &len);
                        //printf("\nlen:%d\n", len);
                        //printf("\nlform:%c\n", *format);
                        
                        format = format + len;
                        continue;
                    }
                }
                // if we meet length block
                if (leng(*format)) {
                    pars.leng = *format;
                    format++;
                    continue;
                }
                
                //if after % will be '-'
                if (*format == '-') {
                    pars.minus = 1;
                    pars.zero = 0;
                    format++;
                    continue;
                }
                // if we meet spec
                if (spec(*format)) {
                    pars.type = *format;
                    format++;
                    flag = 0;
                    continue;
                }
                
            }
            // finish filling struct
            
            // analyzing data and form str
            calling_function(pars, args, &len_add, str_add, length);
            s21_memmove(str + length, str_add, len_add);
            
            length += len_add;
            //if we don't meet % just print symbols  until we can
        } else {
            *(str+length) = *format;
            //printf("format:%c\n %d\ns", *format, length);
            length++;
            format++;
            continue;
        }
    }
    //printf("lenout:%d", length);
    *(str+length) = '\0';
    //printf("outbef:%c", str[12]);
    va_end(args);
    free(str_add);
    return length;
}

int def_number(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

int form_number(char *str, int *len) {
    int factor = 0;
    char *tmp = str;
    int len1 = 0;
    while (def_number(*tmp)) {
        factor = (factor * 10) + (*tmp) - 48;
        tmp++;
        len1++;
    }
    *len = len1;
    return factor;
}

int spec(char c) {
    int result = 0;
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 112, 37};
    for (int i = 0; i <= 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

int leng(char c) {
    int result = 0;
    if (c == 'L' || c == 'l' || c == 'h') {
        result = 1;
    }
    return result;
}


int calling_function(parsing pars, va_list args, int *len_buf, char *str_add, int length) {
    double number = 0;
    int from_g_gird = 0;
    switch(pars.type) {
        case 'c':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case '%':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case 'f':
            number = va_arg(args, double);
            f_func(pars, len_buf, str_add, number, from_g_gird);
            break;
        case 'd':
            d_or_i_func(pars, args, len_buf, str_add);
            break;
        case 'i':
            d_or_i_func(pars, args, len_buf, str_add);
            break;
        case 'u':
            u_func(pars, args, len_buf, str_add);
            break;
        case 'n':
            n_func(args, length);
            break;
        case 'o':
            o_func(pars, args, len_buf, str_add);
            break;
        case 'x':
            x_or_X_func(pars, args, len_buf, str_add);
            break;
        case 'X':
            x_or_X_func(pars, args, len_buf, str_add);
            break;
        case 'e':
            number = va_arg(args, double);
            e_or_E_func(pars, len_buf, str_add, number, from_g_gird);
            break;
        case 'E':
            number = va_arg(args, double);
            e_or_E_func(pars, len_buf, str_add, number, from_g_gird);
            break;
        case 'g':
            number = va_arg(args, double);
            g_or_G_func(pars, len_buf, str_add, number);
            break;
        case 'G':
            number = va_arg(args, double);
            g_or_G_func(pars, len_buf, str_add, number);
            break;
        case 'p':
            p_func(pars, args, len_buf, str_add);
            break;
        case 's':
            s_func(pars, args, len_buf, str_add);
            break;
    }
    return 1;
}



int c_or_percent_func(parsing pars, va_list args, int *len_buf, char *str) {
    char c;
    if (pars.type == '%') {
        c = '%';
    } else {
        c = va_arg(args, int);
    }
    if (pars.width == 0)
        pars.width = 1;
    if (pars.minus) {
        str[0] = c;
        for (int i = 1; i < pars.width; i++) {
            str[i] = ' ';
        }
        str[pars.width] = '\0';
    } else {
        if (pars.zero) {
            for (int i = 0; i < pars.width - 1 ; i++)
                str[i] = '0';
        } else {
            for (int i = 0; i < pars.width - 1 ; i++)
                str[i] = ' ';
        }
        str[pars.width - 1] = c;
        str[pars.width] = '\0';
    }

    if (pars.width) {
        *len_buf = pars.width;
    }
    else {
        *len_buf = 1;
    }
    return 1;
}
