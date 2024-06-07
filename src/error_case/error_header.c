/*
** EPITECH PROJECT, 2024
** error header
** File description:
** error header
*/

#include "asm.h"

bool error_header_to(char *name_file, int i, int size)
{
    int count_c = 0;

    for (; name_file[i] != '\"' && name_file[i] != '\0'; i++)
        count_c++;
    if (name_file[i] == '\0')
        return false;
    if (count_c > size)
        return false;
    i++;
    for (; name_file[i] == ' ' || name_file[i] == '\t'; i++);
    if (name_file[i] != '\0')
        return false;
    return true;
}

bool error_header(char *name_file, char *type, int size)
{
    int i = 0;

    for (i = 0; name_file[i] == ' ' || name_file[i] == '\t'; i++);
    if (my_strncmp((name_file + i), type, my_strlen(type)) != 0)
        return false;
    i = i + my_strlen(type);
    if (name_file[i] != ' ' && name_file[i] == '\t')
        return false;
    for (; name_file[i] == ' ' || name_file[i] == '\t'; i++);
    if (name_file[i] != '\"')
        return false;
    i++;
    if (!error_header_to(name_file, i, size))
        return false;
    return true;
}
