#include "shell.h"


/**
 * execute_bl_in - Builtin command management
 *@cmd: command builtin
 * Return: Return 1 if success.
 */

int execute_bl_in(char *cmd)
{
int c = 0;
if ((strcmp(cmd, "exit")) == 0)
{
	free(cmd), exit(0);
	return (1);
}

if ((strcmp(cmd, "env")) == 0)
{
	while (environ[c])
	{
		write(STDOUT_FILENO, environ[c], _strlen(environ[c]));
		write(STDOUT_FILENO, "\n", 1);
		c++;
	}
	return (1);
}

return (0);
}


/**
 * main - the main shell program
 * Return: 0 on success code error if failure.
 */

int main(void)
{
char *line = NULL, *cmd = NULL, **av = NULL;
size_t bufsize = 0;
int status = 1;

signal(SIGINT, SIG_DFL);

do {
free(av);
av = NULL;
if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "MCshell$ ", 10);

if (getline(&line, &bufsize, stdin) < 0)
{
	free(line);
	line = NULL;
	write(STDIN_FILENO, "\n", 1);
	break;
}

av = split_line(line);

if (av == NULL || *av == NULL)
	continue;

cmd = av[0];

if (execute_bl_in(cmd) == 0)
{
	if (execute(cmd, av) < 0)
	{
		mem_free(av);
		perror("error");
		exit(127);
	}
}
} while (status);
return (0);
}

