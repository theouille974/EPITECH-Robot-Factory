/*
** EPITECH PROJECT, 2023
** my_strcapitalize.c
** File description:
** Capitalize the first letter of each words
*/
#include "my.h"
char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i - 1] == ' ') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
