/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** errors
*/

#include "my.h"

int my_put_error_plus(char *origin, char *input, int nb, char *custom)
{
    char *error = NULL;

    write(2, origin, my_strlen(origin));
    write(2, ": ", 3);
    write(2, input, my_strlen(input));
    if (nb == -1){
        write(2, ": ", 3);
        write(2, custom, my_strlen(custom));
    }
    if (nb > 0){
        error = NULL;
        write(2, ": ", 3);
        write(2, error, my_strlen(error));
    }
    write(2, "\n", 2);
    return 84;
}

int my_put_error(char *message)
{
    int size = my_strlen(message);

    write(2, "Error :", 8);
    write(2, message, size);
    write(2, "\n", 2);
    return 84;
}
