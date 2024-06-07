/*
** EPITECH PROJECT, 2023
** significative
** File description:
** check the number of digits after comma (max 6)
*/
#include "my.h"

int significative(double num)
{
    int cmpt = 0;
    int ten = 10;
    int rest;
    int save = 0;

    num = num - (int) num;
    while (cmpt < 6) {
        rest = num * ten;
        rest = rest % 10;
        if (rest != 0)
            save = cmpt + 1;
        ten = ten * 10;
        cmpt++;
    }
    return save;
}
