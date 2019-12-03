
#include <stdlib.h>
#include "include/env.h"
#include "include/my.h"

char **searsh_and_add_in_env(char **env, char *first, char const *to_add)
{
    int i;
    int len_word;

    for (i = 0; env[i] != NULL; i++) {
        len_word = env_len_name(env[i]);
        if (my_strncmp(env[i], first, len_word) == 0) {
            my_strcat(env[i], ":");
            my_strcat(env[i], to_add);
            return env;
        }
    }
    env[i] = my_strdup(first);
    env[i] = my_strcat(first, "=");
    env[i] = my_strcat(first, to_add);
    env[i+1] = NULL;
    return env;
}

int searsh_and_del_in_env(char **env, char const *first)
{
    int i;
    int len_word;
    int found = 0;

    for (i = 0; env[i] != NULL; i++) {
        len_word = env_len_name(env[i]);
        if (my_strncmp(env[i], first, len_word) == 0 || found == 1) {
            env[i] = env[i+1];
        }
    }
    if (found == 0)
        return 84;
    return 0;
}