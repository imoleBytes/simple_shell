#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * compare - function compares two string
 * @s1: the first string
 * @s2: the second string
 * Return: 1 if same string
 */
int compare(char *s1, char *s2)
{
        if (s1 == NULL)
                return (0);
        while (*s1 != '\0' && *s2 != '\0')
        {
                if (*s1 != *s2)
                        return (0);
                s1++;
                s2++;
        }
        if (*s1 == '\0' && *s2 == '\0')
                return (1);
        return (0);
}

int path(char **args)
{

        char path[1024], fullpath[10024];
        FILE *fp;

        if (compare(args[0], "exit"))
		return (0);
	if (access(args[0], X_OK) == 0)
		return (0);
	if(!checkin_path(fullpath, args[0]))
	{
		args[0] = fullpath;
		return (0);
	}
	return (2);
}
