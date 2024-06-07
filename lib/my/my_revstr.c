/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** Return the reversed string
*/
#include "my.h"

char *my_revstr(char *str)
{
    char swap;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    for (int i = 0; i < count / 2; i++) {
        swap = str[i];
        str[i] = str[count - i - 1];
        str[count - i - 1] = swap;
    }
    return str;
}
