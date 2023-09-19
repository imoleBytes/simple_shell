#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "shell.h"
/**
 * getVariable - function replaces variables
 * @args: array
 * @var: variablename
 * @i: array index number
 * Return: 1 or 0
 */
int getVariable(char **args, char *var, int i)
{
	char **env = environ;
	char *value;

	if (*var == '$' && _strlen(var) == 1)
	{
		/*write(STDERR_FILENO, "./hsh: 1: $: not found\n", 23);*/
		/*get_status(2, 2);*/
		args[i] = var;
		return (1);
	}
	for (; *env != NULL; env++)
	{
		if (strstr(*env, var + 1) == *env)
		{
			value = strchr(*env, '=');
			if (value != NULL)
			{
				args[i] = value + 1;
				return (1);
			}
		}
	}
	if (compare(var, "$$") || compare(var, "$?"))
	{
		args[i] = var;
		return (1);
	}
	if (*var == '$' && _strlen(var) > 1)
	{
		args[i] = "abdi";
		return (0);
	}
	args[i] = var;
	return (1);
}
