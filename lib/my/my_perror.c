/*
** EPITECH PROJECT, 2023
** perror
** File description:
** perror
*/
#include "my.h"
#include <unistd.h>

int my_perror(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
