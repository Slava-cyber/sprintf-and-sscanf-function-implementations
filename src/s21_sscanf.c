#include "s21_string.h"


int x_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    unsigned int number = 0;
    int i = point, sign = 1, changes = 0;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    char *tmp = (char*) malloc (200 * sizeof(char));
    if (!pars.width) {
        pars.width = length - j;
    } else {
        if (pars.width + j >= length) {
            pars.width = length - j;
        }
    }
    int nozero = 0, zero = 0, x_value = 0, x_position = 0;
    while (str[i] == 'x' || str[i] == 'X' || def_number_16Scanf(str[i])) {
        if (i - j == pars.width)
            break;
        if ((str[i] == 'x' || str[i] == 'X') && x_value == 1)
            break;
        if ((str[i] == 'x' || str[i] == 'X') && nozero != 0 && x_value == 0)
            break;
        if ((str[i] == 'x' || str[i] == 'X') && nozero == 0 && x_value == 0) {
            if (zero == 1) {
                x_value = 1;
                x_position = i;
                zero = 0;
            } else if (zero == 0) {
                *error = 1;
                break;
            } else {
                break;
            }
        }
        if (str[i] == '0' && nozero == 0)
            zero++;
        if (nozero != 0 && def_number_16Scanf(str[i]) == 1) {
            tmp[nozero] = str[i];
            nozero++;
        }
        if (str[i] != '0' && def_number_16Scanf(str[i]) == 1 && nozero == 0) {
            tmp[nozero] = str[i];
            nozero++;
        }
        i++;
        changes++;
    }
    tmp[nozero] = '\0';
    unsigned int digit;
    int len = (int) s21_strlen(tmp);
    for (j = 0; j < len; j++) {
        digit =  convertFrom16Scanf(tmp[j]);
        number = number + digit * pow(16, len - 1  - j);
    }
    if (x_value == 1 && (zero == 0 && nozero == 0))
        i = x_position;
    free(tmp);
    if (changes) {
        if (!pars.star) {
            int *num = va_arg(args, int*);
            *num = number * sign;
            *len_buf += 1;
        }
    } else {
        *error = 1;
    }
    return i;
}

int i_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    int  i = point, sign = 1;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    char *tmp = (char*) malloc (200 * sizeof(char));
    for (int j = 0; j < 200; j++) {
        tmp[j] = '\0';
    }
    int zero = 0, x = 0;
    s21_memmove(tmp, str + i, pars.width);
    if (tmp[0] == 48)
        zero = 1;
    if ((tmp[1] == 'x' || tmp[1] == 'X') && zero == 1)
        x = 1;
    if (zero == 0)
        i = d_funcScanf(str, pars, args, len_buf, j, length, error);
    if (zero == 1 && x == 0)
        i = o_funcScanf(str, pars, args, len_buf, j, length, error);
    if (zero == 1 && x == 1)
        i = x_funcScanf(str, pars, args, len_buf, j, length, error);
    free(tmp);
    return i;
}



int o_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    int number = 0, i = point, sign = 1, changes = 0;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    char *tmp = (char*) malloc (200 * sizeof(char));
    if (!pars.width) {
        pars.width = length - j;
    } else {
        if (pars.width + j >= length) {
            pars.width = length - j;
        }
    }
    int nozero = 0;
    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
        if (i - j == pars.width || !def_number_8Scanf(str[i]))
            break;
        if (nozero) {
            tmp[nozero] = str[i];
            nozero++;
        }
        if (str[i] != '0' && nozero == 0) {
            tmp[nozero] = str[i];
            nozero++;
        }
        changes++;
        i++;
    }
    tmp[nozero] = '\0';
    int digit, len = (int) s21_strlen(tmp);
    for (j = 0; j < len; j++) {
        digit =  convertFrom16Scanf(tmp[j]);
        number = number + digit * pow(8, len - 1  - j);
    }
    free(tmp);
    if (changes) {
        if (!pars.star) {
            int *num = va_arg(args, int*);
            *num = number * sign;
            *len_buf += 1;
        }
    } else {
        *error = 1;
    }
    return i;
}

int convertFrom16Scanf(char value) {
    int ch;
    if (value >= '0' && value <= '9') {
        ch = (int)value - 48;
    } else if (value >= 'a' && value <= 'f') {
        ch = (int)value - 87;
    } else if (value >= 'A' && value <= 'F') {
        ch = (int)value - 55;
    } else {
        ch = 0;
    }
    return ch;
}

