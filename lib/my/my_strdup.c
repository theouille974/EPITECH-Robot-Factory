/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** Duplicate the string given in parameter
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = 0;
    return dest;
}
