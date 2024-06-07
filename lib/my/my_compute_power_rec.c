/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** return the power of a number - recursive way
*/
#include "my.h"
int my_compute_power_rec(int n, int power)
{
    if (n < 0) {
        return 0;
    }
    if (power == 0) {
        return 1;
    }
    if (power == 1) {
        return n;
    } else {
        return n * my_compute_power_rec(n, power - 1);
    }
}
