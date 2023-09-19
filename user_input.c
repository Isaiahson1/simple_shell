#include "shell.h"

/**
 * read_command - Reads command inputed by the user
 * @command: User input
 * @size: size of the input
 * Return: Nothing
 */
 void read_command(char *command, size_t size)
{
	if (fgets(command, size,stdin) == NULL)
	{
		if (feof(stdin))
		{
			PRINTER("\n");
			exit(EXIT_SUCCESS);
		} 
		else
		{
			PRINTER("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}

