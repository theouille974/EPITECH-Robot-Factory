/*
** EPITECH PROJECT, 2024
** display label
** File description:
** display label
*/

#include "asm.h"

void display_label(label_t **label)
{
    for (int i = 0; label[i]; i++)
        my_printf("[%s]\n", label[i]->name_label);
}