int f_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    float number = 0;
        int power = -1, sign = 1, i = point, changes_number = 0, changes_power_e = 0, position_e = 0;
        while (str[i] == ' ')
            i++;
        int j = i;
        if (str[i] == '+') {
            sign = 1;
            i++;
        } else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        if (!pars.width) {
            pars.width = length - j;
        } else {
            if (pars.width + j >= length) {
                pars.width = length - j;
            }
        }
        int p = 0, e = 0, plus = 1, power_e = 0;
        while (def_numberScanf(str[i]) == 1 || str[i] == 'e' || str[i] == '.' || str[i] == '+'
               || str[i] == '-' || str[i] == 'E') {
            if (i == pars.width + j) {
                break;
            }
            if (str[i] == '.' && p == 1)
                break;
            if ((str[i] == 'e' || str[i] == 'E') && e == 1) {
                break;
            }
            if (str[i] == '.') {
                p = 1;
            }
            if (str[i] == 'e' || str[i] == 'E') {
                e = 1;
                p = 1;
                position_e = i;
            }
            if ((str[i] == '+' || str[i] == '-') && (str[i - 1] != 'e' && str[i] != 'E'))
                break;
            if ((str[i] == '+') && e == 1 && (str[i - 1] == 'e' || str[i - 1] == 'E'))
                plus = 1;
            if ((str[i] == '-') && e == 1 && (str[i - 1] == 'e' || str[i - 1] == 'E'))
                plus = -1;
            if (p == 0 && def_numberScanf(str[i]) == 1) {
                number = (number * 10) + ((int)str[i] - 48);
                changes_number++;
            }
            if (p == 1 && e == 0 && def_numberScanf(str[i]) == 1) {
                number = number + ((int)str[i] - 48)* pow(10, power);
                power--;
                changes_number++;
            }
            if (p == 1 && e == 1 && def_numberScanf(str[i]) == 1) {
                changes_power_e++;
                power_e = (power_e * 10) + ((int)str[i] - 48);
            }
            i++;
        }
        if (!changes_power_e &&  e == 1)
            i = position_e;
        if (changes_number) {
            if (!pars.star) {
                float *num = va_arg(args, float*);
                *num = number * sign * pow(10, power_e * plus);
                *len_buf += 1;
            }
        } else {
            *error = 1;
        }
        return i;
}

int def_number_16Scanf(char c) {
    int result = 0;
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        result = 1;
    }
    return result;
}

int def_number_8Scanf(char c) {
    int result = 0;
    if (c >= '0' && c <= '7') {
        result = 1;
    }
    return result;
}

int def_numberScanf(char c) {
    int result = 0;
    if (c >= '0' && c <= '9') {
        result = 1;
    }
    return result;
}

int lengScanf(char c) {
    int result = 0;
    if (c == 'L' || c == 'l' || c == 'h') {
        result = 1;
    }
    return result;
}

int form_numberScanf(char *str, int * lenght) {
    int factor = 0;
    char *tmp = str;
    int length1 = 0;
    while (def_numberScanf(*tmp)) {
        factor = (factor * 10) + (*tmp) - 48;
        tmp++;
        length1++;
    }
    *lenght = length1;
    return factor;
}

int specScanf(char c) {
    int result = 0;
    int code[16] = {99, 100, 101, 102, 105, 69, 71, 103, 111, 115, 117, 88, 120, 110, 112, 37};
    for (int i = 0; i <= 16; i++) {
        if (c == code[i]) {
            result = code[i];
        }
    }
    return result;
}

int calling_functionScanf(char *str, parsing pars, va_list args, int *len_buf,
                          int point, int length, int *error) {
    switch (pars.type) {
        case 'd':
            point = d_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'i':
            point = i_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'c':
            point = c_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 's':
            point = s_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'f':
            point = f_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'e':
            point = f_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'E':
            point = f_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'g':
            point = f_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'G':
            point = f_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'x':
            point = x_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'X':
            point = x_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'o':
            point = o_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'n':
            point = n_funcScanf(args, pars, point);
            break;
        case '%':
            break;
        case 'p':
            point = p_funcScanf(str, pars, args, len_buf, point, length, error);
            break;
        case 'u':
            point = u_funcScanf(str, pars, args, len_buf, point, error);
            break;
    }
    return point;
}

int s21_sscanf(char *src, char *format, ...) {
    va_list args;
    int pointer = 0;
    parsing pars;
    int error = 0;
    int length_buf = 0;
    va_start(args, format);
    int length = (int) s21_strlen(src);
    while (*format) {
        // if we meet %
        if (*format == '%') {
            pars.type = 0;
            pars.star = 0;
            pars.width = 0;
            pars.leng = 0;
            format++;
            int flag = 1;
            while (flag) {
                // if we meet *
                if (*format == '*') {
                    pars.star = 1;
                    format++;
                    continue;
                } else if (def_numberScanf(*format)) {
                    int len;
                    pars.width = form_numberScanf(format, &len);
                    format += len;
                    continue;
                } else if (lengScanf(*format)) {
                    pars.leng = *format;
                    format++;
                    continue;
                } else if (specScanf(*format)) {
                    pars.type = *format;
                    format++;
                    flag = 0;
                    continue;
                } else {
                    break;
                }
            }
            pointer = calling_functionScanf(src, pars, args, &length_buf, pointer, length, &error);
            if (error)
                break;
        } else if (*format == ' ') {
            while (src[pointer] == ' ')
                pointer++;
            format++;
        } else {
            if (*format == src[pointer]) {
                pointer++;
                format++;
            } else {
                error = 1;
                break;
            }
        }
    }
    va_end(args);
    return length_buf;
}

