#include "shell.h"

/**
 * prompt - Display shell Prompt
 * Return: Nothing.
 */
void prompt(void)
{
	PRINTER("Prompt$$ ");
}

/**
 * print_error - Display Error Based on Command and number of loops
 * @input: User Input
 * @counter: Simple Shell Count Loop
 * @argv: Program Name
 * Return: Nothing
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(":");

	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": Command not found\n");
}
