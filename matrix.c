#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @ik: struct address
 */
void clear_info(info_t *ik)
{
	ik->arg = NULL;
	ik->argv = NULL;
	ik->path = NULL;
	ik->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @ik: struct address
 * @avenu: argument vector
 */
void set_info(info_t *ik, char **avenu)
{
	int i = 0;

	ik->fname = avenu[0];
	if (ik->arg)
	{
		ik->argv = strtow(ik->arg, " \t");
		if (!ik->argv)
		{

			ik->argv = malloc(sizeof(char *) * 2);
			if (ik->argv)
			{
				ik->argv[0] = _strdup(ik->arg);
				ik->argv[1] = NULL;
			}
		}
		for (i = 0; ik->argv && ik->argv[i]; i++)
			;
		ik->argc = i;

		replace_alias(ik);
		replace_vars(ik);
	}
}

/**
 * free_info - frees info_t struct fields
 * @ik: struct address
 * @ever: true if freeing all fields
 */
void free_info(info_t *ik, int ever)
{
	ffree(ik->argv);
	ik->argv = NULL;
	ik->path = NULL;
	if (ever)
	{
		if (!ik->cmd_buf)
			free(ik->arg);
		if (ik->env)
			free_list(&(ik->env));
		if (ik->history)
			free_list(&(ik->history));
		if (ik->alias)
			free_list(&(ik->alias));
		ffree(ik->environ);
			ik->environ = NULL;
		bfree((void **)ik->cmd_buf);
		if (ik->readfd > 2)
			close(ik->readfd);
		_putchar(BUF_FLUSH);
	}
}
