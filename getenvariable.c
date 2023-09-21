#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "shell.h"


/**
* digit - function checks if string is digit
* @str: string as paramater
* Return: the digit in string or 0 if all not digit
*/
int digit(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

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

	if (digit(var) || compare(var, "-"))
	{
		args[i] = var;
		return (1);
	}
	if (compare(var, "$$") || compare(var, "$?"))
	{
		args[i] = var;
		return (1);
	}

	if (*var == '$' && _strlen(var) == 1)
	{
		/*write(STDERR_FILENO, "./hsh: 1: $: not found\n", 23);*/
		/*get_status(2, 2);*/
		args[i] = var;
		return (1);
	}
	if (*var == '$')
	{
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
		args[i] = NULL;
		return (0);
	}
	args[i] = var;
	return (1);
}
