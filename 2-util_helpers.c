#include "shell.h"

/**
* ctrl_C_func - Handles the signal interupt by ctrl_C
* @signum:      Signal Number
*/
void ctrl_C_func(int signum)
{
    if (signum == SIGINT)
        print("\n ~$ ", STDIN_FILENO);
}

/**
* _getline -    Reads a string from stdin
* Return:       Returns characters read in a block
*/
char *_getline(void)
{
	int bufSize = READ_BUF, no_read, position = 0;

	char *buffer = malloc(bufSize * sizeof(char));
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		no_read = read(STDIN_FILENO, &c, 1);
		if (c == EOF || !no_read)
		{
			/* checks if the input is EOT
			 	(ctrl+D) and if it is from the terminal
			*/
			if (isatty(STDIN_FILENO) == 1)
			{
				print("\n", STDIN_FILENO);
				return (NULL);
			}
		}
		else if (c == '\n' || !no_read)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;

		if (position >= bufSize)
		{
			bufSize += READ_BUF;
			buffer = _realloc(buffer, READ_BUF, bufSize);
			if (!buffer)
			{
				perror("Failed to re-allocate a space in the memory");
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
void shell_execute(char **args, int cmd_type, vars_t *vars)
{
	int status;
	pid_t ChildPID;

	if (cmd_type == EXTERNAL_CMD || cmd_type == PATH_CMD)
	{
		ChildPID = fork();

		if (ChildPID == 0)
		{
			execute(args, cmd_type, vars);
		}
		if (ChildPID < 0)
		{
			perror("failed to call fork");
			exit(1);
		}
		else
			wait(&status);
	}
	else
		execute(args, cmd_type, vars);
}
