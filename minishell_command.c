/*
** EPITECH PROJECT, 2019
** minishell_command.c
** File description:
** cat texts
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "include/my.h"
#include "include/env.h"

int my_error_handle(char *av, int error);

char *my_cat(char *str1, char *str2);

int char_in_array(char c, char *str);

int minishell_execute(char **argv, char *path)
{
    struct stat st;
    int exit_code = 0;

    char *newenviron[] = { NULL };
    char *final_path;

    if (argv[0][0] == '/')
        final_path = argv[0];
    else
        final_path = my_cat(my_cat(path, "/"), argv[0]);

    if (stat(argv[0], &st) == 0 && char_in_array('/', argv[0])) {
        if ((st.st_mode & S_IXUSR) && (st.st_mode & __S_IFREG)) {
            pid_t childpid = fork();
            if (childpid == 0)
                exit_code = execve(final_path, argv, newenviron);
            else {
                wait(&exit_code);
                exit_code = WEXITSTATUS(exit_code);
            }
        }
    }
    else {
        my_error_handle(argv[0], 127);
        exit_code = 127;
    }
    return exit_code;
}

int *minishell_command(char **argv, int read_var, char **env, int prev)
{
    int *exit_codes = malloc(sizeof(int)*2);
    exit_codes[0] = 0;

    if(my_strcmp("exit", argv[0]) == 0) {
        my_putstr("exit\n");
        exit_codes[0] = 1;
        if (argv[1] != NULL)
            exit_codes[1] = my_getnbr(argv[1]);
        else
            exit_codes[1] = prev;
    }
    else
        exit_codes[1] = minishell_execute(argv, ".");
    return exit_codes;
}