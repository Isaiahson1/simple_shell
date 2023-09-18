#include "shell.h"

/**
 * handle_builtin_cmds - handle Builtin commands
 * @cmd: Parsed Command
 * @er: Statue of last execute
 * Return: Incase of fail -1, 0 success
 * (Return :Execute builtin)
 */

int handle_builtin_cmds(char **cmd, int er)
{
	bul_t bil[] = {
		{"cd", change_dir},
		{"env", disp_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};

	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + 1)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}

	return (-1);
}


/**
 * check_command - Execute simple shell command
 * (Fork, Wait, Execute)
 * @cmd: Parsed Command
 * @input: User Input
 * @c:Shell Execution Time case of command not found
 * @argv:Program Name
 * Return: 1 Case Command NULL, -1 Wrong Command 0 Command Executed
 */
int check_command(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}

		return (EXIT_SUCCESS);
	}
	wait(&status);

	return (0);
}
/**
 * signal_to_handle - Handle ^c
 * @sig: Captured Signal
 * Return: Nothing
 */
void signal_to_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
