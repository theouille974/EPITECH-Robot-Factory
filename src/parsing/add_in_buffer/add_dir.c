/*
** EPITECH PROJECT, 2024
** add dir
** File description:
** add dir
*/

#include "asm.h"

static bool add_dr_to(char *tab, asm_t *asm_st, bool index, int p)
{
    int value = 0;

    if (is_str_number(tab + 1)) {
        value = my_getnbr(tab + 1);
        if (!index){
            write_in_buffer(asm_st, (uint8_t[]){(value >> 24) & 0xff}, 1);
            write_in_buffer(asm_st, (uint8_t[]){(value >> 16) & 0xff}, 1);
        }
        write_in_buffer(asm_st, (uint8_t[]){(value >> 8) & 0xff}, 1);
        write_in_buffer(asm_st, (uint8_t[]){value & 0xff}, 1);
    }
    if (p != -1)
        asm_st->buffer[p] = asm_st->buffer[p] | (0b10 << mv_tab[asm_st->arg_pos]);
    return true;
}

bool add_dr(char *tab, asm_t *asmst, bool index, int p)
{
    int size = (index) ? 2 : 4;

    if (!is_direct(asmst, tab))
        return false;
    if (is_label(asmst, tab + 2)) {
        maj_label(asmst, asmst->label, tab + 2, size);
        write_in_buffer(asmst, (uint8_t[]){0x00, 0x00, 0x00, 0x00}, size);
        if (p != -1)
            asmst->buffer[p] = asmst->buffer[p] | (0b10 << mv_tab[asmst->arg_pos]);
        return true;
    }
    return add_dr_to(tab, asmst, index, p);
}
