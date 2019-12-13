/*
** EPITECH PROJECT, 2019
** cd.c
** File description:
** cat texts
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "include/my.h"
#include "include/env.h"
#include "include/error.h"

int my_cd(char **argv, char **env)
{
    char cwd[1024];
    char **home_dir = searsh_in_env(env, "HOME");
    char **oldpwd = searsh_in_env(env, "OLDPWD");
    char *path = NULL;
    char path_old[256];
    errno = 0;
    if (argv[1] == NULL)
        path = home_dir[0];
    else
        path = argv[1];
    if (argv[1] && !my_strcmp(argv[1], "-") && oldpwd != NULL)
        path = oldpwd[0];
    if (argv[1] && argv[2]) {
        my_error_handle("cd", argv[1], -1);
        return 84;
    }
    getcwd(path_old, sizeof(path_old));
    if (chdir(path) != 0) {
        my_error_handle("cd", path, errno);
        return 84;
    } else {
        searsh_and_del_in_env(env, "OLDPWD");
        env = searsh_and_add_in_env(env, "OLDPWD\0", path_old);
    }
    return 0;
}