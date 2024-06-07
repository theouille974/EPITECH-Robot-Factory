/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** Show words in the array
*/

#include "my.h"
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
