/*
** EPITECH PROJECT, 2024
** add reg
** File description:
** add reg
*/

#include "asm.h"

bool add_rg(char *tab, asm_t *asm_st, bool index, int p)
{
    int reg_num = is_register(tab);

    (void)index;
    if (reg_num == -1)
        return false;
    write_in_buffer(asm_st, (uint8_t[]){reg_num}, 1);
    if (p != -1)
        asm_st->buffer[p] = asm_st->buffer[p] | (0b01 << mv_tab[asm_st->arg_pos]);
    return true;
}

bool add_rg_or_id(char *tab, asm_t *asm_st, bool index, int p)
{
    bool reg = add_rg(tab, asm_st, index, p);
    bool id = add_id(tab, asm_st, index, p);

    if (!reg && !id)
        return false;
    return true;
}

bool add_rg_or_dr(char *tab, asm_t *asm_st, bool index, int p)
{
    bool reg = add_rg(tab, asm_st, index, p);
    bool dir = add_dr(tab, asm_st, index, p);

    if (!reg && !dir)
        return false;
    return true;
}

bool add_rg_or_id_or_dr(char *tab, asm_t *asm_st, bool index, int p)
{
    bool reg = add_rg(tab, asm_st, index, p);
    bool id = add_id(tab, asm_st, index, p);
    bool dr = add_dr(tab, asm_st, index, p);

    if (!reg && !id && !dr)
        return false;
    return true;
}
