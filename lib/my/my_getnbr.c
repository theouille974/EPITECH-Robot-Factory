/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** return the number the string
*/
#include "my.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int number = 0;

    while (str[i] == '+' || str[i] == '-') {
        sign = (str[i] == '-') ? -sign : sign;
        i++;
    }
    while (is_num(str[i])) {
        if (is_num(str[i])) {
            number = number * 10 + (str[i] - '0');
        }
        i++;
    }
    return number * sign;
}
