/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/env.h"

char **set_content(char *str)
{
    int j = 0;
    char **content = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] = ':')
            j++;
    }
    content = malloc(sizeof(char *) * (j + 1));
    content[j] = NULL;
    return content;
}

int env_print(env_struct *env_table)
{
    if (env_table != NULL) {
        my_putstr(env_table->NAME);
        my_putchar('=');
        for (int i = 0; env_table->content[i] != NULL; i++) {
            if (i > 1)
                my_putchar(':');
            my_putstr(env_table->content[i]);
        }
        my_putchar('\n');
        env_print(env_table->next);
    }
    return 0;
}