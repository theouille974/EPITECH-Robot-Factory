/*
** EPITECH PROJECT, 2024
** open file
** File description:
** open file
*/

#include "asm.h"

bool only_space_or_tab(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] != ' ' && line[i] != '\t')
            return true;
    return false;
}

char **copying_remove_empty_line(char **tab)
{
    char **new_tab = NULL;
    int len_tab = tab_len(tab);
    int cmpt = 0;

    new_tab = malloc(sizeof(char *) * (len_tab + 1));
    for (int i = 0; tab[i]; i++) {
        if (my_strlen(tab[i]) == 0)
            continue;
        if (!only_space_or_tab(tab[i]))
            continue;
        new_tab[cmpt] = my_strdup(tab[i]);
        cmpt++;
    }
    new_tab[cmpt] = NULL;
    return new_tab;
}

void valid_tab(char **content)
{
    for (int y = 0; content[y]; y++)
        for (int x = 0; content[y][x]; x++) {
            content[y][x] = (content[y][x] == '#') ? '\0' : content[y][x];
        }
}

char **open_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    char *content = NULL;
    char **content_file = NULL;
    char **valid_content = NULL;

    stat(path, &st);
    if (st.st_size == 0 || fd == -1)
        return NULL;
    content = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, content, st.st_size);
    content[st.st_size] = '\0';
    content_file = my_str_to_word_array(content, "\n");
    close(fd);
    free(content);
    valid_tab(content_file);
    valid_content = copying_remove_empty_line(content_file);
    free_tab(content_file);
    return valid_content;
}
