#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_error - function prints error
 * @args: array of comands
 */
void print_error(char **args)
{
	int i = 0;
	char *program = program_name(NULL), buff[1024], digit[100];

	while (args[i])
		i++;

	string_digit(i, digit);
	_concat(buff, program, 0);
	_concat(buff, ": ", _strlen(buff));
	_concat(buff, digit, _strlen(buff));
	_concat(buff, ": ", _strlen(buff));
	_concat(buff, args[0], _strlen(buff));
	_concat(buff, ": not found\n", _strlen(buff));
	write(STDERR_FILENO, buff, strlen(buff));
}
