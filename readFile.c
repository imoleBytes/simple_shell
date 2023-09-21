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
	char err[1024], *pr;

	if (filename == NULL || *filename == '\0')
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		pr = program_name(NULL);
		_concat(err, pr, 0);
		_concat(err, ": 0: Can't open ", _strlen(err));
		_concat(err, filename, _strlen(err));
		_concat(err, "\n", _strlen(err));
		write(STDERR_FILENO, err, _strlen(err));
		close(fd);
		exit(127);
	}
	bytes = read(fd, buff, 1024);
	if (bytes ==  -1)
	{
		pr = program_name(NULL);
		_concat(err, pr, 0);
		_concat(err, ": 0: Can't read ", _strlen(err));
		_concat(err, filename, _strlen(err));
		_concat(err, "\n", _strlen(err));
		write(STDERR_FILENO, err, _strlen(err));
		close(fd);
		exit(2);
	}
	if (bytes == 0)
	{
		close(fd);
		exit(0);
	}
	buff[bytes] = '\0';
	*comand = _strdup(buff);
	return (_strlen(*comand));
}
