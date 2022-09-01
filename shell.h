#ifndef _SHELL_H
#define _SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

/*----- string-helper Functions ----- */
ssize_t _printf(char *, int);
int _putchar(char);
unsigned int _strlen(char *);
int _strcmp(char *, char *);

/*----- Shell utility Functions ----- */
void ctrl_C_func(int);
char *_getline(void);
char **tokenize(char *);
void executecmd (char **);

/*----- Memory Management Functions -----*/
void *_realloc(void *, unsigned int, unsigned int);

/*----- Buffer sizes for Token + String Block ----*/
#define READ_BUF 1028
#define TOK_BUF 64

/* ----- Defined Deliminator ----- */
#define DELIM " \t\r\n\a"

#endif /* SHELL_H */
