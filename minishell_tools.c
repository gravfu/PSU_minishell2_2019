/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** usefull for many files on this task
*/

#include "include/my.h"
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

void reset_buffer(char *buffer, int size)
{
    for (int i = 0; i <= size; i++) {
        buffer[i] = 0;
    }
}

char *my_cat(char *str1, char *str2)
{
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *new_str = malloc(sizeof(char) * (size1 + size2 + 3));
    int i = 0;

    for (int j = 0; j < my_strlen(str1); i++, j++)
        new_str[i] = str1[j];
    for (int j = 0; j < my_strlen(str2); i++, j++)
        new_str[i] = str2[j];
    new_str[i] = '\0';
    return new_str;
}

int char_in_array(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}