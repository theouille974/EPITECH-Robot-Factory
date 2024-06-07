/*
** EPITECH PROJECT, 2024
** replace label
** File description:
** replace label
*/

#include "asm.h"

uint8_t adr(int address, int where_command, int bit, uint8_t mask)
{
    int new_value = address - where_command;

    return (uint8_t)((new_value >> bit) & mask);
}

void replace_label_2_bytes(asm_t *asm_st, label_t **lb, int i, int y)
{
    int M = 0xff;
    int adress = lb[i]->address;
    int cmd = lb[i]->where_command[y];

    if (lb[i]->size[y] == 2) {
        asm_st->buffer[lb[i]->where_write[y] + 0] = adr(adress, cmd, 8, M);
        asm_st->buffer[lb[i]->where_write[y] + 1] = adr(adress, cmd, 0, M);
    }
}

void replace_label_4_bytes(asm_t *asm_st, label_t **lb, int i, int y)
{
    int M = 0xff;
    int adress = lb[i]->address;
    int cmd = lb[i]->where_command[y];

    if (lb[i]->size[y] == 4) {
        asm_st->buffer[lb[i]->where_write[y] + 0] = adr(adress, cmd, 24, M);
        asm_st->buffer[lb[i]->where_write[y] + 1] = adr(adress, cmd, 16, M);
        asm_st->buffer[lb[i]->where_write[y] + 2] = adr(adress, cmd, 8, M);
        asm_st->buffer[lb[i]->where_write[y] + 3] = adr(adress, cmd, 0, M);
    }
}

void replace_label(asm_t *asm_st)
{
    for (int i = 0; asm_st->label[i]; i++) {
        for (int y = 0; y < asm_st->label[i]->nb_call_lab; y++) {
            replace_label_4_bytes(asm_st, asm_st->label, i, y);
            replace_label_2_bytes(asm_st, asm_st->label, i, y);
        }
    }
}
