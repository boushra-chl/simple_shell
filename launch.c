#include "main.h"

/**
 * hsh_launch - function that executes a command line
 * @args: array of arguments to execute
 *
 * Return: 1 on Success
 */
int hsh_launch(char **args)
{
	pid_t pid, __attribute__((__unused__)) wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
