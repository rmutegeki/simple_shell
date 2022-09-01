#include "shell.h"

/**
* check_cmdtype -   checks the type of the command from stdin
* @args:            first argument of the array of pointers
* Returns:          Marco integer to
*/
int check_cmdtype(char *args)
{
    int i = 0;
    char *builtin_cmd[] = {"exit", "cd", "env", NULL};

    /* Checks for external commands */
    while (args[i] != NULL)
    {
        if (args[i] == '/')
            return (EXTERNAL_CMD);
        i++;
    }
    /* Checks for Built-in commands */
    i = 0;
    while (builtin_cmd[i] != NULL)
    {
        if (_strcmp(args[0], builtin_cmd[i]) == 0)
            return (BUILT_IN_CMD);
        i++;
    }
    return (INVALID_CMD);
}

/**
* execute -     Executes command based on command type
* @args:        Double Pointer to array of commands
* @cmd_type:    Type of command to be executed
*/
void execute(char **args, int cmd_type)
{
    if (cmd_type == EXTERNAL_CMD)
    {
        if (execve(*args, args, NULL) == -1)
        {
            dprintf(STDERR_FILENO, "%s: 1: %s: not found.\n", _getenv("PWD"), *args);
            exit(2);
        }
    }
    else if (cmd_type == BUILT_IN_CMD)
    {
        /* To be populated */
    }
    else if (cmd_type == PATH_CMD)
    {
        /* To be populated */
    }
    else
    {
        /* To be populated */
    }
}

/**
* _getenv -     Locates the filename of environment variable
* @filename:    Name of file to be searched for
* Return:       Pointer to environment variable
*/
char *_getenv(const char *filename)
{
	size_t i = 0, k = 0;
	char *env_var = NULL;

	while (environ[i] != NULL)
	{
		env_var = environ[i];

		while (env_var[k] == filename[k] && env_var[k] != '=' && env_var[k] && filename[k])
		{
			k++;
		}
		if(filename[k] == '\0')
			return (env_var);
		i++;
	}
	return (NULL);
}















