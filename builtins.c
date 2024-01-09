#include "main.h"

/**
 * hsh_cd - function that changes direction
 * @args: array of strings
 *
 * Return: 1 on Success
 */
int hsh_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("hsh");
	}
	return (1);
}

/**
 * hsh_help - function help for the user
 * @args: array of arguments
 *
 * Return: 1 on Success
 */

int hsh_help(char __attribute__((__unused__)) **args)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};

	printf("Bouchra's HSH\n");
	printf("Type program names and arguments, and hit enter\n");
	printf("The following are built-ins:\n");
	for (i = 0; i < hsh_num_builtins(); i++)
		printf(" %s\n", builtin_str[i]);
	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * hsh_exit - function that exits the shell
 * @args: array of strings
 *
 * Return: 0 on Success
 */

int hsh_exit(char __attribute__((__unused__)) **args)
{
	return (0);
}
/**
 * hsh_num_builtins - count builtins
 * 
 * Return: integer
 */
int hsh_num_builtins()
{
	char *builtin_str[] = {"cd", "help", "exit"};

	return(sizeof(builtin_str));
}

