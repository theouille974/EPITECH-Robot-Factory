/*
** EPITECH PROJECT, 2023
** help
** File description:
** help
*/

#include "asm.h"

int help(void)
{
    FILE *file = fopen("./help.txt", "r");
    char *buffer = NULL;
    size_t n = 0;

    if (!file) {
        write(2, "Cannot open the file help", 25);
        return 84;
    }
    while (getline(&buffer, &n, file) > 0) {
        write(1, buffer, n);
        memset(buffer, 0, n);
    }
    fclose(file);
    return 0;
}
