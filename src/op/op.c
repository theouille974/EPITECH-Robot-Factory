/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** op
*/

#include "../include/op.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6},
    {"zjmp", 1, {T_DIR}, 9, 20},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25},
    {"fork", 1, {T_DIR}, 12, 800},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50},
    {"lfork", 1, {T_DIR}, 15, 1000},
    {"aff", 1, {T_REG}, 16, 2},
    {0, 0, {0}, 0, 0}
};
