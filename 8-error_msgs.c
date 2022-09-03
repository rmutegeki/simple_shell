#include "shell.h"

/**
 * fork_error - error when fork fails
 * @argv: argument array passed from main.
 * Return: void
 */
void fork_error(char **args __attribute__((unused)))
{
	perror(_getenv("PWD"));
    exit(EXIT_FAILURE);
}

/**
 * execve_error - error when execve fails
 * @argv: argument array passed from main.
 * Return: void
 */
void execve_error(char **args __attribute__((unused)))
{
	perror(_getenv("PWD"));
    exit(EXIT_FAILURE);
}
