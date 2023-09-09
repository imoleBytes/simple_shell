#include "shell.h"


int main(int argc, char *argv[])
{
	
	char *command = NULL;
	size_t max_command_size = 0;
	ssize_t actual_command_size;
	pid_t pid;
	int waitstatus;
	
	while (1)
	{
		displayPrompt();
		actual_command_size = getline(&command, &max_command_size, stdin);
		// printf("%lu\n", bytes);
		command[actual_command_size - 1] = '\0';
		// printf("%s\n", command);

		char *const ar[] = {command, NULL};
		if (strcmp(command, "exit") == 0)
			return (0);

		pid = fork();

		if (pid == 0)
			execve(ar[0], ar, NULL);					
		waitpid(pid, &waitstatus, 0);

	}

	return (0);
}
