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

int env_exec (char **argv, char **env)
{
    int error = 84;
    if (!(my_strcmp("env", argv[0])) && argv[1] == NULL) {
        env_print(env);
        error = 0;
    }
    if (!(my_strcmp("set", argv[0])) && argv[1] && argv[2] && !argv[3]) {
        env = searsh_and_add_in_env(env, argv[1], argv[2]);
        error = 0;
    }
    if (!(my_strcmp("unset", argv[0])) && argv[1] && !argv[2]) {
        error = searsh_and_del_in_env(env, argv[1]);
    }
    if (!(my_strcmp("cd", argv[0])))
        error = my_cd(argv, env);
    return error;
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
    } else if (!(my_strcmp("env", argv[0])) || !(my_strcmp("set", argv[0]))
                || !(my_strcmp("unset", argv[0])) || !(my_strcmp("cd", argv[0])))
        exit_codes[1] = env_exec(argv, env);
    else
        exit_codes[1] = minishell_execute(argv, ".");
    return exit_codes;
}