#include <stdarg.h>
#include <stdio.h>
/**
 *  _strlen - function name
 * @s: string
 * Return: len of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

/**
 * _concat - function concerated two strings
 * @bf: buffer destination
 * @str1: string that will be concated
 * @n: size of the previous string in the buffer
 */
void _concat(char *bf, char *str1, int  n)
{
	if (str1 == NULL)
		return;
	while (*str1 != '\0')
	{
		*(bf + n) = *str1;
		str1++;
		n++;
	}
	bf[n] = '\0';
}

/**
 * string_digit - fuction converst int to digit
 * @d: int number
 * @bf2: buffer or string
 */
void string_digit(int d, char *bf2)
{
	int i = 0, n = 0;
	char bf[10024];

	while (d > 9)
	{
		bf[i++] = '0' + (d % 10);
		d = d / 10;
	}
	bf[i] = d + '0';

	for (; i >= 0; i--)
		bf2[n++] = bf[i];
	bf2[n++] = '\0';
}
/**
 * string_f - function formats string
 * @dst: the destination buffer
 * @argc: number of arguments
 */
void string_f(char *dst, int argc, ...)
{
	int i = 0;
	char *str;
	va_list list;

	va_start(list, argc);
	while (i < argc)
	{
		str = va_arg(list, char *);
		_concat(dst, str, _strlen(dst));
		i++;
	}
	va_end(list);
}
