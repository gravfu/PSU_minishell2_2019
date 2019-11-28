/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

typedef struct env_struct {
    char *NAME;
    char **content;
    struct env_struct *next;
} env_struct;

int env_print(env_struct *env_table);
env_struct *env_struct_init(char **env_table);