#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * compare - function compares two string
 * @s1: the first string
 * @s2: the second string
 * Return: 1 if same string
 */
int compare(char *s1, char *s2)
{
	if (s1 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}
/**
 * path - function handles path case
 * @args: array of comands
 * @fullpath: path
 * Return: int 0 for success
 */
int path(char **args, char *fullpath)
{
	if (compare(args[0], "exit"))
		return (0);
	if (access(args[0], X_OK) == 0)
	{
		_concat(fullpath, args[0], 0);
		return (0);
	}
	if (!checkin_path(fullpath, args[0], "PATH="))
	{
		return (0);
	}
	print_error(args);
	get_status(127, 2);
	return (2);
}
/* strncmp will be chanaged */
/**
 * checkin_path - function gets path
 * @buff: destination to save the full path
 * @str: the comand to look for
 * Return: 0 if found 1 if not found
 */
int checkin_path(char *buff, char *str, char *variable)
{
	int i;
	char *token, *path;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], variable, 5) == 0)
		{
			path = strdup(environ[i] + 5);
			token = my_strtok(path, ":");
			while (token != NULL)
			{
				char fullpath[1000] = "";

				_concat(fullpath, token, 0);
				_concat(fullpath, "/", strlen(fullpath));
				_concat(fullpath, str, strlen(fullpath));

				if (access(fullpath, X_OK) == 0)
				{
					_concat(buff, fullpath, 0);
					free(path);
					return (0);
				}
				token = my_strtok(NULL, ":");
			}
			free(path);
			break;
		}

	}
	return (1);
}
