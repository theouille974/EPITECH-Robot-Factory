/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** The most basic function to print a character
*/
#include <unistd.h>
int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
