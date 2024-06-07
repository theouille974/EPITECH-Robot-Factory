/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** is_str_number
*/

#include "my.h"

bool is_str_number(char *const str)
{
    int index = 0;

    if (!str)
        return false;
    for (; str[index] == '-' || str[index] == '+'; index ++)
        if (str[index] == '\0')
            return false;
    for (; str[index] != '\0'; index ++)
        if (!is_num(str[index]))
            return false;
    return true;
}
