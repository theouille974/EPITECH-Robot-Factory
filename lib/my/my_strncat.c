/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** Concatenate two string - n is the limit
*/
#include "my.h"
char *my_strncat(char *dest, char const *src, int n)
{
    int size = my_strlen(src);
    int i = 0;

    if (n < size) {
        size = n;
    }
    while (i != size) {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return dest;
}
