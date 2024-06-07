/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** print the number either if its negative or not
*/
#include "my.h"
int my_put_nbr_unsigned(unsigned int nb)
{
    int operator = 1;
    int count = 0;

    while (nb / operator > 9) {
        operator *= 10;
    }
    while (operator > 9) {
        count += my_putchar(nb / operator + '0');
        nb %= operator;
        operator /= 10;
    }
    count += my_putchar(nb + '0');
    return count;
}
