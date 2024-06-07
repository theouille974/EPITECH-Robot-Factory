/*
** EPITECH PROJECT, 2023
** flags
** File description:
** Accept only mini_printf flags
*/

#include "my.h"
int special_specifiers(char c)
{
    if (c == 'x')
        return 1;
    if (c == 'X')
        return 1;
    if (c == 'e')
        return 1;
    if (c == 'E')
        return 1;
    if (c == 'g')
        return 1;
    if (c == 'G')
        return 1;
    if (c == 'p')
        return 1;
    if (c == 'n')
        return 1;
    return 0;
}

int specifiers(char c)
{
    if (c == 'i')
        return 1;
    if (c == 'c')
        return 1;
    if (c == 's')
        return 1;
    if (c == 'd')
        return 1;
    if (c == 'f')
        return 1;
    if (c == 'o')
        return 1;
    if (c == 'u')
        return 1;
    return special_specifiers(c);
}
