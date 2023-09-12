#include "shell.h"



/**
 * _getline - func reads input from stream
 * @lptr: buffer that stores the words
 * @n: size of lptr
 * @stream: stream to read from
 * Return: The number of bytes
 */

ssize_t _getline(char **lptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t word;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (word == 0)
		fflush(stream);
	else
		return (-1);
	word = 0;

	buffer = malloc(sizeof(char) * BUFSZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && word == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && word != 0)
		{
			word++;
			break;
		}
		if (word >= BUFSZE)
			buffer = _realloc(buffer, word, word + 1);
			/* buffer = realloc(buffer, word, word + 1);*/
		buffer[word] = t;
		word++;
	}
	buffer[word] = '\0';
	var_line(lptr, n, buffer, word);
	retval = word;
	if (i != 0)
		word = 0;
	return (retval);
}
