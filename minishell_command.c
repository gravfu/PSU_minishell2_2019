/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include <unistd.h>
#include "include/my.h"

int minishell_cat(char *str, int read_var)
{
    if (my_strncmp("cat\n", str, 4) == 0 || my_strncmp("cat ", str, 4) == 0)
        write(1, str, read_var);
    return 0;
}

int minishell_exit(char *str)
{
    if (my_strcmp("exit\n", str) == 0)
        return 1;
    return 0;
}

int minishell_command(char *str, int read_var)
{
    if(minishell_exit(str) == 1)
        return 1;
    if(minishell_cat(str, read_var) == 1)
        return 84;
        
    return 0;
}