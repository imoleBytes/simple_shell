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
* tokenize_lines - function name.
* @str1: the string to tokenize
* @lines: array stores lines of commands
* Return: 0 all time
*/
int tokenize_lines(char *str1, char **lines)
{
	char *str = str1;
	char *str_copy;
	char *token;
	char *dl = ";";
	int i = 0;

	if (*str == '#')
	{
		lines[0] = NULL;
		return (0);
	}
	str_copy = _strdup(str);
	getlines(str, &dl);
	token = my_strtok(str_copy, dl);
	while (token != NULL)
	{
		str = str + _strlen(token) + 1;
		lines[i] = _strdup(token);
		getlines(str, &dl);
		token = my_strtok(NULL, dl);
		i++;
	}
	free(str_copy);
	lines[i] = NULL;
	return (0);
}
