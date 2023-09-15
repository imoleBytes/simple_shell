#include "shell.h"


/**
 * __putc - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int __putc(char c)
{
	write(1, &c, 1);
	return (0);
}
