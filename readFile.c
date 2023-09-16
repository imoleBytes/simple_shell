#include "shell.h"


/**
 * readFile - function reads file
 * @filename: string
 * @comand: string
 * Return: int
 */
int readFile(char *filename, char **comand)
{
	int fd;
	char buff[10024];
	ssize_t  bytes;

	if (filename == NULL || *filename == '\0')
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	bytes = read(fd, buff, 1024);
	if (bytes == -1)
	{
		close(fd);
		return (0);
	}
	buff[bytes] = '\0';
	*comand = strdup(buff);
	return (_strlen(*comand));
}
