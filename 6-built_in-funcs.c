#include "shell.h"

/**
 * _env - prints the current environment
 * @args: List of arguments
 */
void env(char **args __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i++], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

void quit(char **args)
	{
	(void) args;
}

void ch_dir(char **args)
{
	(void) args;
}
