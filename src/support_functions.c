#include"s_printf.h"
#include<stdio.h>



//MARK: Main
int _sprintf(char *buf,const char *format, ...)
{
    int printed_chars;
    conver_t f_list[] = {
        {"c", _sprintf_char},
        //        {"d", _sprintf_integer},
        //        {"i", _sprintf_integer},
        //        {"o", _sprint_octal},
        //        {"x", _sprint_hex},
        //        {"X", _sprint_heX},
        //        {"s", _sprint_string},
        //        {"%", _sprint_percent},
        //        {"%u", _sprint_unsigned_integer},
        
        {NULL, NULL}
    };
    
    va_list arg_list;
    
    if (format == NULL)
        return (-1);
    
    va_start(arg_list, format);
    
    
    printed_chars = parser(buf,format, f_list, arg_list);
    va_end(arg_list);
    return (printed_chars);
}





//MARK: - Parser
int parser(char *buf,const char *format, conver_t f_list[], va_list arg_list)
{
    int i, j, r_val, printed_chars;
    
    printed_chars = 0;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            
            for (j = 0; f_list[j].sym != NULL; j++)
            {
                if (format[i + 1] == f_list[j].sym[0])
                {
                    r_val = f_list[j].f(buf,arg_list);
                    if (r_val == -1)
                        return (-1);
                    printed_chars += r_val;
                    break;
                }
            }
            if (f_list[j].sym == NULL && format[i + 1] != ' ')
            {
                if (format[i + 1] != '\0')
                {
                    _write_char(buf,format[i]);
                    _write_char(buf,format[i + 1]);
                    printed_chars = printed_chars + 2;
                }
                else
                    return (-1);
            }
            i = i + 1;
        }
        
        else
        {
            _write_char(buf,format[i]);
            printed_chars++;
        }
    }
    return (printed_chars);
}




//MARK: -Support Functions
void _write_char(char * buf,char c)
{
    int index = 0;
    while (1) {
        buf[index] = c;
        index ++;
        break;
    }
}


int _sprintf_char(char *buf,va_list list)
{
    _write_char(buf,va_arg(list, int));
    return (1);
}


