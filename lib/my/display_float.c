/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my.h"

int display_float(double num, int n)
{
    long sub;
    int count = 0;

    count += my_put_nbr(num);
    sub = num;
    num = num - sub;
    count += my_putchar('.');
    for (int i = 0; i < n; i++) {
        num = num * 10;
        sub = num;
        count += my_put_nbr(sub % 10);
    }
    return count;
}
