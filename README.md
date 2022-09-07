# simple_shell
### Description :book:
A project by Ronald Mutegeki and Raymond Lukwago. The simple_shell is a command line interpreter, or shell, in the tradition of the first Unix shell written by Ken Thompson in 1971. It is intentionally minimalistic, but includes the basic functionality of a traditional Unix-like command line user interface.

### Environment :floppy_disk:
This shell was developed and tested on `Ubuntu 20.04 LTS` via Vagrant in Virtual Box.

### File Contents :open_file_folder:
The repository contains the following files:

 **File**   |   **Description**
-------------- | ---------------------
AUTHORS | docker-formatted author file
main.h | header file
README.md | readme file
aux_lists.c | xxxxx
aux_lists2.c | xxxxxx
aux_strfunctions.c | xxxxxx
aux_mem.c | xxxxx
aux_str2.c | xxxxxxx
aux_str3.c | xxxxxxx
check_syntax_error.c | xxxxxxxx
shell_loop.c | xxxxxxx
split.c | xxxxxxxxx
rep_var.c | xxxxxxxx
get_line.c | xxxxxxxx
exec_line.c | xxxxxxxxxxxxxx
cmd_exec.c | xxxxxxxxxxxxxxxxxxxxxx
env1.c | xxxxxx
cd.c | xxxxxxxxxxxx
cd_shell.c | xxxxxxxxxx
get_builtin.c | xxxxxxxxxxx
_exit.c | xxxxxxxxxxx
aux_stdlib.c | xxxxxxxxxxxx
aux_error1.c | xxxxxxxxxxxxxx
aux_error2.c | xxxxxxxxxxx
get_error.c | xxxxxxxxxxxxxxx
get_sigint.c | xxxxxxxxxxxxxxx
aux_help.c | xxxxxxxxxxxxx
aux_help2.c | xxxxxxxxxxxx
get_help.c | xxxxxxxxxxx

### Function Descriptions :open_file_folder:

**Function** | **Description**
-------------- | -----------------
ssize_t get_line(char **lineptr, size_t *n, FILE *stream) | uses getline to read input from STDIN

### Usage and Installation :floppy_disk:
Clone the repository and then compile using gcc.
```
$ git clone https://github.com/AfaMadza/simple_shell
```
### Compilation :floppy_disk:
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

## License :warning:

:copyright: 2022 All rights reserved.

### Authors

* [**Raymond Lukwago**](https://github.com/lukwagoraymond)
* [**Ronald Mutegeki**](https://github.com/rmutegeki)




