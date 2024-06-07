/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** basic_instruct
*/

#include "asm.h"

bool is_label(asm_t *asm_st, char *str)
{
    for (int i = 0; asm_st->label[i] != NULL; i ++){
        if (my_strcmp(asm_st->label[i]->name_label, str) == 0)
            return true;
    }
    return false;
}

int is_register(char *line)
{
    int len = my_strlen(line);

    if (len != 2 && len != 3)
        return -1;
    if (line[0] != 'r')
        return -1;
    if (!my_str_isnum(line + 1))
        return -1;
    return my_getnbr(line + 1);
}

bool is_direct(asm_t *asm_st, char *line)
{
    if (line[0] != DIRECT_CHAR)
        return false;
    if (line[1] == LABEL_CHAR) {
        if (is_label(asm_st, line + 2))
            return true;
        return false;
    }
    if (is_str_number(line + 1))
        return true;
    return false;
}

char *is_indirect(asm_t *asm_st, char *line)
{
    if (!line)
        return NULL;
    if (is_label(asm_st, line + 1))
        return line + 1;
    if (is_str_number(line))
        return line;
    return NULL;
}
