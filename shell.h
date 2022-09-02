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
#include <sys/stat.h>
#include <errno.h>

/* ---- Declaring Environment Variables ---- */
extern char **environ;

/* ---- Built-in Support Functions ----- */
typedef struct built_in_func
{
    char *cmd_name;
    void (*func)(char **arg);
} map_func;

void (*get_func(char *))(char **);

/* ----- Built-in Commands ---- */
void env(char **);
void ch_dir(char **);
void quit(char **);

/*----- string-helper Functions ----- */
ssize_t print(char *, int);
unsigned int _strlen(char *);
int _strcmp(char *, char *);

/*----- Shell utility Functions ----- */
void ctrl_C_func(int);
char *_getline(void);
char **tokenize(char *);
void shell_execute(char **, int);

/* ----- Path Support Functions ----- */
int check_command(char *);
void execute(char **, int);
char *_getenv(char *);

/*----- Memory Management Functions -----*/
void *_realloc(void *, unsigned int, unsigned int);

/*----- Buffer sizes for Token + String Block ----*/
#define READ_BUF 1028
#define TOK_BUF 64

/* ----- Defined Deliminator ----- */
#define DELIM " \a\t\r\n"

/* --- Command Type Representations ---- */
#define BUILT_IN_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#endif /* SHELL_H */
