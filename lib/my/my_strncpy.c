/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** Return a string with n characters given in parameter
*/
#include "my.h"
#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
