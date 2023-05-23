#include "shell.h"

/**
 *_eputs - prints an input string
 * @storz: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *storz)
{
	int i = 0;

	if (!storz)
		return;
	while (storz[i] != '\0')
	{
		_eputchar(storz[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @cur: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char cur)
{
	static int i;
	static char bu[WRITE_BUF_SIZE];

	if (cur == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, bu, i);
		i = 0;
	}
	if (cur != BUF_FLUSH)
		bu[i++] = cur;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @mac: The character to print
 * @bet: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char mac, int bet)
{
	static int i;
	static char bu[WRITE_BUF_SIZE];

	if (mac == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(bet, bu, i);
		i = 0;
	}
	if (mac != BUF_FLUSH)
		bu[i++] = mac;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @storz: the string to be printed
 * @bet: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *storz, int bet)
{
	int i = 0;

	if (!storz)
		return (0);
	while (*storz)
	{
		i += _putfd(*storz++, bet);
	}
	return (i);
}
