#include "shell.h"
#include <stdio.h>
/**
 * cd_handle - function for cas cd
 * @str: str
 * @buff: buffer string
 */
void cd_handle(char *str, char *buff)
{

	static char last_dir[1024];

	if (str != NULL)
		_concat(last_dir, str, 0);
	else
		_concat(buff, last_dir, 0);
}
/**
 * change_dir - function chnages directory
 * @args: argument passed
 */
void change_dir(char **args)
{
		char *path = args[1] == NULL ? getenv("HOME") : args[1];
		char err[1000], temp[1000], *pr, actual[1024];

		cd_handle(NULL, actual);
		getcwd(temp, 1000);
		if (compare(path, "-") && actual != NULL)
		{
			path = actual;
		}
		if (chdir(path) == 0)
		{
			cd_handle(temp, NULL);
			get_status(0, 1);
		}
		else
		{
			pr = program_name(NULL);
			string_f(err, 6, pr, ": 1: ", args[0], ":  can't cd to ", args[1], "\n");
			write(STDERR_FILENO, err, _strlen(err));
			get_status(2, 2);
		}
}
