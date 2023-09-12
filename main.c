#include "shell.h"



int other_commands(char **args)
{
	pid_t pid;

	if (compare(args[0], "cd"))
	{
		printf("CD will be handled later\n");
		return (1);
	}
	if (compare(args[0], "setenv") || compare(args[0], "unsetenv"))
	{
		printf("setenv and unset will be handled later\n");
		return (1);
	}
	if (compare(args[0], "echo") && compare(args[1], "$$"))
	{
		/* printf("$$ is not ready yet\n");*/
		pid = getpid();
		printf("%u\n", pid); /*to be replaced with write later*/
		return (1);
	}
	if (compare(args[0], "echo") && compare(args[1], "$?"))
	{
		printf("$? is not ready yet\n");
		return (1);
	}
	return (0);
}

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

	token = my_strtok((char *)command, " ");

	while (token != NULL)
	{
		/* check if argument is # or starts at #*/
		if (compare(token, "#") || *token == '#')
			break;
		args[i] = token;
		token = my_strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
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
	bool from_pipe = false;
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
		actual_command_size = getline(&command, &max_command_size, stdin);
		if (actual_command_size == -1)
		{
			free(command);
			break;
		}
		command[actual_command_size - 1] = '\0';

		/*this to fix the bug not empty command not looping*/
		if (strcmp(command, "") == 0)
			continue;

		comand_tokenize(command, args);
		fullpath[0] = '\0';
		
		if (strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
				get_status(is_digit(args[1]), 2);
			exit(get_status(0, 0));
		}
		/** handle cases like $$ $? cd etc */
		if (other_commands(args))
		{
			free(command);
			continue;
		}
		if (!path(args, fullpath))
		{
			/*
			* pid = fork();
			* if (pid == 0)
			*	execve(fullpath, args, environ);
			* if (pid == -1)
			*	exit(EXIT_FAILURE);
			* //wait(NULL);
			* waitpid(pid, &waitstatus, 0);
			*/
			__execute(fullpath, args);
		}
		if (command != NULL)
			free(command);
	}

	return (0);
}
