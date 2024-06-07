/*
** EPITECH PROJECT, 2024
** parse_instruction
** File description:
** parse instrcution
*/

#include "asm.h"

void update_adress(asm_t *asm_st, char *label)
{
    int nb_lab = 0;

    for (; asm_st->label[nb_lab]; nb_lab++) {
        if (my_strcmp(asm_st->label[nb_lab]->name_label, label) == 0) {
            asm_st->label[nb_lab]->address = asm_st->buffer_size - HEADER;
            break;
        }
    }
}

static int parse_instruction_to(asm_t *asm_st, int i, char **inst, int p)
{
    for (int j = 0; j < our_tab[i].arg_number; j++) {
        asm_st->arg_pos = j;
        if (!our_tab[i].fun[j](inst[j + 1], asm_st, our_tab[i].is_index, p)) {
            return 84;
        }
    }
    return 0;
}

int parse_instruction(asm_t *asm_st, char **instruction)
{
    int pos_pb = -1;

    if (!instruction)
        return 84;
    if (!instruction[0])
        return 84;
    for (int i = 1; i < 17; i++) {
        if (my_strcmp(instruction[0], our_tab[i].op_name) != 0)
            continue;
        if (tab_len(instruction) != our_tab[i].arg_number + 1)
            return 84;
        asm_st->pos_in_file = asm_st->buffer_size - HEADER;
        write_in_buffer(asm_st, (uint8_t[]){our_tab[i].number}, 1);
        if (our_tab[i].coding_byte) {
            pos_pb = asm_st->buffer_size;
            write_in_buffer(asm_st, (uint8_t[]){0x00}, 1);
        }
        return parse_instruction_to(asm_st, i, instruction, pos_pb);
    }
    return 84;
}

static int parse_intructions_to(asm_t *asm_st, char **tmp)
{
    if (tmp[0][my_strlen(tmp[0]) - 1] == ':') {
        tmp[0][my_strlen(tmp[0]) - 1] = 0;
        update_adress(asm_st, tmp[0]);
        if (parse_instruction(asm_st, tmp + 1) == 84) {
            free_tab(tmp);
            return 84;
        }
        return 0;
    }
    if (parse_instruction(asm_st, tmp) == 84) {
        free_tab(tmp);
        return 84;
    }
    return 0;
}

int parse_instructions(asm_t *asm_st)
{
    char **tmp = NULL;

    for (int i = 0; asm_st->content_file[i]; i++) {
        if (i < 2)
            continue;
        tmp = my_str_to_word_array(asm_st->content_file[i], " \t,");
        if (parse_intructions_to(asm_st, tmp) == 84)
            return 84;
        free_tab(tmp);
    }
    return 0;
}
