#include "main.h"

/**
 * hsh_loop - function that reads a line parses it and executes
 * @line: pointer to text typed by user
 * @args: array of different arguments of a text
 * @status: integer
 *
 * Return: Nothing
 */

void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("> ");
		line = hsh_read_line();
		args = hsh_split_line(line);
		status = hsh_execute(args);
		free(line);
		free(args);
	}
	while (status);
}
