#include "shell.h"

/**
* print - prints stdin to stdout on terminal
* @str:     string buffer to be written to
* @fd:      File Descriptor
*
* Return:   Outputs stdin on stdout of file descriptor
*/
ssize_t print(char *str, int fd)
{
    ssize_t len = 0, num;

    fd = STDOUT_FILENO;
    num = strlen(str);
    len = write(fd, str, num);
    if (len != num)
    {
        perror("Can't print to stdout");
        return (-1);
    }
    return (len);
}

/**
* _strlen - Gets the length of a string
* @str:     String to be measured
*
* Return:   Returns the number of characters in string
*/
unsigned int _strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

/**
* _strcmp - perform lexicogarphic comparision of two strings
* @str1:    the first string
* @str2:    the second string
*
* Return:   negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
*/
int _strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    if (*str1 == *str2)
        return (0);
    else
        return (*str1 < *str2 ? -1 : 1);
}
