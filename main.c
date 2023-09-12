#include "shell.h"

int get_status(int new_status, int flag)
{
	static int status = 0;
	if(flag)
		status = new_status;
	return (status);
}

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
	get_status(0, 0);
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

		

		comand_tokenize(command, args);
		/* char *str = args[0];*/
		
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
				exit(atoi(args[1]));
			exit(get_status(0, 0));
		}
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


