/*
** EPITECH PROJECT, 2023
** display_hash
** File description:
** display the oct/hex with 0, 0x or 0X
*/

#include "my.h"
int display_hash(char const *fmt, int count)
{
    while (fmt[count] != ' ') {
        if (fmt[count] == 'o')
            return my_putchar('0');
        if (fmt[count] == 'x')
            return my_putstr("0x");
        if (fmt[count] == 'X')
            return my_putstr("0X");
        count++;
    }
    return 0;
}
