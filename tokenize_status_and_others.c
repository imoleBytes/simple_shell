#include <stdio.h>
#include "shell.h"
/**
 * get_status - reads the status of program
 * @new_status: new status int
 * @flag: that checks if status will be updated
 * Return: status
 */

int get_status(int new_status, int flag)
{
	static int status;

	if (flag)
		status = new_status;
	return (status);
}
/**
 * program_name - function catches program name
 * @str: name of the program or NULL
 * Return: the name
 */
char *program_name(char *str)
{
	static char *program;;

	if (program == NULL)
		program = str;
	return (program);
}
/**
 * comand_tokenize - function seprates words
 * @command: input string
 * @args: array stores arguments
 */
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
