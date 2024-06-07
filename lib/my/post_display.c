/*
** EPITECH PROJECT, 2023
** post_display
** File description:
** post_display
*/

#include "my.h"

int post_display(char c, char const *fmt, int i)
{
    int count = 0;

    if (fmt[i] == '%' && fmt[i + 1] == ' ')
        count += my_putchar('%');
    if (c != '%') {
        count += my_putchar(c);
    }
    return count;
}
