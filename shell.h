#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#define NULL (void *)

/*
 *Headers
 */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/*
 *Functions From previous works
 */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _atoi(char *s);

/*
 *NEW FUNCTIONS
 */

char *read_line(void);
char **split_line(char *line);
int execute(char *cmd, char **av);
void mem_free(char **av);


/*
 *BUILTIN COMMANDS
 */

int new_exit(char **av);
void new_env(void);
int execute_bl_in(char **av, char *line);
#endif
