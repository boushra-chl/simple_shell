#include "main.h"

/**
 * hsh_execute - function
 * @args: array of strings
 *
 * Return: integer
 */
int hsh_execute(char **args)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit"};
	int (*builtin_func[])(char **) = {&hsh_cd, &hsh_help, &hsh_exit};

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	}
	return (hsh_launch(args));
}

