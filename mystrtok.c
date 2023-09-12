#include <stdio.h>
#include <string.h>

char *my_strtok(char *orginal, const char *delimiters)
{
	static char *cp;
	char *token;

	if (orginal != NULL)
		cp = orginal;
	if (cp == NULL || *cp == '\0')
		return (NULL);
	while (*cp != '\0' && strchr(delimiters, *cp) != NULL)
	{
		cp++;
	}
	if (*cp == '\0')
		return (NULL);
	token = cp;
	while (*cp != '\0' && strchr(delimiters, *cp) == NULL)
	{
		cp++;
	}

	if (*cp != '\0')
	{
		*cp = '\0';
		cp++;
	}
	return (token);
}

