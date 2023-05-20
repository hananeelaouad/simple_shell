#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @ik: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: dima 0
 */
char **get_environ(info_t *ik)
{
	if (!ik->environ || ik->env_changed)
	{
		ik->environ = list_to_strings(ik->env);
		ik->env_changed = 0;
	}

	return (ik->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @ik: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var_is_bull: the string env var property
 */
int _unsetenv(info_t *ik, char *var_is_bull)
{
	list_t *node = ik->env;
	size_t i = 0;
	char *p;

	if (!node || !var_is_bull)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var_is_bull);
		if (p && *p == '=')
		{
			ik->env_changed = delete_node_at_index(&(ik->env), i);
			i = 0;
			node = ik->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @ik: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var_is_bull: the string env var property
 * @input: the string env var value
 *  Return: dima 0
 */
int _setenv(info_t *ik, char *var_is_bull, char *input)
{
	char *bu = NULL;
	list_t *node;
	char *p;

	if (!var_is_bull || !input)
		return (0);

	buf = malloc(_strlen(var_is_bull) + _strlen(input) + 2);
	if (!bu)
		return (1);
	_strcpy(bu, var_is_bull);
	_strcat(bu, "=");
	_strcat(bu, input);
	node = ik->env;
	while (node)
	{
		p = starts_with(node->str, var_is_bull);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = bu;
			ik->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(ik->env), bu, 0);
	free(bu);
	ik->env_changed = 1;
	return (0);
}
