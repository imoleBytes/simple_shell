#include "shell.h"

int other_commands(char **args)
{
	pid_t pid;
	char intonum[100], digit[100];

	if (compare(args[0], "cd"))
	{
		/* direcory will be changed you can try pwd after changing it*/
		change_dir(args);
		return (1);
	}
	if (compare(args[0], "setenv") || compare(args[0], "unsetenv"))
	{
		printf("setenv and unset will be handled later\n");
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
		string_digit(get_status(0,0), digit);
		_concat(args[1], digit, 0);
		return (0);
	}
	return (0);
}


int main(int argc, char *argv[])
{

	char *command = NULL, fullpath[1024];
	size_t max_command_size = 0;
	ssize_t actual_command_size;
	/*
	*pid_t pid;
	*int waitstatus;
	*/
	bool from_pipe = false, flag = false;
	char *args[1024]; /*maximum 1024 arguments*/

	(void) argc;
	program_name(argv[0]);
	get_status(0, 0);
	while (!from_pipe && 1)
	{
		/*ths is to check if command is piped into our program*/
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		else
			displayPrompt();
		command = NULL;
		/* actual_command_size = getline(&command, &max_command_size, stdin);*/
		if (argc < 2)
			actual_command_size = _getline(&command, &max_command_size, stdin);
		else
		{
			actual_command_size = readFile(argv[1], &command);
			flag = true;
		}
		if (actual_command_size == -1)
		{
			get_status(2, 2);
			free(command);
			break;
		}
		command[actual_command_size - 1] = '\0';

		/*this to fix the bug not empty command not looping*/
		if (strcmp(command, "") == 0)
			continue;
		comand_tokenize(command, args);
		fullpath[0] = '\0';
		if (compare(args[0], "exit"))
		{
			if (args[1] != NULL)
				get_status(is_digit(args[1]), 2);
			free(command);
			exit(get_status(0, 0));
		}
		
		if (!other_commands(args) && !path(args, fullpath))
			__execute(fullpath, args);
		if (command != NULL)
			free(command);
		/* if file passed stop loop */
		if (flag)
			break;
	}

	return (0);
}