int d_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    int number = 0, i = point, sign = 1, changes = 0;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    if (!pars.width) {
        pars.width = length - j;
    } else {
        if (pars.width + j >= length) {
            pars.width = length - j;
        }
    }
    while (def_numberScanf(str[i])) {
        if (i - j == pars.width)
            break;
        number = (number * 10) + (str[i] - 48);
        changes++;
        i++;
    }
    if (changes) {
        if (!pars.star) {
            int *num = va_arg(args, int*);
            *num = number * sign;
            *len_buf += 1;
        }
    } else {
        *error = 1;
    }
    return i;
}

int c_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    if (!pars.star) {
        char *c = (char*)va_arg(args, int*);
        *c = str[point];
        *len_buf += 1;
    }
    if (pars.width > 1) {
        if (point + pars.width < length) {
            point += pars.width;
        } else {
            point = length;
            *error = 1;
        }
    } else {
        point+=1;
        if (!str[point])
            *error = 1;
    }
    return point;
}

int s_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    char *tmp = (char*)malloc(200*sizeof(char));
    int i = point;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (!pars.width) {
        pars.width = length - j;
    } else {
        if (pars.width + j >= length) {
            pars.width = length - j;
        }
    }
    while (i!= pars.width + j) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            break;
        if (str[i] == '\0') {
            *error = 1;
            break;
        }
        i++;
    }
    s21_memmove(tmp, str + j, i - j);
    tmp[i - j] = '\0';
    if (!pars.star) {
        char *c = (char*)va_arg(args, int*);
        *c = '\0';
        s21_strcat(c, tmp);
        *len_buf += 1;
    }
    free(tmp);
    return i;
}

int n_funcScanf(va_list args, parsing pars, int point) {
    if (!pars.star) {
        int *number = va_arg(args, int*);
        *number = point;
    }
    return 1;
}

int u_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int *error) {
    unsigned int number = 0;
    int i = point, sign = 1, changes = 0;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (def_numberScanf(str[i])) {
        if (pars.width != 0 && i - j == pars.width)
            break;
        number = (number * 10) + (str[i] - 48);
        changes++;
        i++;
    }
    if (changes) {
        if (!pars.star) {
            unsigned int *num = va_arg(args, unsigned int*);
            *num = number * sign;
            *len_buf += 1;
        }
    } else {
        *error = 1;
    }
    return i;
}

int p_funcScanf(char *str, parsing pars, va_list args, int *len_buf, int point, int length, int *error) {
    int number = 0, i = point, sign = 1, changes = 0;
    while (str[i] == ' ')
        i++;
    int j = i;
    if (str[i] == '+') {
        sign = 1;
        i++;
    } else if (str[i] == '-') {
        sign = -1;
        i++;
    }
    char *tmp = (char*) malloc (200 * sizeof(char));
    if (!pars.width) {
        pars.width = length - j;
    } else {
        if (pars.width + j >= length) {
            pars.width = length - j;
        }
    }
    int nozero = 0, zero = 0, x_value = 0, x_position = 0;
    while (str[i] == 'x' || str[i] == 'X' || def_number_16Scanf(str[i])) {
        if (i - j == pars.width)
            break;
        if ((str[i] == 'x' || str[i] == 'X') && x_value == 1)
                break;
        if ((str[i] == 'x' || str[i] == 'X') && nozero != 0 && x_value == 0)
            break;
        if ((str[i] == 'x' || str[i] == 'X') && nozero == 0 && x_value == 0) {
            if (zero == 1) {
                x_value = 1;
                x_position = i;
                zero = 0;
            } else if (zero == 0) {
                *error = 1;
                break;
            } else {
                break;
            }
        }
        if (str[i] == '0' && nozero == 0)
            zero++;
    if (nozero != 0 && def_number_16Scanf(str[i]) == 1) {
            tmp[nozero] = str[i];
            nozero++;
        }
    if (str[i] != '0' && def_number_16Scanf(str[i]) == 1 && nozero == 0) {
            tmp[nozero] = str[i];
            nozero++;
        }
        i++;
        changes++;
    }
    tmp[nozero] = '\0';
    int digit, len = (int) s21_strlen(tmp);
    for (j = 0; j < len; j++) {
        digit =  convertFrom16Scanf(tmp[j]);
        number = number + digit * pow(16, len - 1  - j);
    }
    if (x_value == 1 && (zero == 0 && nozero == 0))
        i = x_position;
    free(tmp);
    if (changes) {
        if (!pars.star) {
            int *num = va_arg(args, int*);
            *num = number * sign;
            *len_buf += 1;
        }
    } else {
        *error = 1;
    }
    return i;
}
