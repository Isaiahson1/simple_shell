#include "shell.h"

/**
 * now_print - prints to the STDOUT
 * @str: whats to be printed
 */

void now_print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
