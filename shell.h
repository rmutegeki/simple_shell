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

/* ---- Global Shell Variables ----- */
typedef struct global_vars
{
    char *old_pwd;
} vars_t;

/* ---- Built-in Support Functions ----- */
typedef struct built_in_func
{
    char *cmd_name;
    void (*func)(char **arg, vars_t *);
} map_func;

void (*get_func(char *))(char **, vars_t *);

/* ----- Built-in Commands ---- */
void env(char **, vars_t *);
void ch_dir(char **, vars_t *);
void quit(char **, vars_t *);

/*----- string-helper Functions ----- */
ssize_t print(char *, int);
unsigned int _strlen(char *);
int _strcmp(char *, char *);
char *_strdup(char *);

/*----- Shell utility Functions ----- */
void ctrl_C_func(int);
char *_getline(void);
char **tokenize(char *);
void shell_execute(char **, int, vars_t *);
unsigned int check_match(char, const char *);
char *_strtok(char *, const char *);

/* ----- Path Support Functions ----- */
int check_command(char *);
void execute(char **, int, vars_t *);
char *_getenv(char *);
char *locate_exe(char *);

/* ----- Path Support Functions (2) ----- */
char *join_paths(char, char *, char *);
int filepath_exits(char *);

/*----- Memory Management Functions -----*/
void *_realloc(void *, unsigned int, unsigned int);
void free_env(char **);

/*---- Error Messages ----- */
void fork_error(char **);
void execve_error(char **);

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

/* Set current Working Directory */
#define SETPWD(D) (D = _getenv("OLDPWD"))

#endif /* SHELL_H */
