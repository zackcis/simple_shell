#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * _putchar - Don't delete _putchar, its used for testing
 * @c: character to be printed
 *
 * Description: It doesn't affect compilation or checker testing but will crash
 * the ALX tool tester if removed.
 * Return: 0 (Success) or 1 (Failure).
 */
int _putchar(char c);
int _strcmp(char *str1, char *str2);
int _strcpy(char **str1, char *str2, unsigned int s);
void _strcln(char **str);
void shell(char **env, char **av);
char *to_exe(char *cmd);
void _realloc(char ***cmd_a, size_t *n);
void _exec(char *cmd, char *temp, char **cmd_a, size_t n, int c,
char **env, char **av);
void builtin_env(char **env);
char *_strcat(char *s1, char *s2);
unsigned int _strlen(char *str);
#endif
