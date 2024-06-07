/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Fetch the first prime number equals or greater than
** the number set in parameter
*/
#include "my.h"
int my_find_prime_sup(int nb)
{
    int i = 2;

    if (nb < 2) {
        return 0;
    }
    while (1) {
        if (i == nb / 2) {
            return nb;
        }
        if (nb % i != 0) {
            i++;
        } else {
            i = 2;
            nb++;
        }
    }
}
