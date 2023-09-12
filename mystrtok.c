#include <stdio.h>

char *my_strtok(char *str, char *dl)
{
	static char *str_copy;
	static char token[1024];
	int n = 0;

	if (str != NULL)
		str_copy = str;
	while (*str_copy != '\0')
	{
		if (*str_copy == *dl)
		{
			str_copy++;
			token[n++] = '\0';
			return token;
		}
		token[n++] = *str_copy;
		str_copy++;
	}
	if (n > 0) {
		token[n] = '\0';
		return token;
	}
	return (NULL);
}
