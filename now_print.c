#include "shell.h"

/**
 * now_print - prints to the STDOUT
 * @message: whats to be printed
 */

void now_print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
