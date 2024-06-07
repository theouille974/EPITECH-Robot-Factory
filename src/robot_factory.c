/*
** EPITECH PROJECT, 2024
** robot factory
** File description:
** robot factury
*/

#include "asm.h"

label_t **init_struct_label(void)
{
    label_t **label = malloc(sizeof(label_t *));

    label[0] = NULL;
    return label;
}

asm_t *init_struct(void)
{
    asm_t *asm_st = malloc(sizeof(asm_t));

    asm_st->content_file = NULL;
    asm_st->name_file = NULL;
    asm_st->pos_in_file = 0;
    asm_st->size_cont = 0;
    asm_st->label = init_struct_label();
    asm_st->size_tab_label = 0;
    asm_st->buffer = NULL;
    asm_st->buffer_size = 0;
    asm_st->arg_pos = 0;
    return asm_st;
}

int robot_factory(char **av)
{
    asm_t *asm_st = init_struct();
    char **label = NULL;

    if (file_errors(av))
        return my_free_struct(asm_st, 84);
    recup_name_file(asm_st, av[1]);
    asm_st->content_file = open_file(av[1]);
    if (asm_content_error(asm_st))
        return my_free_struct(asm_st, 84);
    label = find_label(asm_st->content_file);
    if (label == NULL)
        return my_free_struct(asm_st, 84);
    load_label(label, asm_st);
    free_tab(label);
    return parse_file(asm_st);
}
