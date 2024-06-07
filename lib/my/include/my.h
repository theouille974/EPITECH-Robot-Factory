/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** never gonna give you up
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <ncurses.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/wait.h>
    #define END_OF_STR '\0'
    #define MINORBITS    20
    #define MINORMASK    ((1U << MINORBITS) - 1)
    #define MAJOR(dev)    ((unsigned int) ((dev) >> MINORBITS))
    #define MINOR(dev)    ((unsigned int) ((dev) & MINORMASK))

typedef struct handler {
    char trigger;
    int (*func)();
} handler_t;

typedef struct flags_s {
    char a;
    char l;
    char d;
} flags_t;

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str, char const *delim);
int count_words(char const *str, char const *delim);
int my_strlen_delim(char const *str, char const *delim);
bool is_delim(char c, char const *delim);
char *my_strndup(char const *src, int n);
int base_operator(char const *base);
int length(int n, int len);
int is_alpha_num(char c);
int words_number(char const *str);
int is_num(char c);
void check_and_move(char **world, int i, int *count);
int count_island(char **world);
int specifiers(char c);
int display_fmt(const char *fmt, int n, va_list list, int count);
int post_display(char c, char const *fmt, int i);
int my_printf(const char *format, ...);
int display_float(double num, int n);
int my_putnbr_hexa(long n);
int my_putnbr_oct(int n);
int display_unsigned(unsigned int n);
int my_put_nbr_unsigned(unsigned int nb);
int significative(double num);
int display_exponent(double n, int e, char exp);
int display_double_g(double num);
int my_put_adress(void *adress);
int my_putnbr_b(long n, char const *base, char letter);
int count_c(int *count, int n);
int flags(char const *fmt, int *i, va_list list, int count);
int left_justify_count(char const *fmt, int start, int *cmpt);
int left_justify_spaces(int n);
int left_justify_zeros(int n);
int spaces(char const *fmt, int n);
int display_hash(char const *fmt, int count);
int width(char const *fmt, int start);
int find_slash(char *av, int i, int checkpoint);
int search_path(char **av);
char *type_file(struct stat *st);
int display_stat_file(char *ap, struct dirent *rf, char *fn);
int info_file(char *filepath, char *file_name, char *all_path);
int ls_flags(char **c);
int my_ls(char *dir_path, flags_t flags);
int only_dash(char c, char **av);
int inverse_ls(int ac, char **av);
void stats_l(struct stat *st, char *all_path);
void no_dash(int ac, char **av, int flags, int i);
void dash(int ac, char *av, flags_t *flags);
int no_dir_p(struct dirent *rd, char *dir_path);
int stats_perm(char *all_path);
void time_l(struct stat *st);
void flags_ls(struct dirent *rd, char *cat, char *dir_path, flags_t flags);
void path_null(flags_t flags, int path);
char *slash(char *dir_path);
int d_flags(char *dir_name, flags_t flags);
void check_flags(flags_t flags, struct dirent *rd, char *dir_path);
void is_file(char *all_path, flags_t flags);
void nb_flags(flags_t *flags, int ac, char **av);
int ls_flags(char **c);
int getfile_size(char *path);
char *read_file_content(char *file_content, char *path);
char *getfile(char *path);
char *getfile_lines(char *path);
int my_strlen_to(char const *str, char to);
int my_new_strcmp(char const *str1, char const *str2);
int my_put_error_plus(char *origin, char *input, int nb, char *custom);
int tab_len(char **tab);
void display_tab(char **tab);
int my_put_error(char *mmessage);
char *ignore_char(char *str, char c);
int count_char(char *str, char c);
bool is_str_number(char *const str);

#endif
