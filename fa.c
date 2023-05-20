#include "shell.h"

/**
 * _myexit - exits the shell
 * @tach: yalah ghadi ne3erfha heta deyal ach .
 *  Return: lmhm tekheerej lik mn dik lblan we sf 
 */




int _myexit(tach_t *tach)
{
	int testexit;

	if (tach->argv[1])  /* hadi ila kan chi arg bach nkharjo  */
	{
		testexit = _erratoi(tach->argv[1]);
		if (testexit == -1)
		{
			tach->status = 2;
			print_error(tach, "Illegal number: ");
			_eputs(tach->argv[1]);
			_eputchar('\n');
			return (1);
		}
		tach->err_num = _erratoi(tach->argv[1]);
		return (-2);
	}
	tach->err_num = -1;
	return (-2);
}

/**
 * _myhelp - changes the current directory of the process
 * @tach: gha chi haja ghadi tendam eliha mn ba3ed we sf
 *  Return: dima ghadi tkherej b 0
 */



int _myhelp(info_t *tach)
{
	char **arg_list;

	arg_list = tach->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_list);
	return (0);
}

/**
 * _mycd - katbadel dic li kayen ela wed hadak li bghina
 * @tach: function prototype dima tabta bach maykonch fiha chi haja oukhera
 *  Return: dima atkherej b zero 
 */
int _mycd(info_t *tach)
{
	char *sos, *rid, buffer[1024];
	int chrid_ret;

	sos = getcwd(buffer, 1024);
	if (!sos)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!tach->argv[1])
	{
		rid = _getenv(tach, "HOME=");
		if (!rid)
			chrid_ret = /* TODO: what should this be? */
				chrid((rid = _getenv(tach, "PWD=")) ? rid : "/");
		else
			chrid_ret = chrid(rid);
	}
	else if (_strcmp(tach->argv[1], "-") == 0)
	{
		if (!_getenv(tach, "OLDPWD="))
		{
			_puts(sos);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(tach, "OLDPWD=")), _putchar('\n');
		chrid_ret = /* TODO: what should this be? */
			chrid((rid = _getenv(tach, "OLDPWD=")) ? rid : "/");
	}
	else
		chrid_ret = chrid(tach->argv[1]);
	if (chrid_ret == -1)
	{
		print_error(tach, "can't cd to ");
		_eputs(tach->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(tach, "OLDPWD", _getenv(tach, "PWD="));
		_setenv(tach, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
