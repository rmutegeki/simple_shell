#include "shell.h"

/**
 * fork_error - error when fork fails
 * @args: argument array passed from main.
 * Return: void
 */
void fork_error(char **args __attribute__((unused)))
{
	perror(_getenv("PWD"));
    exit(EXIT_FAILURE);
}

/**
 * execve_error - error when execve fails
 * @args: argument array passed from main.
 * Return: void
 */
void execve_error(char **args __attribute__((unused)))
{
	perror(_getenv("PWD"));
    exit(EXIT_FAILURE);
}









