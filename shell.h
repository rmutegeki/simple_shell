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
#include <errno.h>

/* ---- Declaring Environment Variables ---- */
extern char **environ;

/*----- string-helper Functions ----- */
ssize_t _printf(char *, int);
int _putchar(char);
unsigned int _strlen(char *);
int _strcmp(char *, char *);

/*----- Shell utility Functions ----- */
void ctrl_C_func(int);
char *_getline(void);
char **tokenize(char *);
void executecmd(char **, int);

/* ----- Path Support Functions ----- */
int check_cmdtype(char *);
void execute(char **, int);
char *_getenv(const char *);


/*----- Memory Management Functions -----*/
void *_realloc(void *, unsigned int, unsigned int);

/*----- Buffer sizes for Token + String Block ----*/
#define READ_BUF 1028
#define TOK_BUF 64

/* ----- Defined Deliminator ----- */
#define DELIM " \t\r\n\a"

/* --- Command Type Representations ---- */
#define BUILT_IN_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#endif /* SHELL_H */
