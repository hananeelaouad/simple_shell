#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @sick: the string to be converted
 * Return: 0ila kan number string , converted number otherwise
 *       -1 ila kan ghalat 
 */
int _erratoi(char *sick)
{
	int inter = 0;
	unsigned long int rezulta = 0;

	if (*sick == '+')
		sick++; 
	for (inter = 0;  sick[inter] != '\0'; inter++)
	{
		if (sick[inter] >= '0' && sick[inter] <= '9')
		{
			rezulta *= 10;
			rezulta += (sick[inter] - '0');
			if (rezulta > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rezulta);
}

/**
 * print_error - prints an error message
 * @maaloma: the parameter & return info struct
 * @ucl: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *maaloma, char *ucl)
{
	_eputs(maaloma->fname);
	_eputs(": ");
	print_d(maaloma->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(maaloma->argv[0]);
	_eputs(": ");
	_eputs(ucl);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @value: the input
 * @uel: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int value, int uel)
{
	int (*__putchar)(char) = _putchar;
	int roma, sev = 0;
	unsigned int _abs_, current;

	if (uel == STDERR_FILENO)
		__putchar = _eputchar;
	if (value < 0)
	{
		_abs_ = -input;
		__putchar('-');
		sev++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (roma = 1000000000; roma > 1; roma /= 10)
	{
		if (_abs_ / roma)
		{
			__putchar('0' + current / roma);
			sev++;
		}
		current %= i;
	}
	__putchar('0' + current);
	sev++;

	return (sev);
}

/**
 * convert_number - converter function, a clone of itoa
 * @nemra: ra9em
 * @rma: 9a3ida
 * @raya: argument flags
 *
 * Return: string
 */
char *convert_number(long int nemra, int rma, int raya)
{
	static char *list;
	static char bff[50];
	char alama = 0;
	char *prot;
	unsigned long non = nemra;

	if (!(raya & CONVERT_UNSIGNED) && nemra < 0)
	{
		non = -nemra;
		alama = '-';

	}
	list = raya & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	prot = &bff[49];
	*prot = '\0';

	do	{
		*--prot = list[n % rma];
		non /= rma;
	} while (non != 0);

	if (alama)
		*--prot = alama;
	return (prot);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buffalo)
{
	int i;

	for (i = 0; buffalo[i] != '\0'; i++)
		if (buffalo[i] == '#' && (!i || buffalo[i - 1] == ' '))
		{
			buffalo[i] = '\0';
			break;
		}
}
