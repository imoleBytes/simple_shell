#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * @args: array of comands
 */
void print_error(char **args)
{
	int i = 0;
	char *program = program_name(NULL), buff[1024], digit[100];

	while (args[i])
		i++;

	string_digit(i, digit);
	string_f(buff, 6, program, ": ", digit, ": ",  args[0], ": not found\n");
	write(STDERR_FILENO, buff, strlen(buff));
}
