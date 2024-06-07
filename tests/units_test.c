/*
** EPITECH PROJECT, 2024
** unit test
** File description:
** unit test
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

//test = test_function(...); -> call function
//cr_assert_str_eq(test, expected); -> cmp str expected and str received
//cr_assert_eq_int(test, expected); -> cmp int expected and int received
//cr_assert_eq_null(test, expected); -> test if null = malloc(sizeof(...) * -1)

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (test, test_str, .init=redirect_all_std)
{
    cr_assert_str_eq(test(), "hello world!");
}

