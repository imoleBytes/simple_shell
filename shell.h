#ifndef _shell_h
#define _shell_h


#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
void string_f(char *dst, int argc, ...);
void string_digit(int d, char *bf2);
void _concat(char *bf, char *str1, int  n);
int path(char **);
void displayPrompt(void);
int checkin_path(char *buff, char *str);


#endif
