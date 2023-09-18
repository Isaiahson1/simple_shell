#include "shell.h"

/**
 * exit_bul - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input.
 * @argv: Program Name
 * @c: Execute Count
 * Return: Nothing (Exit Statue).
 */
void exit_bul(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}
/**
 * change_dir - Change Directory
 * @cmd: Parsed Command
 * @er: Statue Last Commant Executed
 * Return: 0 success 1 Failed (For Old pwd Always 0 Case NO Old pwd)
 */
int change_dir(char **cmd, __attribute__((unused))int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}
/**
 * disp_env - Display Environment Variable
 * @cmd: Parsed command
 * @er: Statue of Last command Executed
 * Return: Always 0
 */
int disp_env(__attribute__((unused)) char **cmd, __attribute__((unused))int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
