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
#include "include/my.h"
#include <stdlib.h>

int minishell_text(int ac, char **av);
int minishell_command(char *str, int read_var);
void reset_buffer(char *buffer, int size);

int minishell_stand_imput(int fd)
{
    int read_var = 1;
    int exit = 0;
    char *buffer = malloc(sizeof(char) * 4097);

    buffer[4096] = '\0';
    while (read_var > 0 && exit == 0) {
        my_putstr("#>");
        reset_buffer(buffer, read_var);
        read_var = read(fd, buffer, 4096);
        if(read_var > 0) {
            exit = minishell_command(buffer, read_var);
        }
    }
    free(buffer);
    return 0;
}

int minishell(int ac, char **av)
{
    if (ac == 1)
        return minishell_stand_imput(0);
    else if (ac > 1)
        return minishell_text(ac, av);
    else
        return 84;
    return 0;
}
