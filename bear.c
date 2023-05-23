#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @tach: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *tach)
{
	return (isatty(STDIN_FILENO) && tach->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ci: the char to check
 * @deliman: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char ci, char *deliman)
{
	while (*deliman)
		if (*deliman++ == ci)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@cio: The character to input
 *Return: 1 if cio is alphabetic, 0 otherwise
 */

int _isalpha(int cio)
{
	if ((cio >= 'a' && cio <= 'z') || (cio >= 'A' && cio <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@ese: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *ese)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  ese[i] != '\0' && flag != 2; i++)
	{
		if (ese[i] == '-')
			sign *= -1;

		if (ese[i] >= '0' && ese[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (ese[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

