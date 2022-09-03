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
	char *prewd;

	home = _getenv("HOME");
	prewd = _getenv("PWD");

	if ((args[1] == NULL) || (_strcmp(args[1], "~") == 0) || (_strcmp(args[1], "$HOME") == 0))
	{
        SETPWD(p->old_pwd);
        if (chdir(home) < 0)
            exit(EXIT_FAILURE);
	}
	else if (_strcmp(args[1], "-") == 0) /*Not printing previous PWD on output */
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
            print(prewd, STDOUT_FILENO);
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
#undef GETCWD










