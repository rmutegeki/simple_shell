# simple_shell
### Description
A project by Ronald Mutegeki and Raymond Lukwago. The simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. It is intentionally minimalistic, but includes the basic functionality of a traditional Unix-like command line user interface.

### Environment
This shell was developed and tested on `Ubuntu 20.04 LTS` via Vagrant in Virtual Box.

### File Contents
The repository contains the following files:

 **File**   |   **Description**
-------------- | ---------------------
AUTHORS | docker-formatted author file
main.h | header file
README.md | readme file

### Function Descriptions

**Function** | **Description**
-------------- | -----------------
ssize_t get_line(char **lineptr, size_t *n, FILE *stream) | uses getline to read input from STDIN

### Usage and Installation
Clone the repository and then compile using gcc.
```
$ git clone https://github.com/AfaMadza/simple_shell
```
### Compilation
This code was compiled with the following flags:
` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

###### Example command line call (non-interactive mode)

```

$ echo "/bin/ls" | ./hsh
README.md       builtin_func.c  read_line.c    simple_shell.h  util.c
arg_to_path.c   launch_prog.c  shell_loop.c    strutil.c       args_execute.c
hsh             parse_argv.c   simple_shell.c
$

```

