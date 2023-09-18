#include "shell.h"

/**
 * _putchar - writess the character c to stdout
 * @c: The character to print
 * Return: 1 on success and -1 on error and errno is set
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copies a string
 * @dest: string destination
 * @src: string source.
 * @n: Number of items
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + 1) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - length of string
 * @str: string
 * Return: Number of characters in the string
 */
int _strlen(char *str)
{
	int n;

	for (n = 0; str[n] != '\0'; n++)
	{
		continue;
	}
	return (n);
}

/**
 * _atoi - convert to an int
 * @str: string
 * Return: int
 */
int _atoi(char *str)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;

	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
		{
			x *= -1;
			i++;
		}
	}
	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		n = (n * 10) + x * ((str[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _puts - print a string
 * @str: Pointer char
 * Return: Nothing.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
