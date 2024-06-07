/*
** EPITECH PROJECT, 2024
** find label
** File description:
** find label
*/

#include "asm.h"

bool is_char_valid(char c)
{
    char *label_char = LABEL_CHARS;

    for (int i = 0; label_char[i]; i++)
        if (c == label_char[i])
            return true;
    my_printf("Syntaxe error : Wrong charactere in labels.\n");
    return false;
}

bool is_in(char **label_tab, char **tmp, int i)
{
    for (int x = i + 1; tmp[x]; x++) {
        if (my_strcmp(label_tab[i], tmp[x]) == 0) {
            my_printf("Double labels\n");
            return false;
        }
    }
    return true;
}

bool check_label_to(char **label_tab, int y)
{
    for (int x = 0; label_tab[y][x]; x++) {
        if (!is_char_valid(label_tab[y][x]))
            return false;
    }
    return true;
}

bool check_label(char **label_tab)
{
    char **tmp = label_tab;

    for (int i = 0; label_tab[i]; i++) {
        if (!is_in(label_tab, tmp, i))
            return false;
    }
    for (int y = 0; label_tab[y]; y++)
        if (!check_label_to(label_tab, y))
            return false;
    return true;
}

char **find_label(char **tab)
{
    char **label_tab = malloc(sizeof(char *));
    char **tmp = NULL;
    int cmpt = 0;

    label_tab[0] = NULL;
    for (int y = 0; tab[y]; y++) {
        tmp = my_str_to_word_array(tab[y], " \t");
        if (tmp[0][my_strlen(tmp[0]) - 1] == LABEL_CHAR) {
            label_tab = realloc(label_tab, sizeof(char *) * (cmpt + 2));
            label_tab[cmpt] = my_strndup(tmp[0], my_strlen(tmp[0]) - 1);
            label_tab[cmpt + 1] = NULL;
            cmpt++;
        }
        free_tab(tmp);
    }
    if (!check_label(label_tab))
        return NULL;
    return label_tab;
}
