#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    char *n_read;
    char **args;

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
        executecmd(args);
    }
    return (0);
}
