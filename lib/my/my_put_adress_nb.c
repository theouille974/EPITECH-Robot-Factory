/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** print the number either if its negative or not
*/
#include "my.h"

int my_put_adress(void *adress)
{
    int count = 0;

    count += my_putstr("0x");
    count += my_putnbr_b((long)adress, "HEX", 'x');
    return count;
}
