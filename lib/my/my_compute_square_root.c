/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Return the square root of a number
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int result;
    float speculation = nb;

    for (int i = 0; i < 10; i++) {
        speculation = (speculation + nb / speculation) / 2;
    }
    result = speculation;
    if (result == speculation) {
        return result;
    }
    return 0;
}
