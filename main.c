#include "shell.h"


/**
 * non_inter_active_mode - function
 * @commands: commands
 * @command: command
 */
void non_inter_active_mode(char *commands, char *command)
{
	ssize_t actual_command_size = 0;
	size_t max_command_size = 0;

	actual_command_size = _getline(&commands, &max_command_size, stdin);
	while (actual_command_size > -1)
	{
		if (!check_empty(commands))
		{
			free(commands);
			commands = NULL;
			continue;
		}
		_concat(command, commands, _strlen(command));
		free(commands);
		commands = NULL;
		actual_command_size = _getline(&commands, &max_command_size, stdin);
	}
	command[_strlen(command) - 1] = '\0';

}
/**
 * other_commands - function handles othe command
 * @args: array of arguments
 * Return: int
 */
int other_commands(char **args)
{
	pid_t pid;
	char intonum[100], digit[100];

	if (compare(args[0], "cd"))
	{
		change_dir(args);
		return (1);
	}
	if (compare(args[0], "setenv") || compare(args[0], "unsetenv"))
	{
		/*printf("setenv and unset will be handled later\n");*/
		return (1);
	}
	if (compare(args[0], "echo") && compare(args[1], "$$"))
	{
		pid = getpid();
		intToStr(intonum, pid, 10, 0);
		_concat(args[1], intonum, 0);
		return (0);
	}
	if (compare(args[0], "echo") && compare(args[1], "$?"))
	{
		string_digit(get_status(0, 0), digit);
		_concat(args[1], digit, 0);
		return (0);
	}
	return (0);
}
/**
 * handle_lines - function name
 * @command: str input
 * @lines: array to store lines
 * @args: array stores args
 */
void handle_lines(char **args, char **lines, char *command)
{
	int j;

	for (j = 0; lines[j] != NULL; j++)
	{
		if (!check_empty(lines[j]))
		{
			free(lines[j]);
			continue;
		}
		process(args, lines[j], command);
		free(lines[j]);
	}
}

/**
 * active_mode - function
 * @commands: commands
 * @command: command
 */

void active_mode(char *commands, char *command)
{
	ssize_t actual_command_size = 0;
	size_t max_command_size = 0;

	actual_command_size = _getline(&commands, &max_command_size, stdin);
	if (actual_command_size > -1)
	{
		commands[actual_command_size] = '\0';
		_concat(command, commands, 0);
		free(commands);
		commands = NULL;
	}

}

/**
 * main - main function
 * @argc: size
 * @argv: arrray
 * Return: int
 */

int main(int argc, char *argv[])
{
	char command[1000] = "", *commands, *lines[1024];
	bool from_pipe = false;
	char *args[1024]; /*maximum 1024 arguments*/
	ssize_t actual_command_size;

	program_name(argv[0]);
	get_status(0, 0);
	while (!from_pipe && 1)
	{
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		else
			displayPrompt();
		commands = NULL;
		if (argc < 2)
		{
			if (!from_pipe)
				active_mode(commands, command);
			else
				non_inter_active_mode(commands, command);
		}
		else
		{
			actual_command_size = readFile(argv[1], &commands);
			from_pipe = true;
			if (actual_command_size == -1)
			{
				free(commands);
				continue;
			}
			_concat(command, commands, 0);
		}
		if (!check_empty(command))
			continue;
		tokenize_lines(command, lines);
		handle_lines(args, lines, command);
		if (commands != NULL)
			free(commands);
	}
	exit(get_status(0, 0));
}
