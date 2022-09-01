#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    char *n_read;
    char **args;
    int cmd_type;

    (void) argv;

    signal(SIGINT, ctrl_C_func);

    while (1)
    {
        _printf("~$ ", STDOUT_FILENO);
        n_read = _getline();

        if (n_read == NULL)
        {
            if (isatty(STDIN_FILENO))
                break;
        }
        args = tokenize(n_read);
        cmd_type = check_cmdtype(*args);
        executecmd(args, cmd_type); /* Not complete Path-cmd, built-in cmd missing*/
    }
    return (0);
}
