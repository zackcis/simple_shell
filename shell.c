#include "main.h"

/**
 * shell - Handles interactive mode
 * @env: Environment
 * @av: Argument array
 *
 * Description: Perform interactive mode workflow.
 * Return: void (Nothing)
 */
void shell(char **env, char **av)
{
	int c;
	size_t n = 1;
	char *cmd = malloc(sizeof(char) * n), *temp = malloc(sizeof(char) * n);
	char **cmd_a = malloc(sizeof(char *) * n);

	do {
		free(cmd);
		free(cmd_a);
		n = 24;
		cmd = malloc(sizeof(char) * n);
		temp = malloc(sizeof(char) * n);
		cmd_a = malloc(sizeof(char *) * n);
		c = 0;
		if (!cmd || !cmd_a)
		{
			write(2, "Out of memory exception\n", 24);
			return;
		}
		if (isatty(fileno(stdin)))
			write(1, "$ ", 2);
		c = getline(&cmd, &n, stdin);
		if (c == -1)
			return;
		_strcln(&cmd);
		if (_strcmp(cmd, "env"))
		{
			builtin_env(env);
		}
		else if (!_strcmp(cmd, "exit") && !_strcmp(cmd, ""))
		{
			_exec(cmd, temp, cmd_a, n, c, env, av);
		}
	} while (!_strcmp(cmd, "exit"));

	free(temp);
	free(cmd);
	free(cmd_a);
}
