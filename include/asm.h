/*
** EPITECH PROJECT, 2023
** asm.h
** File description:
** never gonna give you up
*/
#ifndef _ASM_H_
    #define _ASM_H_
    #include "../lib/my/include/my.h"
    #include "../include/op.h"
    #include "sys/types.h"
    #include <errno.h>

/// 4 bytes for the magic nb ///
/// 128 bytes for the name ///
/// 4 bytes for the padding ///
/// 4 bytes for the prog size ///
/// 2048 bytes for the comment ///
/// 4 bytes for the padding ///
    #define HEADER (4 + 128 + 4 + 4 + 2048 + 4)

typedef struct label_s {
    char *name_label;
    int address;
    int nb_call_lab;
    int *where_command;
    int *where_write;
    int *size;
}label_t;

typedef struct asm_s {
    char **content_file;
    char *name_file;
    int size_cont;
    int pos_in_file;
    int arg_pos;
    label_t **label;
    int size_tab_label;
    uint8_t *buffer;
    int buffer_size;
} asm_t;

typedef struct fun_valid_op_s {
    char *instruction;
    bool (*fun)(char **tab, asm_t *asm_st);
} fun_valid_op_t;

typedef struct new_fun_valid_op_s {
    uint8_t number;
    char *op_name;
    bool coding_byte;
    bool is_index;
    u_int8_t arg_number;
    bool (*fun[MAX_ARGS_NUMBER])(char *tab, asm_t *asm_st, bool index, int p);
} new_fun_valid_op_t;

int main(int ac, char **av);

///errors///
bool main_errors(char **av);
bool file_errors(char **av);
bool error_header_file(asm_t *asm_st);
bool error_header(char *name_file, char *type, int size);
bool error_header_to(char *name_file, int i, int size);
bool asm_content_error(asm_t *asm_st);

///find label///
char **find_label(char **tab);
bool check_label(char **label_tab);
bool check_label_to(char **label_tab, int y);
bool is_in(char **label_tab, char **tmp, int i);
bool is_char_valid(char c);
void display_label(label_t **label);
int tab_label_len(label_t **label);
void load_label(char **label, asm_t *asm_st);
void replace_label(asm_t *asm_st);
void replace_label_2_bytes(asm_t *asm_st, label_t **lb, int i, int y);
void replace_label_4_bytes(asm_t *asm_st, label_t **lb, int i, int y);
uint8_t adr(int address, int where_command, int bit, uint8_t mask);

///free///
int my_free_struct(asm_t *asm_st, int status);
void free_tab(char **tab);
void display_tab(char **tab);
void free_label(label_t **label);
void free_int_et2(label_t *label);

///help///
int help(void);

///open file///
char **open_file(char *path);
void valid_tab(char **content);
char **copying_remove_empty_line(char **tab);
int recup_name_file(asm_t *asm_st, char *file_name);

///operation asm///
bool asm_content_error(asm_t *asm_st);
bool is_exist_correct_op(char **tab, asm_t *asm_st);
bool is_valid_op(int index, char **tab);

///robot factory///
label_t **init_struct_label(void);
asm_t *init_struct(void);
int robot_factory(char **av);

///tab_len///
int tab_len(char **tab);

///create_file///
int parse_file(asm_t *asm_st);
void add_name(asm_t *asm_st);
void write_in_buffer(asm_t *asm_st, uint8_t *file, int size);
void add_magic_nb(asm_t *asm_st);
void add_comment(asm_t *asm_st);

///parsing///
bool is_label(asm_t *asm_st, char *str);
int is_register(char *line);
bool is_direct(asm_t *asm_st, char *line);
char *is_indirect(asm_t *asm_st, char *line);
int parse_instructions(asm_t *asm_st);
int parse_instruction(asm_t *asm_st, char **instruction);
void update_adress(asm_t *asm_st, char *label);
void maj_label(asm_t *asm_st, label_t **l, char *tab, int type);

///add in buffer///
bool add_rg(char *tab, asm_t *asm_st, bool index, int p);
bool add_rg_or_id(char *tab, asm_t *asm_st, bool index, int p);
bool add_rg_or_dr(char *tab, asm_t *asm_st, bool index, int p);
bool add_rg_or_id_or_dr(char *tab, asm_t *asm_st, bool index, int p);
bool add_id(char *tab, asm_t *asm_st, bool index, int p);
bool add_id_or_dr(char *tab, asm_t *asm_st, bool index, int p);
bool add_dr(char *tab, asm_t *asm_st, bool index, int p);

static const new_fun_valid_op_t our_tab[] = {
    {0, NULL, 0, 0, 0, {NULL, NULL, NULL}},
    {1, "live", 0, 0, 1, {add_dr, NULL, NULL}},
    {2, "ld", 1, 0, 2, {add_id_or_dr, add_rg}},
    {3, "st", 1, 1, 2, {add_rg, add_rg_or_id, NULL}},
    {4, "add", 1, 0, 3, {add_rg, add_rg, add_rg}},
    {5, "sub", 1, 0, 3, {add_rg, add_rg, add_rg}},
    {6, "and", 1, 0, 3, {add_rg_or_id_or_dr, add_rg_or_id_or_dr, add_rg}},
    {7, "or", 1, 0, 3, {add_rg_or_id_or_dr, add_rg_or_id_or_dr, add_rg}},
    {8, "xor", 1, 0, 3, {add_rg_or_id_or_dr, add_rg_or_id_or_dr, add_rg}},
    {9, "zjmp", 0, 1, 1, {add_dr, NULL, NULL}},
    {10, "ldi", 1, 1, 3, {add_rg_or_id_or_dr, add_rg_or_dr, add_rg}},
    {11, "sti", 1, 1, 3, {add_rg, add_rg_or_id_or_dr, add_rg_or_dr}},
    {12, "fork", 0, 1, 1, {add_dr, NULL, NULL}},
    {13, "lld", 1, 0, 2, {add_id_or_dr, add_rg, NULL}},
    {14, "lldi", 1, 1, 3, {add_rg_or_id_or_dr, add_rg_or_dr, add_rg}},
    {15, "lfork", 0, 1, 1, {add_dr, NULL, NULL}},
    {16, "aff", 1, 0, 1, {add_rg, NULL, NULL}},
    {17, NULL, 0, 0, 0, {NULL, NULL, NULL}}
};

static const int mv_tab[] = {
    6,
    4,
    2,
};

#endif /*_ASM_H_*/
