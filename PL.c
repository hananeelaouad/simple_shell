#include "shell.h"

/**
 *_eputs - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_eputchar(string[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @cry: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char cry)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (cry == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (cry != BUF_FLUSH)
		buf[i++] = cry;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @manc: The character to print
 * @fddoc: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char manc, int fddoc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (manc == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fddoc, buf, i);
		i = 0;
	}
	if (manc != BUF_FLUSH)
		buf[i++] = manc;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @livr: the string to be printed
 * @evr: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *livr, int evr)
{
	int i = 0;

	if (!livr)
		return (0);
	while (*livr)
	{
		i += _putfd(*livr++, evr);
	}
	return (i);
}
