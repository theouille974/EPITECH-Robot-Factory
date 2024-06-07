/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** errors
*/

#include "asm.h"

bool main_errors(char **av)
{
    if (my_strcmp(av[1] + (my_strlen(av[1]) - 2), ".s") != 0) {
        my_put_error_plus(av[0], "Wrong type of file.", 0, NULL);
        write(2, "Retry with -h\n", 14);
        return true;
    }
    return false;
}

bool file_errors(char **av)
{
    FILE *file = NULL;
    struct stat sb;
    int stats = stat(av[1], &sb);

    if (sb.st_size == 0)
        return true;
    if (stats != 0)
        return true;
    if (!S_ISREG(sb.st_mode)){
        my_put_error_plus(av[1], "Not a valid regular file.", 0, NULL);
        return true;
    }
    file = fopen(av[1], "r");
    if (!file) {
        my_put_error_plus(av[1], "Opening the file", EACCES, NULL);
        return true;
    }
    fclose(file);
    return false;
}
