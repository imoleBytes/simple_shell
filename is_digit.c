#include "shell.h"
#include <stdio.h>
/**
 * is_digit - function checks if string is digit
 * @str: string as paramater
 * Return: the digit in string or 2 if all not digit
 */
int is_digit(char *str)
{
	char result, flag = 1;
	char *pr = program_name(NULL);
	char err[1000];

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
		{
			_concat(err, pr, 0);
			_concat(err, ": 1: exit: Illegal number: ", _strlen(err));
			_concat(err, str, _strlen(err));
			_concat(err, "\n", _strlen(err));
			write(STDERR_FILENO, err, _strlen(err));
			return (2);
		}
		str++;
	}
	return (result * flag);
}
