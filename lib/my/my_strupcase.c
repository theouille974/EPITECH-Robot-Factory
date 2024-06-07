/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Transform the string into an UPPERCASE string
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}
