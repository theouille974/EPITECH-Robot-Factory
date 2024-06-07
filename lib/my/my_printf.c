/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** A small version of printf - with C99 flags
*/

#include "my.h"
#include <stdarg.h>

int my_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != END_OF_STR; i++) {
        if (format[i] == '%') {
            count += flags(format, &i, list, count);
            i++;
        } else {
            count += post_display(format[i], format, i);
        }
    }
    va_end(list);
    return count;
}
