#include "shell.h"

/**
 * _prerror - Print custom error
 * @argc: Program Name
 * @c: Error Count
 * @cmd: Command
 * Return:Void
 */
void _prerror(char **argc, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argc[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Number not Allowed: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
