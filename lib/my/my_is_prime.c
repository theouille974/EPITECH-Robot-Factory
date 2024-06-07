/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Check if the number in parameter is a prime number or not
*/
int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i < nb / 2; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
