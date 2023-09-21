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
	static char *program;

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
		{
			args[i] = NULL;
			return;
		}
		if (getVariable(args, token, i))
		{
			i++;
			token = my_strtok(NULL, " ");
		}
		else
			break;
	}
	args[i] = NULL;
}

/**
 * process - function helps main
 *@args: array of commands
 *@command: comand input
 *@orginal_command: to free incase
 */
void process(char **args, char *command, char *orginal_command)
{
	char fullpath[10024];

	comand_tokenize(command, args);
	fullpath[0] = '\0';
	if (compare(args[0], "exit"))
	{
		if (args[1] != NULL)
			get_status(is_digit(args[1]), 2);
		(void)orginal_command;
		free(command);
		exit(get_status(0, 0));
	}
	if (!other_commands(args) && !path(args, fullpath))
		__execute(fullpath, args);
}
