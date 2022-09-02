#include "shell.h"

/**
* get_func -    Matches cmd name from stdin to builtin function
* @arg:        The cmd name from the stdin
*/
void (*get_func(char *arg))(char **)
{
    map_func builtins[] = {
        {"env", env},
        {"cd", ch_dir},
        {"exit", quit},
        {NULL, NULL}
    };

    unsigned int i;

    for ( i = 0; builtins[i].func != NULL; i++)
    {
        if (_strcmp(arg, builtins[i].cmd_name) == 0)
            return (builtins[i].func);
    }
    return (NULL);
}

