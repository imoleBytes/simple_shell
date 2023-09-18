#include "shell.h"



/**
* _strdup - func to create a block of memmory and fill it with string
* @str: array size
* Return: a pointer to array
*/

char *_strdup(char *str)
{
	char *array;
	int i = 0;
	int count = 0;

	if (str == NULL)
		return (NULL);

	while (str[count] != '\0')
	{
		count++;
	}
	count++;

	array = malloc(sizeof(*str) * count);

	if (array != NULL)
	{
		for (i = 0; i < count; i++)
		{
			array[i] = str[i];
		}

		return (array);
	}

	return (NULL);
}
