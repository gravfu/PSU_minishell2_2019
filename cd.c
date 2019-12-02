

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int path(char **argv, int argc, char *the_path)
{
    if (the_path == NULL) {
        the_path = malloc(sizeof(char) * 2);
        the_path[0] = '.';
        the_path[1] = '\0';
    }
    if (argv[2] == NULL) {
        the_path[0] = '~';
        the_path[1] = '\0';
    }
    if (argv[2][0] == '/')
    my_strcat(the_path, "/");
    my_strcat(the_path, argv[2])
}