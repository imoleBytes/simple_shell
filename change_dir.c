#include "shell.h"
#include <stdio.h>

void cd_handle(char *str, char *buff)
{
	
	static char last_dir[1024];

	if (str != NULL)
		_concat(last_dir, str, 0);
	else
		_concat(buff, last_dir, 0);
}

void change_dir(char **args)
{
        char *path = args[1] == NULL ? getenv("HOME") : args[1];
        char errorm[1000], temp[1000], *program, actual[1024];

        cd_handle(NULL, actual);
        getcwd(temp, 1000);
        if (compare(path, "-") && actual != NULL)
        {
                path = actual;
        }
        if (chdir(path) == 0)
        {
                cd_handle(temp, NULL);
                get_status(0,1);
        }
        else
        {
		program = program_name(NULL);
                string_f(errorm, 5, program, ": 1: ", args[0], ":  can't cd to ", args[1]);
                write(STDERR_FILENO, errorm, _strlen(errorm));
		get_status(2, 2);
        }
}
