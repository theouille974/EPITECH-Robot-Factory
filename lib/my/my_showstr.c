/*
** EPITECH PROJECT, 2023
** my_showstr.c
** File description:
** Show all the string, hidden characters in hexadecimal
*/
#include "my.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 20 || str[i] == 127) {
            my_putchar('\\');
            my_putnbr_b(str[i], "HEX", 'x');
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
