#include "shell.h"

/**
* get_func -    Matches cmd name from stdin to builtin function
* @arg:        The cmd name from the stdin
*/
void (*get_func(char *arg))(char **, vars_t *)
{
    map_func builtins[] = {
        {"env", env},
        {"cd", ch_dir},
        {"exit", quit},
        {NULL, NULL}
    };

    unsigned int i;

    for ( i = 0; builtins[i].func != NULL; i++)
    {
        if (_strcmp(arg, builtins[i].cmd_name) == 0)
            return (builtins[i].func);
    }
    return (NULL);
}

/**
 * check_match - checks if a character matches any in a string
 * @c: character to check
 * @str: string to check
 *
 * Return: 1 if match, 0 if not
 */
unsigned int check_match(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - custom strtok
 * @str: string to tokenize
 * @delim: delimiter to tokenize against
 *
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_start;
	static char *next_token;
	unsigned int i;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_match(next_token[i], delim) == 0)
			break;
	}
	if (next_token[i] == '\0' || next_token[i] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + i;
	next_token = token_start;
	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (check_match(next_token[i], delim) == 1)
			break;
	}
	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}
