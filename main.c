#include "shell.h"

char *program_name(char *str)
{
	static char *program = NULL;

	if (program == NULL)
		program = str;
	return (program);
}
void comand_tokenize(char *command, char **args)
{
	int i = 0;
	char *token;

	token = strtok((char *)command, " ");

	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
}

int main(int argc, char *argv[])
{

	char *command = NULL;
	size_t max_command_size = 0;
	ssize_t actual_command_size;
	pid_t pid;
	/* int waitstatus;   not used*/
	bool from_pipe = false;
	char *args[20]; /*maximum 20 arguments*/


	(void) argc;
	program_name(argv[0]);
	while (!from_pipe && 1)
	{
		/*ths is to check if command is piped into our program*/
		if (isatty(STDIN_FILENO) == 0)
			from_pipe = true;
		else
			displayPrompt();
		actual_command_size = getline(&command, &max_command_size, stdin);

		command[actual_command_size - 1] = '\0';

		/*this to fix the bug not empty command not looping*/
		if (strcmp(command, "") == 0)
			continue;

		/*
		* if (strcmp(command, "exit") == 0)
		*	return (0);
		*/

		if (strcmp(command, "exit") == 0)
			exit(EXIT_SUCCESS);

		comand_tokenize(command, args);
		/* char *str = args[0];*/
		if (!path(args))
		{
			pid = fork();
			if (pid == 0)
				execve(args[0], args, environ);
			if (pid == -1)
				exit(EXIT_FAILURE);
			wait(NULL);
			/* waitpid(pid, &waitstatus, 0);*/
		}
	}

	return (0);
}
