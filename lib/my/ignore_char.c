/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** ignore_char
*/

#include "my.h"
#include <errno.h>

char *ignore_char(char *str, char c)
{
    char *new = NULL;
    int nb = 0;
    int index = 0;

    if (!str){
        my_put_error_plus("Error", "ignore_char", EINVAL, NULL);
        return NULL;
    }
    nb = count_char(str, c);
    new = malloc(sizeof(char) * (my_strlen(str) - nb + 2));
    for (int i = 0; str[i] != '\0'; i ++){
        if (str[i] == c)
            continue;
        new[index] = str[i];
        index ++;
    }
    new[my_strlen(str) - nb + 1] = '\0';
    free(str);
    return new;
}

int count_char(char *str, char c)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i ++){
        if (str[i] == c)
            cpt ++;
    }
    return cpt;
}
