#include "s21_string.h"

int g_or_G_func(parsing pars, int *len_buf, char *str, long double number) {
    int len_e = 0;
    char *str_e = NULL;
    str_e = (char*) malloc(200 * sizeof(char));
    // change type
    if (pars.type == 'g') {
        pars.type = 'e';
    } else {
        pars.type = 'E';
    }
    // consider precision
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    if (!pars.precision)
        pars.precision = 1;
    pars.precision -= 1;
    int power = e_or_E_func(pars, &len_e, str_e, number, pars.gird + 1);
    if (power < -4 || (power > 0 && pars.precision + 1 <= power + 1)) {
        *len_buf = len_e;
        s21_strcat(str, str_e);
    } else {
        pars.precision -= power;
        f_func(pars, &len_e, str_e, number, pars.gird + 1);
        *len_buf = len_e;
        s21_strcat(str, str_e);
    }
    free(str_e);
    return 1;
}

char sign_func_whole(long int *number, int *plus, int *space) {
    char c;
    if (*number < 0) {
        *number = *number * (-1);
        c = '-';
        *plus = 1;
        *space = 0;
    } else {
        c = '+';
    }
    return c;
}

char sign_func_subst(long double *number, int *plus, int *space) {
    char c;
    if (*number < 0) {
        *number = *number * (-1);
        c = '-';
        *plus = 1;
        *space = 0;
    } else {
        c = '+';
    }
    return c;
}

int whole_part(long double number, int *buff) {
    long double buf;
    modfl(number, &buf);
    long int buf1 = (long int)buf;
    int buff1[100], i = 0;
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
    // switch to ttrue direction
    for (int j = 0; j < i; j++) {
        buff[j] = buff1[i - j - 1];
    }
    return i;
}

int fraction_part(int shortage, long double number, int *buff, int whole) {
    long double buf, ost = modfl(number, &buf);
    for (int j = 0; j <= shortage; j++) {
        ost = ost * 10.0;
        ost = modfl(ost, &buf);
        buff[whole + j] = (int)buf;
    }
    return 1;
}

int round_number(int *buff, int len, int *buff1, int *whole) {
    int i = len;
    if (buff[len] >= 5) {
        int flag = 1;
        while (flag) {
            i--;
            if (i == -1)
                flag = 0;
            buff[i]++;
            if (buff[i] > 9 && i != 0) {
                buff[i] = 0;
                continue;
            } else {
                flag = 0;
            }
        }
    }
    // form new finish array with numbers
    if (buff[0] > 9) {
        buff1[0] = 1;
        buff1[1] = 0;
        for (int j = 1; j < len; j++)
            buff1[j + 1] = buff[j];
        *whole+=1;
    } else {
        for (int j = 0; j < len; j++)
            buff1[j] = buff[j];
    }
    return 1;
}

int str_form(parsing pars, int *buff1, int whole, char c, char *str, int *len_str) {
    for (int j = 0; j < whole; j++)
       str[j] = buff1[j] + 48;

    // consider the existence of point
    if (pars.precision == 0 && pars.gird == 0) {
        str[whole] = '\0';
        *len_str = whole;
    } else {
        str[whole] = '.';
        for (int j = 0; j < pars.precision; j++) {
            str[whole + 1 + j] = buff1[whole + j] + 48;
        }
        str[whole + pars.precision  + 1] = '\0';
        *len_str = whole + pars.precision + 1;
    }
    int len = *len_str;
    // consider sign
    if (pars.plus) {
        s21_memmove(str + 1, str, *len_str);
        str[0] = c;
        str[*len_str + 1] = '\0';
        *len_str += 1;
    } else {
        if (pars.space) {
            s21_memmove(str + 1, str, *len_str);
            str[0] = ' ';
            str[*len_str+ 1] = '\0';
            *len_str += 1;
        }
    }
    return len;
}

