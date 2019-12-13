/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "include/my.h"
#include "include/env.h"
#include "include/error.h"

int minishell_execute(char **argv, char *path, char **env);

int env_exec (char **argv, char **env)
{
    int error = 84;
    if (!(my_strcmp("env", argv[0])) && argv[1] == NULL) {
        env_print(env);
        error = 0;
    }
    if (!(my_strcmp("setenv", argv[0])) && argv[1] && argv[2] && !argv[3]) {
        env = searsh_and_add_in_env(env, argv[1], argv[2]);
        error = 0;
    }
    if (!(my_strcmp("unsetenv", argv[0])) && argv[1] && !argv[2]) {
        error = searsh_and_del_in_env(env, argv[1]);
    }
    if (!(my_strcmp("cd", argv[0])))
        error = my_cd(argv, env);
    return error;
}

void exit_function(char **argv, int *exit_codes, int prev)
{
    my_putstr("exit\n");
    exit_codes[0] = 1;
    if (argv[1] != NULL)
        exit_codes[1] = my_getnbr(argv[1]);
    else
        exit_codes[1] = prev;
}

int *minishell_command(char **argv, int read_var, char **env, int prev)
{
    int *exit_codes = malloc(sizeof(int)*2);
    exit_codes[0] = 0;
    char path[256];

    if (getcwd(path, sizeof(path)) == NULL) {
        perror("chdir() error()");
        exit_codes[0] = 1;
        exit_codes[1] = errno;
        return exit_codes;
    }
    if (my_strcmp("exit", argv[0]) == 0) {
        exit_function(argv, exit_codes, prev);
    } else if (!(my_strcmp("env", argv[0])) || !(my_strcmp("setenv", argv[0]))
                || !(my_strcmp("unsetenv", argv[0]))
                || !(my_strcmp("cd", argv[0])))
        exit_codes[1] = env_exec(argv, env);
    else
        exit_codes[1] = minishell_execute(argv, path, env);
    return exit_codes;
}