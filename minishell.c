/*
** EPITECH PROJECT, 2019
** minishell.c
** File description:
** Minishell
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/env.h"
#include <stdio.h>

int minishell_text(int ac, char **av);

int *minishell_command(char **str, int read_var, char **env, int prev);

void reset_buffer(char *buffer, int size);

char *new_cmd(char *str)
{
    int i;
    char *cmd = malloc(sizeof(char) * 400);

    for (i = 0; str[i] != '\n' && str[i] != ' ' && str[i] != '\0'; i++) {
        cmd[i] = str[i];
    }
    cmd[i] = '\0';
    return cmd;
}

char **read_commands(char *buffer, int readsize)
{
    int i = 1;
    int point = 0;
    char **argv = malloc(sizeof(char *) * 4096);

    for (i = 0; i < readsize; i++) {
        if (buffer[i] != '\n' && buffer[i] != ' ') {
            argv[point] = new_cmd(&buffer[i]);
            point++;
            for (; buffer[i] != '\n' && buffer[i] != ' ' && i < readsize; i++);
        }
    }
    argv[point] = NULL;
    return argv;
}

int minishell_stand_imput(int fd, char **env)
{
    int read_var = 1;
    int *exit_codes = malloc(sizeof(int)*2);
    char *buffer = malloc(sizeof(char) * 4097);
    char **argv;
    size_t size = 4096;

    buffer[4096] = '\0';
    exit_codes[0] = 0;
    exit_codes[1] = 0;
    while (read_var > 0 && exit_codes[0] == 0) {
        my_putstr("=(^-^)= ");
        reset_buffer(buffer, read_var);
        read_var = getline(&buffer, &size, stdin);
        //read_var = read(fd, buffer, 4096);
        //write(1, buffer, read_var);
        if (read_var > 1) {
            argv = read_commands(buffer, read_var);
            exit_codes = minishell_command(argv, read_var, env, exit_codes[1]);
        }
    }
    free(buffer);
    return exit_codes[1];
}

int minishell(int ac, char **av, char **env_path)
{
    char **env = env_struct_init(env_path);
    if (ac == 1)
        return minishell_stand_imput(0, env);
    else
        return 84;
    return 0;
}