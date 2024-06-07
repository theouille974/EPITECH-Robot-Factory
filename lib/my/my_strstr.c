/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** return the substring of the string if there is one
*/
#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    for (; str[0] != END_OF_STR; i++) {
        if (my_strncmp(str, to_find, my_strlen(to_find)) == 0) {
            return (char *)to_find;
        }
        str += 1;
    }
    return str - i;
}
