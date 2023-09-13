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
	else
	{
		waitpid(pid, &waitstatus, 0);
		if (WIFEXITED(waitstatus))
		{
			int status = (waitstatus > 0) ? 2 : waitstatus;
			get_status(status, 2);
		}
	}
}
