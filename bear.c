#include "shell.h"

/**
 * _myenv - prints the current environment
 * @test: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: dima 0
 */
int _myenv(info_t *test)
{
	print_list_str(test->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @test: Structure containing potential arguments. Used to maintain
 * @ism: env var name
 *
 * Return: la valuer deyal dikchi li bghina 
 */
char *_getenv(info_t *test, const char *ism)
{
	list_t *nodejs = test->env;
	char *par;

	while (nodejs)
	{
		par = starts_with(nodejs->str, ism);
		if (par && *par)
			return (par);
		nodejs = nodejs->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @test: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: dima 0
 */
int _mysetenv(info_t *test)
{
	if (test->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(test, test->argv[1], test->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @test: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: dima 0
 */
int _myunsetenv(info_t *test)
{
	int i;

	if (test->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= test->argc; i++)
		_unsetenv(test, test->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @test: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: dima 0
 */
int populate_env_list(info_t *test)
{
	list_t *nodejs = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&nodejs, environ[i], 0);
	test->env = nodejs;
	return (0);
}
