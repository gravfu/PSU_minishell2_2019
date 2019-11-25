/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include "include/my.h"

int minishell_exit(char *str)
{
    if (my_strcmp("exit\n", str) == 0)
        return 1;
    return 0;
}

int minishell_command(char *str)
{
    if(minishell_exit(str) == 1)
        return 1;
    return 0;
}