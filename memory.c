#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and Free
 * @ptr: Pointer
 * @old_size: Previous size of the pointer
 * @new_size: New size of the pointer
 * Return: Nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}
/**
 * free_all - Free array of char pointer and char pointer
 * @cmd: Array pointer.
 * @line: Pointer to the character
 * Retun: Nothing
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memcpy - copy byte from Source to destination
 * @dest: Destination
 * @src: Source
 * @n: Size (How much you will copy.)
 * Return: destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - Fill an array with a constant byte
 * @a: void pointer
 * @el: int
 * @len: length of integer
 * Return: Nothing
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - Allocates memory  for an array using malloc
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
