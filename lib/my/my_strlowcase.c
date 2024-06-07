/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** Transform the string into an LOWERCASE string
*/
#include "my.h"
char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}
