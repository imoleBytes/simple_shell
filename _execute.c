#include "shell.h"

void __execute(char *fullpath, char **args)
{
	pid_t pid;
	int waitstatus;

	pid = fork();
	if (pid == 0) /*child process*/
		execve(fullpath, args, environ);
	if (pid == -1)
		exit(EXIT_FAILURE);
	/* parent process*/
	/*wait(NULL);*/	
	waitpid(pid, &waitstatus, 0);
}
