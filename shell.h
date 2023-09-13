#ifndef _shell_h
#define _shell_h

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFSZE 1024

extern char **environ;
void change_dir(char **args);
int get_status(int new_status, int flag);
void comand_tokenize(char *command, char **args);
void string_f(char *dst, int argc, ...);
void string_digit(int d, char *bf2);
void _concat(char *bf, char *str1, int  n);
int path(char **, char *);
void displayPrompt(void);
int checkin_path(char *buff, char *str);
void print_error(char **args);
char *program_name(char *);
int get_status(int, int);
char *my_strtok(char *, char *);
int _strlen(char *);
int is_digit(char *);
int compare(char *, char *);

void __execute(char *fullpath, char **args);
char *intToStr(char *a, int num, int base, int upper);
int __putc(char c);
ssize_t _getline(char **lptr, size_t *n, FILE *stream);
void var_line(char **lptr, size_t *n, char *buffer, size_t j);
void *_realloc(void *ptr, unsigned int old, unsigned int newp);
void mem_cpy(void *newptr, const void *ptr, unsigned int size);
char *str_cpy(char *dest, char *src);
int readFile(char *filename, char **comand);




#endif
