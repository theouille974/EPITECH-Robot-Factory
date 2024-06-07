/*
** EPITECH PROJECT, 2024
** display tab
** File description:
** display tab
*/

#include "my.h"

void display_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("[%s]\n", tab[i]);
}
