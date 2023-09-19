#include "shell.h"
/**
 * check_empty - function name
 * @str1: string to  check
 * Return: int
 */
int check_empty(char *str1)
{
	char *str = str1;

	if (str1 == NULL)
		return (1);
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\n')
		{
			return (1);
		}
		str++;
	}
	return (0);
}
