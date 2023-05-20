#include "shell.h"

/**
 **_strncpy - copies a string
 *@tazeko: the destination string to be copied to
 *@source: the source string
 *@nice: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *tazeko, char *source, int nice)
{
	int i, j;
	char *s = tazeko;

	i = 0;
	while (source[i] != '\0' && i < n - 1)
	{
		tazeko[i] = source[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			tazeko[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@tazeko: the first string
 *@source: the second string
 *@nice: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *tazeko, char *source, int nice)
{
	int i, j;
	char *s = tazeko;

	i = 0;
	j = 0;
	while (tazeko[i] != '\0')
		i++;
	while (source[j] != '\0' && j < n)
	{
		tazeko[i] = source[j];
		i++;
		j++;
	}
	if (j < n)
		tazeko[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@sick: the string to be parsed
 *@clear: the character to look for
 *Return: (sick) a pointer to the memory area s
 */
char *_strchr(char *sick, char clear)
{
	do {
		if (*sick == clear)
			return (sick);
	} while (*sick++ != '\0');

	return (NULL);
}
