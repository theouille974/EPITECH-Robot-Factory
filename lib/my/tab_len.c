/*
** EPITECH PROJECT, 2024
** tab len
** File description:
** tab len
*/

#include "my.h"

int tab_len(char **tab)
{
    int len = 0;

    for (len = 0; tab[len]; len++);
    return len;
}
