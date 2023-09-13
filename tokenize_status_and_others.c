#include <stdio.h>
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
