#include "main.h"

/**
 * main - main function
 *
 * Return: 0 on success
 */
int main()
{
	char command[MAX_COMMAND_LENGTH];
	size_t len = strlen(command);

	while (1)
	{
		print_prompt();

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		if (len > 0 && command[len - 1] == '\n')
			command[len - 1] = '\0';
		if (strcmp(command, "exit") == 0)
			break;
		execute_command(command);
	}
	return (0);
}
