#include "shell.h"

/**
 * parse_cmd - Parse line of Input
 * @input: User Input to Parse
 * Return: Array of char (Parsed)
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
