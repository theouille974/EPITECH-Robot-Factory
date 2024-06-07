/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Concatenate two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int size = my_strlen(dest);

    while (i != my_strlen(src)) {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return dest;
}
