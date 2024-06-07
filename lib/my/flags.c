/*
** EPITECH PROJECT, 2023
** flags
** File description:
** handle my_printf's flags
*/

#include "my.h"
#include <stdarg.h>

int flags_2(char const *fmt, int *i, va_list list, int count)
{
    int cmpt = 0;
    int c = 0;
    int nums = 0;

    switch (fmt[*i + 1]) {
        case '#':
            cmpt += display_hash(fmt, *i + 2);
            *i = *i + 1;
            return flags(fmt, i, list, count) + cmpt;
        case '0':
            nums += left_justify_count(fmt, *i, &cmpt);
            *i += nums;
            c += left_justify_zeros(cmpt - nums);
            c += flags(fmt, i, list, count);
            return c;
        default:
            return display_fmt(fmt, *i, list, count);
    }
    return 0;
}

int flags(char const *fmt, int *i, va_list list, int count)
{
    int cmpt = 0;
    int nums = 0;
    int cmpt_flag = 0;

    switch (fmt[*i + 1]) {
        case ' ':
            *i += spaces(fmt, *i + 1);
            return flags(fmt, i, list, count);
        case '-':
            nums = left_justify_count(fmt, *i + 2, &cmpt);
            *i += nums + 1;
            cmpt_flag += flags(fmt, i, list, count);
            return left_justify_spaces(cmpt - cmpt_flag) + cmpt_flag;
        default:
            return flags_2(fmt, i, list, count);
    }
}
