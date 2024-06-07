/*
** EPITECH PROJECT, 2023
** display_exponent.c
** File description:
** display with the exponent
*/

#include "my.h"

float is_nega(float n, int *count)
{
    if (n < 0) {
        *count += my_putchar('-');
        return -n;
    }
    return n;
}

int exp_disp(char exp, int cmpt, char s, int count)
{
    int i = 0;

    if (exp == 'e')
        i += my_putchar('e');
    else
        i += my_putchar('E');
    i += my_putchar(s);
    if (cmpt < 10)
        i += my_put_nbr(0);
    i += count + my_put_nbr(cmpt);
    return i;
}

int display_exponent(double n, int e, char exp)
{
    int count = 0;
    int cmpt = 0;
    char sign;

    n = is_nega(n, &count);
    if (n > 1) {
        sign = '+';
        for (int i = 0; n > 10; i++) {
            n = n / 10;
            cmpt++;
        }
    } else {
        sign = '-';
        for (int i = 0; n < 1; i++) {
            n = n * 10;
            cmpt++;
        }
    }
    count += display_float(n, e);
    return exp_disp(exp, cmpt, sign, count);
}
