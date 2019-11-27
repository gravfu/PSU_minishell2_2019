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
int minishell_command(char **str, int read_var);
void reset_buffer(char *buffer, int size);

int boucle = 0;

char *new_cmd(char *str)
{
    /*if (str[0] == '\n' || str[0] == '\0')
        return NULL; */
    int i;
    char *cmd = malloc(sizeof(char) * 400);

    for (i = 0; str[i] != '\n' && str[i] != ' ' && str[i] != '\0'; i++) {
        cmd[i] = str[i];
        //printf("Boucle %d, str[i] = %c\n", boucle, str[i]);
    }
    cmd[i] = '\0';
    boucle++;
    return cmd;
}

char **read_commands(char *buffer, int readsize)
{
    int i = 1;
    int point = 0;
    char **argv = malloc(sizeof(char *) * 4096);

    for(i = 0; i < readsize; i++) {
        if (buffer[i] != '\n' && buffer[i] != ' ') {
            argv[point] = new_cmd(&buffer[i]);
            point++;
            for(; buffer[i] != '\n' && buffer[i] != ' ' && i < readsize; i++);
        }
    }
    /*
    while (buffer[i-1] != '\n') {
        argv[point] = new_cmd(&buffer[i]);
        point++;
        for (; buffer[i] != '\n' && buffer[i] != ' '; i++);
        i++;
    }*/
    argv[point] = NULL;
    //my_show_word_array(argv);
    return argv;
}

int minishell_stand_imput(int fd)
{
    int read_var = 1;
    int exit = 0;
    char *buffer = malloc(sizeof(char) * 4097);
    char **argv;

    buffer[4096] = '\0';
    while (read_var > 0 && exit == 0) {
        my_putstr("#> ");
        reset_buffer(buffer, read_var);
        read_var = read(fd, buffer, 4096);
        if(read_var > 0) {
            argv = read_commands(buffer, read_var);
            exit = minishell_command(argv, read_var);
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
