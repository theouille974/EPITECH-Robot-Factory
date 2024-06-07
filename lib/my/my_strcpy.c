/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copy an entire string from another
*/
#include "my.h"
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
