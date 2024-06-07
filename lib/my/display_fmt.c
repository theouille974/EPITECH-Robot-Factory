/*
** EPITECH PROJECT, 2023
** display_fmt
** File description:
** Display in function of a specific format
*/

#include "my.h"
#include "my.h"
#include <stdarg.h>

int display_fmt_2(const char *fmt, int n, va_list list, int count)
{
    switch (fmt[n + 1]) {
        case 'X':
            return my_putnbr_b(va_arg(list, int), "HEX", 'X');
        case 'x':
            return my_putnbr_b(va_arg(list, int), "HEX", 'x');
        case 'E':
            return display_exponent(va_arg(list, double), 6, 'E');
        case 'e':
            return display_exponent(va_arg(list, double), 6, 'e');
        case 'p':
            return my_put_adress(va_arg(list, void *));
        case 'g':
            return display_double_g(va_arg(list, double));
        case 'n':
            return count_c(va_arg(list, int *), count);
        default:
            return my_putchar('%');
    }
    return 1;
}

int display_fmt(const char *fmt, int n, va_list list, int count)
{
    switch (fmt[n + 1]) {
        case 'c':
            return my_putchar(va_arg(list, int));
        case 's':
            return my_putstr(va_arg(list, char *));
        case 'i':
        case 'd':
            return my_put_nbr(va_arg(list, int));
        case 'f':
            return display_float(va_arg(list, double), 6);
        case 'o':
            return my_putnbr_b(va_arg(list, int), "OCT", 'a');
        case 'u':
            return my_put_nbr_unsigned(va_arg(list, unsigned int));
        case '%':
            return my_putchar('%');
    }
    return display_fmt_2(fmt, n, list, count);
}
