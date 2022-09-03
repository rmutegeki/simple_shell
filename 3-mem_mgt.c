#include "shell.h"

/**
* _realloc -    reallocates a memory block using malloc & free
* @ptr:         Pointer to previously allocated memory
* @old_size:    Size of allocated space for ptr
* @new_size:    Size of newly allocated space
*
* Return:       Pointer to newly allocated memory, or NULL for failure
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;
    unsigned int index, max = new_size;
    char *oldptr = ptr;

    if (ptr == NULL)
    {
        p = malloc(new_size);
        return (p);
    }
    else if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    else if (new_size == old_size)
        return (ptr);
    p = malloc (new_size);
    if (p == NULL)
        return (NULL);
    if (new_size > old_size)
        max = old_size;
    for (index = 0; index < max; index++)
        p[index] = oldptr[index];
    free(ptr);
    return (p);
}

/**
* free_env -    free the shell's environment
* @env:         Shells environment
*
* Return:       Void
*/
void free_env(char **env)
{
    unsigned int i;

    for (i = 0; env[i] != NULL; i++)
    {
        free(env[i]);
    }
    free(env);
}