//
//int _sprintf_integer(va_list list)
//{
//    int num_length;
//
//    num_length = _print_number(list);
//    return (num_length);
//}
//
//
//int _print_number(va_list args)
//{
//    int n;
//    int div;
//    int len;
//    unsigned int num;
//
//    n  = va_arg(args, int);
//    div = 1;
//    len = 0;
//
//    if (n < 0)
//    {
//        len += _write_char('-');
//        num = n * -1;
//    }
//    else
//        num = n;
//
//    for (; num / div > 9; )
//        div *= 10;
//
//    for (; div != 0; )
//    {
//        len += _write_char('0' + num / div);
//        num %= div;
//        div /= 10;
//    }
//
//    return (len);
//}
//
//
//int _sprint_octal(va_list list)
//{
//    unsigned int num;
//    int len;
//    char *octal_rep;
//    char *rev_str;
//
//    num = va_arg(list, unsigned int);
//
//    if (num == 0)
//        return (_write_char('0'));
//    if (num < 1)
//        return (-1);
//    len = base_len(num, 8);
//
//    octal_rep = malloc(sizeof(char) * len + 1);
//    if (octal_rep == NULL)
//        return (-1);
//    for (len = 0; num > 0; len++)
//    {
//        octal_rep[len] = (num % 8) + 48;
//        num = num / 8;
//
//    }
//    octal_rep[len] = '\0';
//    rev_str = rev_string(octal_rep);
//    if (rev_str == NULL)
//        return (-1);
//
//    write_base(rev_str);
//    free(octal_rep);
//    free(rev_str);
//    return (len);
//}
//
//
//unsigned int base_len(unsigned int num, int base)
//{
//    unsigned int i;
//
//    for (i = 0; num > 0; i++)
//    {
//        num = num / base;
//    }
//    return (i);
//}
//
//
//char *rev_string(char *s)
//{
//    int len;
//    int head;
//    char tmp;
//    char *dest;
//
//    for (len = 0; s[len] != '\0'; len++)
//    {}
//
//    dest = malloc(sizeof(char) * len + 1);
//    if (dest == NULL)
//        return (NULL);
//
//    s21_memcpy(dest, s, len);
//    for (head = 0; head < len; head++, len--)
//    {
//        tmp = dest[len - 1];
//        dest[len - 1] = dest[head];
//        dest[head] = tmp;
//    }
//    return (dest);
//}
//
//
//void * s21_memcpy(void *dest, const void *src, s21_size_t n) {
//
//
//    char *p = (char*)dest;
//    char *p1 = (char*)src;
//    while (n--) {
//        *p = *p1;
//        p++;
//        p1++;
//    }
//
//    return dest;
//}
//
//void write_base(char *str)
//{
//    int i;
//
//    for (i = 0; str[i] != '\0'; i++)
//        _write_char(str[i]);
//}
//
//
//
//int _sprint_hex(va_list list)
//{
//    unsigned int num;
//    int len;
//    int rem_num;
//    char *hex_rep;
//    char *rev_hex;
//
//    num = va_arg(list, unsigned int);
//
//    if (num == 0)
//        return (_write_char('0'));
//    if (num < 1)
//        return (-1);
//    len = base_len(num, 16);
//    hex_rep = malloc(sizeof(char) * len + 1);
//    if (hex_rep == NULL)
//        return (-1);
//    for (len = 0; num > 0; len++)
//    {
//        rem_num = num % 16;
//        if (rem_num > 9)
//        {
//            rem_num = hex_check(rem_num, 'x');
//            hex_rep[len] = rem_num;
//        }
//        else
//            hex_rep[len] = rem_num + 48;
//        num = num / 16;
//    }
//    hex_rep[len] = '\0';
//    rev_hex = rev_string(hex_rep);
//    if (rev_hex == NULL)
//        return (-1);
//    write_base(rev_hex);
//    free(hex_rep);
//    free(rev_hex);
//    return (len);
//}
//
//int hex_check(int num, char x)
//{
//    char *hex = "abcdef";
//    char *Hex = "ABCDEF";
//
//    num = num - 10;
//    if (x == 'x')
//        return (hex[num]);
//    else
//        return (Hex[num]);
//    return (0);
//}
//
//
//int _sprint_heX(va_list list)
//{
//    unsigned int num;
//    int len;
//    int rem_num;
//    char *hex_rep;
//    char *rev_hex;
//
//    num = va_arg(list, unsigned int);
//
//    if (num == 0)
//        return (_write_char('0'));
//    if (num < 1)
//        return (-1);
//    len = base_len(num, 16);
//    hex_rep = malloc(sizeof(char) * len + 1);
//    if (hex_rep == NULL)
//        return (-1);
//    for (len = 0; num > 0; len++)
//    {
//        rem_num = num % 16;
//        if (rem_num > 9)
//        {
//            rem_num = hex_check(rem_num, 'X');
//            hex_rep[len] = rem_num;
//        }
//        else
//            hex_rep[len] = rem_num + 48;
//        num = num / 16;
//    }
//    hex_rep[len] = '\0';
//    rev_hex = rev_string(hex_rep);
//    if (rev_hex == NULL)
//        return (-1);
//    write_base(rev_hex);
//    free(hex_rep);
//    free(rev_hex);
//    return (len);
//}
//
//int _sprint_string(va_list list)
//{
//    int i;
//    char *str;
//
//    str = va_arg(list, char *);
//    if (str == NULL)
//        str = "(null)";
//    for (i = 0; str[i] != '\0'; i++)
//        _write_char(str[i]);
//    return (i);
//}
//
//
//int _sprint_percent(__attribute__((unused))va_list list)
//{
//    _write_char('%');
//    return (1);
//}
//
//
//int _sprint_unsigned_integer(va_list list)
//{
//    unsigned int num;
//
//    num = va_arg(list, unsigned int);
//
//    if (num == 0)
//        return num;
//
//    if (num < 1)
//        return (-1);
//
//    return num;
//}
