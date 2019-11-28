/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include <stdlib.h>
#include "include/my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int minishell_cat(char **str, int read_var)
{
    if (my_strncmp("cat", str[0], 4) == 0)
        write(1, str, read_var);
    return 0;
}

int char_in_array(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int minishell_execute(char **possible_path)
{
    struct stat st;
    int pass;
    char *newargv[] = { NULL };
    char *newenviron[] = { NULL };

    pass = char_in_array('/', possible_path[0]);
    if (stat(possible_path[0], &st) == 0) {
        if ((st.st_mode & S_IXUSR) && (st.st_mode & __S_IFREG) && pass)
            execve(possible_path[0], newargv, newenviron);
    }
    return 0;
}

int minishell_exit(char **str)
{
    if (my_strcmp("exit", str[0]) == 0) {
        my_putstr("exit\n");
        if (str[1] != NULL)
            exit(my_getnbr(str[1]));
        return 1;
    }
    return 0;
}

int minishell_command(char **argv, int read_var, char *path)
{
    if(minishell_exit(argv) == 1)
        return 1;
    if(minishell_execute(argv) == 1)
        return 1;
    if(minishell_cat(argv, read_var) == 1)
        return 84;
    return 0;
}