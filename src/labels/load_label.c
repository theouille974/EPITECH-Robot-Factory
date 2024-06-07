/*
** EPITECH PROJECT, 2024
** load_label
** File description:
** load label in struct of label
*/

#include "asm.h"

void load_label(char **label_tab, asm_t *asm_st)
{
    int len = tab_len(label_tab);

    asm_st->size_tab_label = len;
    asm_st->label = realloc(asm_st->label, sizeof(label_t *) * (len + 1));
    for (int i = 0; label_tab[i]; i++) {
        asm_st->label[i] = malloc(sizeof(label_t));
        asm_st->label[i]->name_label = my_strdup(label_tab[i]);
        asm_st->label[i]->address = -1;
        asm_st->label[i]->nb_call_lab = 0;
        asm_st->label[i]->where_command = NULL;
        asm_st->label[i]->where_write = NULL;
        asm_st->label[i]->size = NULL;
    }
    asm_st->label[len] = NULL;
}
