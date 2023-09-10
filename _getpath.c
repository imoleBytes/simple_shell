#include <stdio.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>
/* strncmp will be chanaged */

int checkin_path(char *buff, char *str)
{
	
	int i;
	char *token, *path;

	for(i = 0; environ[i] != NULL; i++)
	{
		 if (strncmp(environ[i], "PATH=", 5) == 0)
		 {
			 path = environ[i] + 5;
			 token = strtok(path, ":");
			 while (token != NULL)
			 {
				 char fullpath[1000] = "";
				 _concat(fullpath, token, 0);
				 _concat(fullpath, "/", strlen(fullpath));
				 _concat(fullpath, str,strlen(fullpath));
				 if (access(fullpath, X_OK) == 0)
				 {
					 _concat(buff, fullpath, 0);
					 return (0);
				 }
				 token = strtok(NULL, ":");
			 }
		 }
	
	}
	return (1);
}

