#include "shell.h"

int main (int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *n_read;
	char **args;
	int cmd_type;
	vars_t vars;

	(void) argv;

	signal(SIGINT, ctrl_C_func);

	while (1)
	{
		print("~$ ", STDOUT_FILENO);
		n_read = _getline();

		if (n_read == NULL)
		{
			if (isatty(STDIN_FILENO))
				break;
		}
		args = tokenize(n_read);
		cmd_type = check_command(*args);
		shell_execute(args, cmd_type, &vars);
	}
	return (1);
}
