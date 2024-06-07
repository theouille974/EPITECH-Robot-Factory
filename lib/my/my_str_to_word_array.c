/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Return a string to a array of words
*/

#include "my.h"
#include <stdlib.h>

bool is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
        if (c == delim[i])
            return true;
    return false;
}

int my_strlen_delim(char const *str, char const *delim)
{
    int i = 0;

    for (; !is_delim(str[i], delim) && str[i] != '\0'; i++);
    return i;
}

int count_words(char const *str, char const *delim)
{
    int cmpt = 0;

    for (int i = 0; str[i] != '\0';) {
        for (; is_delim(str[i], delim) && str[i] != '\0'; i++);
        if (str[i] != '\0')
            cmpt++;
        for (; !is_delim(str[i], delim) && str[i] != '\0'; i++);
    }
    return cmpt;
}

char **my_str_to_word_array(char const *str, char const *d)
{
    int cmpt = 0;
    char **tab = NULL;
    int y = 0;
    int len = my_strlen(str);

    if (!str || !d)
        return NULL;
    cmpt = count_words(str, d);
    tab = malloc(sizeof(char *) * (cmpt + 1));
    if (!tab)
        return NULL;
    for (int i = 0; i < len && y < cmpt; i += my_strlen_delim(str + i, d)+ 1) {
        for (; is_delim(str[i], d) && str[i] != '\0'; i++);
        tab[y] = my_strndup(str + i, my_strlen_delim(str + i, d));
        if (!tab[y])
            return NULL;
        y++;
    }
    tab[cmpt] = NULL;
    return tab;
}
