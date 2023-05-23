#include "shell.h"

/**
 **_strncpy - copies a string
 *@dgst: the destination string to be copied to
 *@surc: the source string
 *@nun: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dgst, char *surc, int nun)
{
	int i, j;
	char *s = dgst;

	i = 0;
	while (surc[i] != '\0' && i < nun - 1)
	{
		dgst[i] = surc[i];
		i++;
	}
	if (i < nun)
	{
		j = i;
		while (j < nun)
		{
			dgst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dgst: the first string
 *@surc: the second string
 *@nun: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dgst, char *surc, int nun)
{
	int i, j;
	char *s = dgst;

	i = 0;
	j = 0;
	while (dgst[i] != '\0')
		i++;
	while (surc[j] != '\0' && j < nun)
	{
		dgst[i] = surc[j];
		i++;
		j++;
	}
	if (j < nun)
		dgst[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@sos: the string to be parsed
 *@cue: the character to look for
 *Return: (sos) a pointer to the memory area sos
 */
char *_strchr(char *sos, char cue)
{
	do {
		if (*sos == cue)
			return (sos);
	} while (*sos++ != '\0');

	return (NULL);
}
