/*
** EPITECH PROJECT, 2023
** my_str_islower.c
** File description:
** Check if the string contains only lowercase alphabet
*/
#include "my.h"
int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ' || str[i] == 127) {
            return 0;
        }
    }
    return 1;
}
