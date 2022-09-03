#include "shell.h"

/**
 * _env - prints the current environment
 * @args: List of arguments
 */
void env(char **args __attribute__((unused)), vars_t *p __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i++], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

void quit(char **args, vars_t *p __attribute__((unused)))
	{
	(void) args;
}

/**
* ch_dir -  Changes working directory of the prcess
* @args:    Command arguments placed into the command
* @p:       Global variable containing previously stored
*           working directory
*/
void ch_dir(char **args __attribute__((unused)), vars_t *p)
{
	char *home;

	home = _getenv("HOME");

	if (args[1] == NULL)
	{
        SETPWD(p->old_pwd);
        if (chdir(home) < 0)
            exit(EXIT_FAILURE);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
        if (p->old_pwd == NULL)
        {
            SETPWD(p->old_pwd);
            if (chdir(home) < 0)
                exit(EXIT_FAILURE);
        }
        else
        {
            SETPWD(p->old_pwd);
            if(chdir(p->old_pwd) < 0)
                exit(EXIT_FAILURE);
        }
	}
	else
	{
        SETPWD(p->old_pwd);
        if(chdir(args[1]) < 0)
            exit(EXIT_FAILURE);
	}
}











