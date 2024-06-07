/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/

#include "asm.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        my_put_error_plus(av[0], "Invalid number on arguments.", 0, NULL);
        write(2, "Retry with -h\n", 14);
        return true;
    }
    if (my_strcmp(av[1], "-h") == 0)
        return help();
    if (main_errors(av))
        return 84;
    return robot_factory(av);
}
