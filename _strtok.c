#include "shell.h"

/**
 * check_delimeter - Checks if a character Match any char *
 * @c: character to check
 * @str: String to check
 * Return: 1 Success, 0 fail.
 */
unsigned int check_delimeter(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}

	return (0);
}

/**
 * _strtok - Token A string into Token (strtok)
 * @str: String
 * @delim: Delimeter
 * Return: Pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delimeter(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}

	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delimeter(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}

	return (ts);
}
