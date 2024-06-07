/*
** EPITECH PROJECT, 2023
** spaces
** File description:
** if several spaces, move the index until the flag
*/

#include "my.h"
int spaces(char const *fmt, int n)
{
    int cspaces = 0;

    while (fmt[n + cspaces] == ' ') {
        cspaces++;
    }
    return cspaces;
}
