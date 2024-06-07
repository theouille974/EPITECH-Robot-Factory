/*
** EPITECH PROJECT, 2024
** tab_label_len
** File description:
** tab lable len
*/

#include "asm.h"

int tab_label_len(label_t **label)
{
    int len = 0;

    for (len = 0; label[len]; len++);
    return len;
}
