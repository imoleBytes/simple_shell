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
        path[0] = '\0';
        string_f(path, 2, "which ", args[0]);
        fp  = popen(path, "r");
        if (fp == NULL)
		return (2);
        if (fgets(fullpath, sizeof(fullpath), fp) != NULL)
        {
                fullpath[strcspn(fullpath, "\n")] = '\0';
                args[0] = fullpath;
                pclose(fp);
                return (0);
        }
        pclose(fp);
	return (2);
}
