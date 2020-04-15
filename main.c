#include "shell.h"

/**
 * main - the main shell program
 * Return: 0 on success code error if failure.
 */

int main(void)
{
char *cmd, *line = NULL, **av = NULL;
size_t bufsize = 0;

signal(SIGINT, SIG_DFL);

while (1)
{
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
if (execute(cmd, av) < 0)
{
	if (strcmp(cmd, "exit") != 0)
	{
		free(av);
		perror("error");
		return (0);
	}
}
free(line);
}
return (0);
}

