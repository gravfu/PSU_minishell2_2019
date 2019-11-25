/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include <unistd.h>
#include "include/my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int minishell_cat(char *str, int read_var)
{
    if (my_strncmp("cat\n", str, 4) == 0 || my_strncmp("cat ", str, 4) == 0)
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

int minishell_execute(char *possible_path)
{
    struct stat st;
    int pass;

    pass = char_in_array('/', possible_path);
    if (stat(possible_path, &st) == 0) {
        if ((st.st_mode & S_IXUSR) && (st.st_mode & __S_IFREG) && pass)
            my_putstr("SUCESS\n");
    }
    return 0;
}

int minishell_exit(char *str)
{
    if (my_strcmp("exit", str) == 0)
        return 1;
    return 0;
}

int minishell_command(char *str, int read_var)
{
    str[read_var-1] = '\0';
    if(minishell_exit(str) == 1)
        return 1;
    if(minishell_execute(str) == 1)
        return 1;
    if(minishell_cat(str, read_var) == 1)
        return 84;
    return 0;
}