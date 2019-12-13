/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <stdlib.h>
#include "include/my.h"

int env_len_name(char *str)
{
    int i;
    for (i = 0; str[i] != '=' && str[i] != ':' && str[i] != '\0'; i++);
    return i;
}

int number_of_lines(char **env_table)
{
    int i;

    for (i = 0; env_table[i] != NULL; i++);
    return i;
}

char **env_struct_init(char **env_table)
{
    int i;
    int len_name = number_of_lines(env_table);
    char **env = malloc(sizeof(char *) * (len_name + 100));

    for (i = 0; i < len_name; i++) {
        env[i] = my_strdup(env_table[i]);
    }
    env[i+50] = NULL;
    return env;
}