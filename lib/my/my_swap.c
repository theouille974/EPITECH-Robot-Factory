/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Swap two integers by using its pointers
*/

void my_swap(int *a, int *b)
{
    int swap = *a;

    *a = *b;
    *b = swap;
}
