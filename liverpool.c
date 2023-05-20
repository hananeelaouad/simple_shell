#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @maaloma: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *maaloma)
{
	print_list(maaloma->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @test: parameter struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *test, char *string)
{
	char *pop, c;
	int retweet;

	pop = _strchr(string, '=');
	if (!pop)
		return (1);
	c = *pop;
	*pop = 0;
	retweeet = delete_node_at_index(&(test->alias),
		get_node_index(test->alias, node_starts_with(test->alias, string, -1)));
	*pop = c;
	return (retweet);
}



/**
 * set_alias - sets alias to string
 * @in: parameter struct
 * @sr: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *in, char *sr)
{
	char *pi;

	pi = _strchr(sr, '=');
	if (!pi)
		return (1);
	if (!*++pi)
		return (unset_alias(in, sr));

	unset_alias(in, sr);
	return (add_node_end(&(in->alias), sr, 0) == NULL);
}



/**
 * print_alias - prints an alias string
 * @node_khaz: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node_khaz)
{
	char *pss = NULL, *a = NULL;

	if (node_khaz)
	{
		pss = _strchr(node_khaz->str, '=');
		for (a = node_khaz->str; a <= pss; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(pss + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}






/**
 * _myalias - mimics the alias builtin (man alias)
 * @ism: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *ism)
{
	int i = 0;
	char *poque = NULL;
	list_t *inne = NULL;

	if (ism->argc == 1)
	{
		inne = ism->alias;
		while (inne)
		{
			print_alias(inne);
			inne = inne->next;
		}
		return (0);
	}
	for (i = 1; ism->argv[i]; i++)
	{
		poque = _strchr(ism->argv[i], '=');
		if (p)
			set_alias(ism, ism->argv[i]);
		else
			print_alias(inne_starts_with(ism->alias, info->argv[i], '='));
	}

	return (0);
}
