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
    while (args[i])
    {
        if (args[i] == '/')
            return (EXTERNAL_CMD);
        i++;
    }
    /* Checks for Built-in commands */
    i = 0;
    while (builtin_cmd[i] != NULL)
    {
        if (_strcmp(args, builtin_cmd[i]) == 0)
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
    void (*func)(char **arg);

    switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror(_getenv("PWD"));
					/*dprintf(STDERR_FILENO, "%s: 1: %s: not found.\n", _getenv("PWD"), *args);*/
					exit(2);
				}
				break;
			}
		case BUILT_IN_CMD:
			{
				func = get_func(args[0]);
				func(args);
				break;
			}
		case PATH_CMD:
			{
				break;
			}
		case INVALID_CMD:
			{
				break;
			}
	}
}

    /**if (cmd_type == EXTERNAL_CMD)
    {
        if (execve(*args, args, NULL) == -1)
        {
            perror(_getenv("PWD"));
            dprintf(STDERR_FILENO, "%s: 1: %s: not found.\n", _getenv("PWD"), *args);
            exit(2);
        }
    }
    else if (cmd_type == BUILT_IN_CMD)
    {
        func = get_func(args[0]);
        func(args);
    }
    else if (cmd_type == PATH_CMD)
    {

    }
    else
    {

    }
} */

/**
* _getenv -     Locates the filename of environment variable
* @filename:    Name of file to be searched for
* Return:       Pointer to environment variable
*/
char *_getenv(char *filename)
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















