#include "main.h"

/**
 * print_prompt - function that prints a prompt
 * 
 * Return: Nothing
 */

void print_prompt()
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	printf("#cisfun$ ");
	fflush(stdout);
}
