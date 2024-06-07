/*
** EPITECH PROJECT, 2024
** recup name
** File description:
** recup name
*/

#include "asm.h"

int recup_name_file(asm_t *asm_st, char *file_name)
{
    char **path = my_str_to_word_array(file_name, "/");
    int len = 0;
    char *str = NULL;

    if (path == NULL)
        return 84;
    len = tab_len(path);
    str = my_strndup(path[len - 1], my_strlen(path[len - 1]) - 2);
    asm_st->name_file = malloc(sizeof(char) * (my_strlen(str) + 5));
    my_strcpy(asm_st->name_file, str);
    my_strcpy(asm_st->name_file + my_strlen(str), ".cor");
    asm_st->name_file[my_strlen(str) + 4] = '\0';
    free(str);
    free_tab(path);
    return 0;
}
