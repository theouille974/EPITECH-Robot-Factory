/*
** EPITECH PROJECT, 2023
** left-justify
** File description:
** Justify the given width. This width is a integer
** preceded by a dash -
*/

#include "my.h"

int left_justify_count(char const *fmt, int start, int *cmpt)
{
    int i = start;
    int count = 0;

    for (; specifiers(fmt[i]) == 0; i++) {
        if (is_num(fmt[i])) {
            *cmpt = *cmpt * 10 + (fmt[i] - '0');
            count++;
        }
    }
    return count;
}

int left_justify_spaces(int n)
{
    for (int i = 0; i < n; i++)
        my_putchar(' ');
    return n;
}

int left_justify_zeros(int n)
{
    for (int i = 0; i < n; i++) {
        my_putchar('0');
    }
    return n;
}
