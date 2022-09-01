#include "shell.h"

/**
* ctrl_C_func - Handles the signal interupt by ctrl_C
* @signum:      Signal Number
*/
void ctrl_C_func(int signum)
{
    if (signum == SIGINT)
        _printf("\n ~$ ", STDIN_FILENO);
}

/**
* _getline -    Reads a string from stdin
* Return:       Returns characters read in a block
*/
char *_getline(void)
{
    char *buffer = NULL;
    int BufSize = READ_BUF;
    int index = 0, c, num_read;

    buffer = malloc(sizeof(char) * BufSize);
    if (!buffer)
    {
        perror("Failed to allocate space in memory");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        num_read = read(STDIN_FILENO, &c, 1);
        if (c == EOF || !num_read)
        {
            if (isatty(STDIN_FILENO))
            {
                _printf("\n", STDIN_FILENO);
                return (NULL);
            }
        }
        else if (c == '\n' || !num_read)
        {
            buffer[index] = '\0';
            return (buffer);
        }
        else
            buffer[index] = c;
        index++;

        /* Part for case of reallocation of memory */
        if (index >= BufSize)
        {
            BufSize += READ_BUF;
            buffer = _realloc (buffer, READ_BUF, BufSize);
            if (!buffer)
            {
                perror("Can't reallocate additional memory to buffer");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
* tokenize -    Breaks string block into parts based on deliminator
* @str:         String block to be split into parts based on deliminator
* Return:       Pointers to the 1st letter of list of strings
*/
char **tokenize(char *str)
{
    char **tokens = NULL;
    int BufSize = TOK_BUF;
    int index = 0;
    char *token;

    tokens = malloc(sizeof(char *) * BufSize);

    if (!tokens)
    {
        perror("Can't allocate space to block");
        exit (EXIT_FAILURE);
    }

    token = strtok(str, DELIM);

    while (token != NULL)
    {
        tokens[index] = token;
        index++;

        /*Addition Memory Space if string space bigger than tokens*/
        if (index >= BufSize)
        {
            BufSize += TOK_BUF;
            tokens = _realloc(tokens,(TOK_BUF * sizeof(char *)),(BufSize * sizeof(char *)));
            if (!tokens)
            {
                perror("Can't allocate additional memory");
                exit (EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIM);
    }
    tokens[index] = NULL;
    return (tokens);
}

/**
* execute-cmd - Executes inserted command
* @args:        List of pointers to command strings
*/
void executecmd (char **args)
{
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0)
    {
        execve(args[0], args, NULL);
        dprintf(STDERR_FILENO, "%s: Command not found.\n", *args);
        exit(1);
    }
    else if (child_pid < 0)
    {
        perror("Failed to create child process");
        exit(1);
    }
    else
        wait(&status);
}



















