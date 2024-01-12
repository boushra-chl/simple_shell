#include "main.h"

/**
 * execute_command - function that executes a command
 * @command: command to execute
 * 
 * Return: Nothing
 */

void execute_command(char *command)
{
	pid_t pid = fork();
	int status;
	char *args[2];
	char *env[] = {NULL};

	args[0] = "command";
	args[1] = NULL;
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command, args, env);
		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			fprintf(stderr, "./shell: %s: No such file or directory\n", command);
	}
}	
