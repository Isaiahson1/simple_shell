#include "shell.h"


/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: Exit Value by status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin_cmds(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_command(cmd, input, counter, argv);
		}
		free_all(cmd, input);
	}
	return (statue);
}
/**
 * check_builtin - check builtin
 *
 * @cmd: Command to check
 * Return: 0 upon Success, on fail -1
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * create_env - Create Array of Environment Variable
 * @env: Array of Environment Variables
 * Return: Nothing
 */
void create_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}
