/*
** EPITECH PROJECT, 2024
** free structure
** File description:
** free structure asm_t
*/

#include "asm.h"

int my_free_struct(asm_t *asm_st, int status)
{
    if (asm_st->content_file != NULL)
        free_tab(asm_st->content_file);
    if (asm_st->name_file != NULL)
        free(asm_st->name_file);
    if (asm_st->label != NULL)
        free_label(asm_st->label);
    if (asm_st->buffer != NULL)
        free(asm_st->buffer);
    free(asm_st);
    return status;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_label(label_t **label)
{
    for (int i = 0; label[i] != NULL; i++) {
        free(label[i]->name_label);
        free_int_et2(label[i]);
        free(label[i]);
    }
    free(label);
}

void free_int_et2(label_t *label)
{
    free(label->where_command);
    free(label->where_write);
    free(label->size);
}
