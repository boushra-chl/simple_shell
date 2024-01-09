#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void hsh_loop(void);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
int hsh_launch(char **args);
int hsh_execute(char **args);
/*builtins*/
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);
int hsh_num_builtins(void);

#endif
