#include "shell.h"



/**
* _getline - This func reads input from the given stream
* @lptr: this is a buffer that stores the words
* @n: size of value in the buffer (lptr)
* @stream: the stream to read from, (stdin)
* Return: The number of bytes
*/

ssize_t _getline(char **lptr, size_t *n, FILE *stream)
{
	static ssize_t word;
	int i;
	char *buffer, t = 'z';
	ssize_t num_bytes;

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
		if ((i == 0 && word == 0) || i == -1)
		{
			free(buffer);
			return (-1);
		}
		if (word != 0 && i == 0)
		{
			word++;
			break;
		}
		if (word >= BUFSZE)
			buffer = _re_alloc(buffer, word + 1, word);
		buffer[word] = t;
		word++;
	}

	buffer[word] = '\0';
	var_line(lptr, n, buffer, word);
	num_bytes = word;

	if (i != 0)
		word = 0;
	return (num_bytes);
}
