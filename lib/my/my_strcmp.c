/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** Compare two strings
*/
#include "my.h"
int my_strcmp(char const *s1, char const *s2)
{
    int cs1 = my_strlen(s1);
    int cs2 = my_strlen(s2);

    if (cs1 < cs2) {
        return - s2[cs1];
    }
    if (cs1 > cs2) {
        return s1[cs2];
    }
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] < s2[i] || s1[i] > s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
