#include "shell.h"

/*
* join_paths -  Appends the cmd_alias to path directory
* @sep:         Character to use as a separator between path directory
*               and cmd_alias
* @dir_path:    Pointer to path directories located in $PATH
* @cmd_alias:   Command alias to represent
*/
char *join_paths(char sep, char *dir_path, char *cmd_alias)
{
    char *joined_buf = NULL;
    unsigned int i, k, len = 0;

    /* Find length of dir_path */
    i = 0;
    while (dir_path[i++] != '\0')
        ;
    len += i;

    /* Find length of cmd_alias */
    i = 0;
    while (cmd_alias[i++] != '\0')
        ;
    len += i;
    len += 1; /* One more space to accomodate the sep */

    joined_buf = malloc(sizeof(*joined_buf) * (len + 1)); /* Plus one for the null terminator */
    /*check if buffer memory was dynamically allocated */

    i = 0, k = 0;
    while (dir_path[k])
    {
        joined_buf[i] = dir_path[k];
        i++;
        k++;
    }
    joined_buf[i++] = sep;

    k = 0;
    while (cmd_alias[k])
    {
        joined_buf[i] = cmd_alias[k];
        i++;
        k++;
    }
    joined_buf[i] = '\0';

    return(joined_buf);
}

/**
* filepath_exits -  Checks if the filepath exists in $PATH directories
* @filepath:        File absolute path to be checked
* Return:           Returns (1) if path exists (0) if it doesn't
*/
int filepath_exits(char *filepath)
{
    struct stat buffer;

    if (stat(filepath, &buffer) == 0)
        return (1);

    return (0);
}
