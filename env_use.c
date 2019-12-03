/*
** EPITECH PROJECT, 2019
** my_cat_text.c
** File description:
** cat texts
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int env_len_name(char *str);

int env_nb_word(char *str)
{
    int j = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ':')
            j++;
    }
    if (i = 0)
        return 0;
    return j + 1;
}

char **env_str_word_array(char *str)
{
    int nb_words = env_nb_word(str);
    char **words =  malloc(sizeof(char *) * (nb_words + 1));
    int len;

    for (int i = 0; i < nb_words; i++) {
        len = env_len_name(str);
        words[i] = malloc(sizeof(char) * (len + 1));
        words[i] = my_strncpy(words[i], str, len);
        i += len;
    }
    return words;
}

char **searsh_in_env(char **env, char const *to_search)
{
    int i;
    int len_word;

    for (i = 0; env[i] != NULL; i++) {
        len_word = env_len_name(env[i]);
        if (my_strncmp(env[i], to_search, len_word) == 0) {
            return env_str_word_array(&env[i][len_word + 1]);
        }
    }
    return NULL;
}

int env_print(char **table)
{
    for (int i = 0; table[i] != NULL; i++){
        my_putstr(table[i]);
        my_putchar('\n');
    }
    return 0;
}