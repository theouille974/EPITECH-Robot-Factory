/*
** EPITECH PROJECT, 2024
** B-CPE-200-RUN-2-1-robotfactory-thea.gory-lauret
** File description:
** operation_asm
*/

#include "asm.h"

bool error_header_file(asm_t *asm_st)
{
    if (!error_header(asm_st->content_file[0], NAME_STR, NAME_LENGTH))
        return false;
    if (!error_header(asm_st->content_file[1], COMMENT_STR, COMMENT_LENGTH))
        return false;
    return true;
}

bool asm_content_error(asm_t *asm_st)
{
    char **tmp = NULL;
    int result = 0;
    char *str = NULL;

    if (asm_st->content_file == NULL)
        return true;
    for (int i = 0; asm_st->content_file[i] != NULL; i ++){
        str = my_strdup(asm_st->content_file[i]);
        tmp = my_str_to_word_array(str, " ");
        result += (is_exist_correct_op(tmp, asm_st)) ? 0 : 1;
        free_tab(tmp);
        free(str);
    }
    if (result != 0){
        my_put_error("content not valid\n");
        return true;
    }
    return false;
}

bool is_exist_correct_op(char **tab, asm_t *asm_st)
{
    char *op = NULL;

    if (!tab)
        return true;
    op = tab[0];
    if (error_header_file(asm_st))
        return true;
    for (int i = 0; op_tab[i].mnemonique != NULL; i ++){
        if (my_strcmp(op_tab[i].mnemonique, op) == 0)
            return is_valid_op(i, tab);
    }
    return false;
}

bool is_valid_op(int index, char **tab)
{
    int nb_args = op_tab[index].nbr_args;

    if (nb_args != tab_len(tab) - 1)
        return false;
    return true;
}
