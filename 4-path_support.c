#include "shell.h"

/**
* check_cmdtype -   checks the type of the command from stdin
* @args:            first argument of the array of pointers
* Returns:          Marco integer to
*/
int check_command(char *args)
{
	int i = 0;
	char *builtins[] = {"exit", "cd", "env", NULL};
	char *path = NULL;

	while (args[i])
	{
		if (args[i] == '/')
			return (EXTERNAL_CMD);
		i++;
	}

	i = 0;

	while (builtins[i] != NULL)
	{
		if (_strcmp(args, builtins[i]) == 0)
			return (BUILT_IN_CMD);
		i++;
	}

	path = locate_exe(args);
	if (path)
        return (PATH_CMD);

	return (INVALID_CMD);
}

/**
* execute -     Executes command based on command type
* @args:        Double Pointer to array of commands
* @cmd_type:    Type of command to be executed
*/
void execute(char **args, int cmd_type, vars_t *vars)
{
	void (*func)(char **args, vars_t *lz);

	switch (cmd_type)
	{
		case EXTERNAL_CMD:
			{
                if (execve(*args, args, NULL) == -1)
                    execve_error(args);
				break;
			}
		case BUILT_IN_CMD:
			{
				func = get_func(*args);
				func(args, vars);
				break;
			}
		case PATH_CMD:
			{
                if (execve(locate_exe(*args), args, NULL) == -1)
                    execve_error(args);
				break;
			}
		case INVALID_CMD:
			{
				/* Name of shell program missing */
				print(": 1: ", STDERR_FILENO);
				print(*args, STDERR_FILENO);
				print(": not found\n", STDERR_FILENO);
			}
	}
}

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
			return (_strdup(env_var));
		i++;
	}
	return (NULL);
}

/**
* locate_exe -  Locates path directory containing function executable file
* @cmd_name:    Exectable File to be searched for.
* Return:       Returns absolute path to executable file
*/
char *locate_exe(char *cmd_name)
{
    char *path = _getenv("PATH");
    char *dir_path = NULL;
    char *file_path = NULL;

    /*Check if stdin is already in absolute format */
    if (filepath_exits(cmd_name))
        return (_strdup(cmd_name));

    _strtok(path, "=");
    dir_path = _strtok(NULL, ":");

    while (dir_path)
    {
        file_path = join_paths('/', dir_path, cmd_name);
        if (filepath_exits(file_path))
        {
            free(path);
            return (file_path);
        }
        free(file_path);
        file_path = NULL;

        dir_path = _strtok(NULL, ":");
    }
    free(path);
    return (NULL);
}










