/*
** EPITECH PROJECT, 2024
** add ind
** File description:
** add ind
*/

#include "asm.h"

bool add_id(char *tab, asm_t *asm_st, bool index, int p)
{
    char *id = is_indirect(asm_st, tab);
    int value = 0;

    (void)index;
    if (!id)
        return false;
    if (is_label(asm_st, tab + 1)) {
        maj_label(asm_st, asm_st->label, tab + 1, IND_SIZE);
        write_in_buffer(asm_st, (uint8_t[]){0x00, 0x00}, 2);
    } else if (is_str_number(id)) {
            value = my_getnbr(id);
            write_in_buffer(asm_st, (uint8_t[]){(value >> 8) & 0xff}, 1);
            write_in_buffer(asm_st, (uint8_t[]){(value) & 0xff}, 1);
        }
    if (p != -1)
        asm_st->buffer[p] = asm_st->buffer[p] | (0b11 << mv_tab[asm_st->arg_pos]);
    return true;
}

bool add_id_or_dr(char *tab, asm_t *asm_st, bool index, int p)
{
    bool id = add_id(tab, asm_st, index, p);
    bool dr = add_dr(tab, asm_st, index, p);

    if (!id && !dr)
        return false;
    return true;
}
