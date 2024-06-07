/*
** EPITECH PROJECT, 2024
** maj labels
** File description:
** maj label
*/

#include "asm.h"

void maj_label(asm_t *asm_st, label_t **l, char *tab, int type)
{
    int nc = 0;
    int *wr = NULL;
    int *wc = NULL;

    for (int i = 0; l[i] != NULL; i ++){
        if (my_strcmp(l[i]->name_label, tab) == 0) {
            nc = l[i]->nb_call_lab;
            l[i]->size = realloc(l[i]->size, sizeof(int) * (nc + 1));
            l[i]->size[nc] = type;
            wr = l[i]->where_write;
            l[i]->where_write = realloc(wr, sizeof(int) * (nc + 1));
            l[i]->where_write[nc] = asm_st->buffer_size;
            l[i]->nb_call_lab++;
            wc = l[i]->where_command;
            l[i]->where_command = realloc(wc, sizeof(int) * (nc + 1));
            l[i]->where_command[nc] = asm_st->pos_in_file;
        }
    }
}