int consider_g(char *str, int *len_str, int *len, int from_g_gird) {
    if (from_g_gird == 1) {
        while (str[*len_str - 1] == 48) {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
        if (str[*len_str - 1] == '.') {
            str[*len_str - 1] = '\0';
            *len_str -= 1;
            *len -= 1;
        }
    }
    return 1;
}

int format_f(parsing pars, int len1, int len, char c, char *str, int *len_buf) {
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

int form_power(int power, char e, char *str, int *len_buf) {
    char sign;
    if (power >= 0) {
        sign = '+';
    } else {
        power = power * (-1);
        sign = '-';
    }
    int pow[2];
    if (power >= 10) {
        int i = 0;
        while (i != 2) {
            pow[1 - i] = power % 10;
            power = power / 10;
            i++;
        }
    } else {
        pow[0] = 0;
        pow[1] = power;
    }
    str[*len_buf] = e;
    str[*len_buf + 1] = sign;
    str[*len_buf + 2] = pow[0] + 48;
    str[*len_buf + 3] = pow[1] + 48;
    str[*len_buf + 4] = '\0';
    *len_buf = *len_buf + 4;
    return *len_buf;
}

int e_or_E_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird) {
    long double const_zero = pow(10, -50);
    *len_buf = 0;
    char e = pars.type, sign = sign_func_subst(&number, &pars.plus, &pars.space);
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    int power = 0, whole, len;
    long double buf_number = number;
    int *buff1 = (int*) malloc(100 * sizeof (int));
    int *buff = (int*) malloc(100 * sizeof (int));
    if (number < const_zero) {
        power = 0;
        whole = 1;
        for (int i = 0; i < whole + pars.precision; i++) {
            buff[i] = 0;
        }
    } else {
        while (buf_number > 10) {
        buf_number = buf_number / 10;
        power++;
        }
        while (buf_number < 1) {
            buf_number = buf_number * 10;
            power--;
        }
        number = buf_number;
        whole = whole_part(number, buff);
        fraction_part(pars.precision, number, buff, whole);
        round_number(buff, whole + pars.precision, buff1, &whole);
        if (whole == 2) {
            number = number / 10;
            power++;
        }
        whole = whole_part(number, buff);
        fraction_part(pars.precision, number, buff, whole);
    }
    len = str_form(pars, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = form_power(power, e, str, len_buf);
    len += 4;
    format_f(pars, len1, len, sign, str, len_buf);
    free(buff);
    free(buff1);
    return power;
}

int consider_precision_x(parsing pars, int i, int *precision, char *str) {
    if (pars.precision < 0)
        pars.precision = i;
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else if (pars.precision == 0) {
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
        str[1] = pars.type;
        str[pars.precision + 2] = '\0';
    } else {
        str[pars.precision] = '\0';
    }
    *precision = pars.precision;
    return len;
}

int f_func(parsing pars, int *len_buf, char *str, long double number, int from_g_gird) {
    char sign = sign_func_subst(&number, &pars.plus, &pars.space);
    if (!pars.point || pars.precision < 0)
        pars.precision = 6;
    int *buff = (int*) malloc(100 * sizeof (int));
    int whole = whole_part(number, buff);

    fraction_part(pars.precision, number, buff, whole);
    int *buff1 = (int*) malloc(100 * sizeof (int));
    round_number(buff, whole + pars.precision, buff1, &whole);
    int len = str_form(pars, buff1, whole, sign, str, len_buf);
    consider_g(str, len_buf, &len, from_g_gird);
    int len1 = *len_buf;
    format_f(pars, len1, len, sign, str, len_buf);
    free(buff);
    free(buff1);
    return 1;
}

int format_x(parsing pars, int len, char *str, int *len_buf) {
        if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.gird) {
                    str[0] = '0';
                    str[1] = pars.type;
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';


                if (pars.gird) {
                    str[pars.width - pars.precision - 1] = pars.type;
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
    return 1;
}

int x_or_X_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int)number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int)number;
    }
    // form number 16-system
    char *data = malloc(sizeof(char *));
    int index = convert(pars, number, 16, data, pars.type);
    for (int i = index; i >= 0; i--)
        str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (pars.point != 0 && pars.precision >= 0) {
        pars.zero = 0;
    }
    if (number == 0) {
        if (pars.point == 0) {
            str[0] = '0';
            str[1] = '\0';
            i = 1;
        }
        pars.gird = 0;
    }
    // precision solve
    int len = consider_precision_x(pars, i, &pars.precision, str);
    // if width > len
    format_x(pars, len, str, len_buf);
    free(data);
    return *len_buf;
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
    long unsigned int buf = number;
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

