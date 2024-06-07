/*
** EPITECH PROJECT, 2023
** display_double_g
** File description:
** significative numbers
*/

#include "my.h"

int display_double_g(double num)
{
    if (num < 1000000 && num > 0.1)
        display_float(num, significative(num));
    else
        display_exponent(num, significative(num), 'e');
    return 0;
}
