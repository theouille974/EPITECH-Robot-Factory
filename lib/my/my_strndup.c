/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** Duplicate n charactere of the string given in parameter
*/

#include "my.h"
#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));

    if (!dest)
        return NULL;
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return dest;
}
