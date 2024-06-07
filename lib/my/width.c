/*
** EPITECH PROJECT, 2023
** width.c
** File description:
** set the number of spaces written after the flag
** and before the specifier. If width is not specified
** then the width is treated as zero
*/

#include "my.h"

int width(char const *fmt, int start)
{
    int i = 0;
    int val = 0;
    int index = i + start;

    while (specifiers(fmt[i + start]) == 0) {
        index = i + start;
        if (is_num(fmt[index])) {
            val += val * 10 + (fmt[index] - '0');
            i++;
        }
    }
    left_justify_spaces(val - 1);
    return i;
}
