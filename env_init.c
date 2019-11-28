/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <stdlib.h>
#include "include/env.h"
#include "include/my.h"

int env_len_name(char *str)
{
    int i;

    for (i = 0; str[i] != '=' && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return 0;
    else
        return i;
}

char *new_content(char *str)
{
    int i;
    char *cmd = malloc(sizeof(char) * 400);

    for (i = 0; str[i] != ':' && str[i] != '\0'; i++) {
        cmd[i] = str[i];
    }
    cmd[i] = '\0';
    return cmd;
}

char **read_content(char *buffer)
{
    int i = 1;
    int point = 0;
    int readsize = my_strlen(buffer);
    char **argv = malloc(sizeof(char *) * 4096);

    for(i = 0; i < readsize; i++) {
        if (buffer[i] != '\0' && buffer[i] != ':') {
            argv[point] = new_content(&buffer[i]);
            point++;
            for(; buffer[i] != ':' && i < readsize; i++);
        }
    }
    argv[point] = NULL;
    return argv;
}

env_struct *env_struct_init(char **env_table)
{
    env_struct *env_var = malloc(sizeof(env_struct));
    int len_name;

    len_name = env_len_name(env_table[0]);
    if(len_name > 0) {
        env_var->NAME = malloc(sizeof(char) * (len_name + 1));
        my_strncpy(env_var->NAME, env_table[0], len_name);
    }
    env_var->content = read_content(&env_table[0][len_name + 1]);
    if (env_table[1] != NULL)
        env_var->next = env_struct_init(&env_table[1]);
    else
        env_var->next = NULL;
    return env_var;
}