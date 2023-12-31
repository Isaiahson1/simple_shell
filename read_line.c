#include "shell.h"

/**
 * read_line - reads the input string.
 *
 * @i_eof: return value of getline function
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *user_input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&user_input, &bufsize, stdin);

	return (user_input);
}
