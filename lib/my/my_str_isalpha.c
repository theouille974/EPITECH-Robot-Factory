/*
** EPITECH PROJECT, 2023
** my_str_isalpha.c
** File description:
** check if the string contains only alphabetic characters
*/
#include "my.h"
int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A') {
            return 0;
        }
        if (str[i] > 'Z' && str[i] < 'a') {
            return 0;
        }
        if (str[i] > 'z') {
            return 0;
        }
    }
    return 1;
}
