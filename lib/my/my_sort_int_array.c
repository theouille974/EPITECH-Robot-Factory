/*
** EPITECH PROJECT, 2023
** my_sort_int_array.c
** File description:
** Sort a modifiable array
*/
#include <stdio.h>
#include "my.h"

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (tab[i] > tab[i + 1]) {
            my_swap(&tab[i], &tab[i + 1]);
            i = 0;
        }
    }
    return;
}
