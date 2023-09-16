#include "shell.h"

/**
* var_line - assigns the line var for get_line
* @lptr: buff that store the input str
* @buff: str that is been called to line
* @num: size of line
* @i: size of buff
*/
void var_line(char **lptr, size_t *num, char *buff, size_t i)
{

	if (*lptr == NULL)
	{
		if  (i > BUFSZE)
			*num = i;

		else
			*num = BUFSZE;
		*lptr = buff;
	}
	else if (*num < i)
	{
		if (i > BUFSZE)
			*num = i;
		else
			*num = BUFSZE;
		*lptr = buff;
	}
	else
	{
		/* _strcpy(*lptr, buff);*/
		str_cpy(*lptr, buff);
		free(buff);
	}
}
