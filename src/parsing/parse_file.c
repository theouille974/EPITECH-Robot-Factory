/*
** EPITECH PROJECT, 2024
** parse_file
** File description:
** parse_file
*/

#include "asm.h"

static void replace_prog_size(asm_t *asm_st)
{
    int full_header_size = HEADER;
    int prog_size = asm_st->buffer_size - full_header_size;

    asm_st->buffer[4 + 128 + 4 + 0] = (prog_size >> 24) & 0xff;
    asm_st->buffer[4 + 128 + 4 + 1] = (prog_size >> 16) & 0xff;
    asm_st->buffer[4 + 128 + 4 + 2] = (prog_size >> 8) & 0xff;
    asm_st->buffer[4 + 128 + 4 + 3] = (prog_size) & 0xff;
}

void add_comment(asm_t *asm_st)
{
    char *l = asm_st->content_file[1];

    l += my_strlen_to(l, '\"') + 1;
    l = my_strndup(l, my_strlen_to(l, '\"'));
    write_in_buffer(asm_st, (uint8_t *)l, my_strlen(l));
    for (; asm_st->buffer_size < 4 + 128 + 2048 + 8 + 4;)
        write_in_buffer(asm_st, (uint8_t[]){0x00}, 1);
    free(l);
}

void add_name(asm_t *asm_st)
{
    char *l = asm_st->content_file[0];

    l += my_strlen_to(l, '\"') + 1;
    l = my_strndup(l, my_strlen_to(l, '\"'));
    write_in_buffer(asm_st, (uint8_t *)l, my_strlen(l));
    for (; asm_st->buffer_size < 4 + 128 + 8;)
        write_in_buffer(asm_st, (uint8_t[]){0x00}, 1);
    free(l);
}

void write_in_buffer(asm_t *asm_st, uint8_t *file, int size)
{
    asm_st->buffer = realloc(asm_st->buffer, asm_st->buffer_size + size);
    for (int i = 0; i < size; i++)
        asm_st->buffer[asm_st->buffer_size + i] = file[i];
    asm_st->buffer_size += size;
}

void add_magic_nb(asm_t *asm_st)
{
    write_in_buffer(asm_st, (uint8_t[]){0x00, 0xea, 0x83, 0xf3}, 4);
}

int parse_file(asm_t *asm_st)
{
    int fd = 0;

    add_magic_nb(asm_st);
    add_name(asm_st);
    add_comment(asm_st);
    if (parse_instructions(asm_st) == 84)
        return my_free_struct(asm_st, 84);
    replace_label(asm_st);
    replace_prog_size(asm_st);
    fd = open(asm_st->name_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return my_free_struct(asm_st, 84);
    write(fd, asm_st->buffer, asm_st->buffer_size);
    close(fd);
    return my_free_struct(asm_st, 0);
}
