#include "main.h"

/**
 * _strcmp - compare two stings
 * @str1: First string
 * @str2: Second string
 *
 * Description: Simple string comparison
 * Return: 1 for true and 0 for false.
 */
int _strcmp(char *str1, char *str2)
{
	int sl1 = 0, sl2 = 0;

	while (str1[sl1])
		sl1++;

	while (str2[sl2])
		sl2++;

	if (sl1 != sl2)
		return (0);

	sl1 = 0;
	while (str1[sl1] == str2[sl1] && str1[sl1])
		sl1++;

	if (sl1 == sl2)
		return (1);

	return (0);
}

/**
 * _strcpy - copies one string into another
 * @str1: First string, copied into
 * @str2: Second string, copied from
 * @s: Integer size of first strings memory in bytes.
 *
 * Description: People copy string with equals. C is ridiculous
 * Return: 1 if the copy succeeded or 0 if it failed.
 */
int _strcpy(char **str1, char *str2, unsigned int s)
{
	unsigned int i = 0, j = 0;

	while (str2[j])
		j++;

	if (j > s)
	{
		free(*str1);
		*str1 = malloc(sizeof(char) * j);
	}

	while (str2[i])
	{
		(*str1)[i] = str2[i];
		i++;
	}
	(*str1)[i] = '\0';

	return (_strcmp((*str1), str2));
}

/**
 * _strcln - Removes terminating newline characters
 * @str: Pointer to string to be cleaned
 *
 * Description: Removes the \n at the end of getline results
 * Return: The string less the newline character.
 */
void _strcln(char **str)
{
	int i = 0;
	char *str_c = *str;

	while (str_c[i] != '\n')
	i++;

	str_c[i] = '\0';
}

/**
 * _strcat - joins strings
 * @s1: First string
 * @s2: Second string
 *
 * Description: Joins two strings
 * Return: A poiter to the new joined string.
 */
char *_strcat(char *s1, char *s2)
{
	char *join;
	unsigned int i, j;

	i = 0;
	while (s1 && s1[i])
		i++;

	j = 0;
	while (s2 && s2[j])
		j++;
	i += j;
	i++;
	join = malloc(sizeof(char) * i);

	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}

	j = 0;
	while (s2 && s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	i += j;
	i++;
	join[i] = '\0';
	return (join);
}

/**
 * _strlen - Counts string length
 * @str: String to check
 *
 * Description: Iteratively count characters
 * Return: Length of the string.
 */
unsigned int _strlen(char *str)
{
	unsigned int i = 0;

	if (str)
	{
	while (str[i])
		i++;
	}
	return (i);
}
