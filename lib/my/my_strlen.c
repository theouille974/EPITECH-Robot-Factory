/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Display the string length given in parameter
*/
#include "my.h"

int my_strlen(char const *str)
{
    return my_strlen_to(str, '\0');
}

int my_strlen_to(char const *str, char to)
{
    int count = 0;

    if (!str)
        return 0;
    for (count = 0; str[count] != '\0' && str[count] != to; count++);
    return count;
}
