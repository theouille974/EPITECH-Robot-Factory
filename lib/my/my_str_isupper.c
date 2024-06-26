/*
** EPITECH PROJECT, 2023
** my_str_isupper.c
** File description:
** Check if the string contains only uppercase alphabet
*/
#include "my.h"
int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            return 0;
        }
    }
    return 1;
}
