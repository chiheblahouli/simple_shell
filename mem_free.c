#include "shell.h"

/**
 *mem_free - Free arguments
 *@av: arguments of a program
 *Return: Void
 */

void mem_free(char **av)
{
int c = 0;
if (av == NULL)
return;

else
{
	do {
		free(av[c]);
		av[c] = NULL;
		c++;
	} while (av[c]);
}

free(av);
av = NULL;
}
