#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * getlines - function gets lines for cases ; && |
 * @command: the input
 * @dl: array that stores delemeter
 */
void getlines(char *command, char **dl)
{
	while (*command)
	{
		if (*command == '&')
		{
			*dl = "&";
			return;
		}
		else if (*command == ';')
		{
			*dl = ";";
			return;
		}
		else if (*command == '\n')
		{
			*dl = "\n";
			return;
		}
		else if (*command == '|')
		{
			*dl = "|";
			return;
		}
		command++;
	}
}
/**
 * tokenize_lines - function name
 * @str1: the string to tokenize
 * @lines: array stores lines of commands
 * Return: 0 all time
 */
int tokenize_lines(char *str1, char **lines)
{
	char *str = str1;
	char *str_copy = strdup(str);
	char *token;
	char *dl = ";";
	int i = 0;

	getlines(str, &dl);
	token = my_strtok(str_copy, dl);
	while (token != NULL)
	{
		str = str + strlen(token) + 1;
		lines[i] = strdup(token);
		getlines(str, &dl);
		token = my_strtok(NULL, dl);
		i++;
	}
	free(str_copy);
	lines[i] = NULL;
	return (0);
}