int form_number_d(parsing pars, long int number, char *str) {
    int i = 0;
    int buff[100];
    if (number) {
        while (number) {
            buff[i] = number % 10;
            number = number / 10;
            i++;
        }
    } else {
        if (pars.precision < 0 || pars.point == 0) {
            buff[i] = 0;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        str[j] = buff[i - j - 1] + 48;
    }
    str[i] = '\0';
    return i;
}

int consider_precision_d(parsing pars, int i, char sign, char *str, int *precision) {
    // precision solve
    if (pars.precision > i) {
        s21_memmove(str + pars.precision - i, str, i);
        for (int j = 0; j < pars.precision - i; j++) {
            str[j] = '0';
        }
    } else {
        *precision = i;
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
        str[0] = sign;
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
    return len;
}

int format_d(parsing pars, int len, char *str, char sign, int *len_buf) {
    // if width > len
    if (pars.width > len) {
        if (!pars.minus) {
            s21_memmove(str + pars.width - len, str, len);
            if (pars.zero) {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = '0';
                if (pars.plus) {
                    str[0] = sign;
                } else if (pars.space) {
                    str[0] = ' ';
                }
            } else {
                for (int j = 0; j < pars.width - pars.precision; j++)
                    str[j] = ' ';

                if (pars.plus) {
                    str[pars.width - pars.precision - 1] = sign;
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

int d_or_i_func(parsing pars, va_list args, int *len_buf, char *str) {
    if (pars.point && pars.precision >= 0)
        pars.zero = 0;
    long int number = va_arg(args, long int);
    if (pars.leng == 0) {
        number = (int)number;
    } else if (pars.leng == 'h') {
        number = (short int)number;
    }
    char sign = sign_func_whole(&number, &pars.plus, &pars.space);
    // size of number
    int i = form_number_d(pars, number, str);
    // consider precision
    int len = consider_precision_d(pars, i, sign, str, &pars.precision);
    // fornmat d_func
    format_d(pars, len, str, sign, len_buf);
    return 1;
}

int o_func(parsing pars, va_list args, int *len_buf, char *str) {
    long unsigned number = va_arg(args, long unsigned);
    if (pars.leng == 0) {
        number = (unsigned int)number;
    } else if (pars.leng == 'h') {
        number = (short unsigned int)number;
    }
    // form number 8-system
    char *data = (char*) malloc(200 * sizeof(char));
    int index = convert(pars, number, 8, data, pars.type);
    for (int i = index; i >= 0; i--)
        str[index - i] = data[i];
    str[index + 1] = '\0';
    int i = index + 1;
    if (pars.point)
        pars.zero = 0;
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
    // if width > len
    pars.plus = 0;
    pars.space = 0;
    format_d(pars, pars.precision, str, '+', len_buf);
    free(data);
    return *len_buf;
}

int p_func(parsing pars, va_list args, int *len_buf, char *str) {
    int size = 0;
    unsigned long num = va_arg(args, unsigned long);
    char *data = malloc(200*sizeof(char *));
    char *reverse = malloc(200* sizeof(char *));
    char *src = malloc(sizeof(char *));
    char *tmp = malloc(sizeof(char *));
    int index = convert(pars, num, 16, data, 'x');
    for (int i = index; i >= 0; i--)
        reverse[index - i] = data[i];
    reverse[index + 1] = '\0';
    src[0] = '0';
    src[1] = 'x';
    src[2] = '\0';
    if ((void *)num == NULL) {
        if (pars.point != 0) {
            src[2] = '\0';
        } else {
            src[2] = '0';
            src[3] = '\0';
        }
        }
    s21_strcat(src, reverse);
    if (pars.width) {
        if (pars.width > (int)s21_strlen(src)) {
            size = pars.width - (int)s21_strlen(src);
        }
        if (pars.minus) {
            for (int i = 0; i < (int)s21_strlen(src); i++) {
                str[i] = src[i];
            }
            for (int j = (int)s21_strlen(src); j < pars.width; j++) {
                str[j] = ' ';
            }
        } else {
            for (int i = 0; i < (int)s21_strlen(src); i++) {
                tmp[i] = src[i];
            }
            for (int i = 0; i < size; i++) {
                str[i] = ' ';
            }
            int index = 0;
            for (int i = size; i< size + (int)s21_strlen(tmp); i++) {
                str[i] =  tmp[index];
                index++;
            }
        }
    } else {
        for (int i = 0; i < (int)s21_strlen(src); i++) {
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
    if (pars.leng == 0) {
        char *src;
        src = va_arg(args, char *);
        s21_strcat(str, src);
    } else {
        wchar_t *src;
        src = (wchar_t *)va_arg(args, wchar_t *);
        s21_wchstrcat(str, src);
        }
        if (pars.precision >= (int)s21_strlen(str) || (pars.precision == 0 && pars.point == 0)
            || pars.precision < 0)
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

int convert(parsing pars, long unsigned num, long unsigned divider, char *data, char spec) {
    long unsigned rem = num;
    char ch;
    int index = 0;
    if (num) {
        while (num) {
            rem = num % divider;
            num = num / divider;
            if ((spec == 'x') || (spec == 'o')) {
                ch = convertTox(rem);
            }
            if  (spec == 'X') {
                ch = convertToX(rem);
            }
            data[index] = ch;
            index++;
        }
    } else {
        if (pars.precision <0) {
            data[index] = '0';
            index++;
        }
    }
    return index - 1;
}

int n_func(va_list args, int length) {
    int *number = va_arg(args, int*);
    *number = length;
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
    while (*format) {
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
            // free bufer after last step
            for (int i = 0; i < 200; i++)
                str_add[i]='\0';
                len_add = 0;
            while (flag) {
                // if after % will be ' '
                if (*format == ' ' && pars.plus == 0)
                        pars.space = 1;
                // if after % will be '0'
                if (*format == '0' && pars.width == 0 && pars.point == 0)
                    pars.zero = 1;
                // if after % will be '+'
                if (*format == '+') {
                    pars.plus = 1;
                    pars.space = 0;
                }
                // if after % will be '#'
                if (*format == '#')
                    pars.gird = 1;
                // if meet '.'
                if (*format == '.') {
                    pars.point = 1;
                    format++;
                    // if we have *
                    if (*format == '*') {
                        pars.precision = va_arg(args, int);
                        format++;
                        continue;
                    // if we have to form number
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
                    }
                }
                // if meet just digit
                if (def_number(*format)) {
                    if (pars.star == 1) {
                        pars.width = 0;
                        continue;
                    } else {
                        int len = 0;
                        pars.width = form_number(format, &len);
                        format = format + len;
                        continue;
                    }
                }
                // if we meet length block
                if (leng(*format)) {
                    pars.leng = *format;
                }
                // if after % will be '-'
                if (*format == '-') {
                    pars.minus = 1;
                    pars.zero = 0;
                }
                // if we meet spec
                if (spec(*format)) {
                    pars.type = *format;
                    flag = 0;
                }
                format++;
            }
            calling_function(pars, args, &len_add, str_add, length);
            s21_memmove(str + length, str_add, len_add);
            length += len_add;
        // if we don't meet % just print symbols  until we can
        } else {
            *(str+length) = *format;
            length++;
            format++;
            continue;
        }
    }
    *(str+length) = '\0';
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
    long double number = 0.0;
    int from_g_gird = 0;
    switch (pars.type) {
        case 'c':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case '%':
            c_or_percent_func(pars, args, len_buf, str_add);
            break;
        case 'f':
            number = subst_input(pars, args);
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
            number = subst_input(pars, args);
            e_or_E_func(pars, len_buf, str_add, number, from_g_gird);
            break;
        case 'E':
            number = subst_input(pars, args);
            e_or_E_func(pars, len_buf, str_add, number, from_g_gird);
            break;
        case 'g':
            number = subst_input(pars, args);
            g_or_G_func(pars, len_buf, str_add, number);
            break;
        case 'G':
            number = subst_input(pars, args);
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

long double subst_input(parsing pars, va_list args) {
    long double number;
    if (pars.leng == 0) {
        number = (long double) va_arg(args, double);
    } else {
        number = va_arg(args, long double);
    }
    return number;
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
    } else {
        *len_buf = 1;
    }
    return 1;
}
