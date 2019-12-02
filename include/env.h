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

int env_print(char **env_table);
char **env_struct_init(char **env_table);