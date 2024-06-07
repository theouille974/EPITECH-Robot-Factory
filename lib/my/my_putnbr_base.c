/*
** EPITECH PROJECT, 2023
** my_putnbr_base
** File description:
** display the decimal number into a number
** in a given base (hex, oct, bin...)
*/

#include "my.h"
#include <stdio.h>

int base_operator(const char *base)
{
    if (my_strcmp(base, "BIN") == 0)
        return 2;
    if (my_strcmp(base, "OCT") == 0)
        return 8;
    if (my_strcmp(base, "HEX") == 0)
        return 16;
    return 0;
}

int is_hexa(int quo, char l)
{
    if (l == 'x')
        l = 'a';
    else
        l = 'A';
    if (quo >= 10) {
        my_putchar(quo % 10 + l);
    } else {
        my_putchar(quo + '0');
    }
    return 1;
}

int my_putnbr_b(long n, char const *base, char letter)
{
    long operator = base_operator(base);
    int count = 0;

    if (n < base_operator(base))
        return is_hexa(n, letter);
    while (n / operator >= base_operator(base))
        operator *= base_operator(base);
    while (operator > base_operator(base) - 1) {
        count += is_hexa(n / operator, letter);
        n %= operator;
        operator /= base_operator(base);
    }
    count += is_hexa(n, letter);
    return count;
}
