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
#include "include/error.h"

int my_cd(char **argv, char **env)
{
    char cwd[1024];
    errno = 0;

    if (chdir(argv[1]) != 0) {
        my_error_handle("cd", argv[1], errno);
        return 84;
    }
    getcwd(cwd, sizeof(cwd));
}