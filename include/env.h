/*
** EPITECH PROJECT, 2019
** env.h
** File description:
** every functions of libmy
*/

char **searsh_in_env(char **env, char const *to_search);
int env_print(char **table);
char **env_struct_init(char **env_table);
char **searsh_and_add_in_env(char **env, char *first,
                            char const *to_add);
int searsh_and_del_in_env(char **env, char const *first);
int env_len_name(char *str);
int my_cd(char **argv, char **env);