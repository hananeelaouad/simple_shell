#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @ik: parameter struct
 * @bu: address of buffer
 * @le: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *ik, char **bu, size_t *le)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*le) 
	{
		/*bfree((void **)ik->cmd_buf);*/
		free(*bu);
		*bu = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(bu, &len_p, stdin);
#else
		r = _getline(ik, bu, &len_p);
#endif
		if (r > 0)
		{
			if ((*bu)[r - 1] == '\n')
			{
				(*bu)[r - 1] = '\0'; 
				r--;
			}
			ik->linecount_flag = 1;
			remove_comments(*bu);
			build_history_list(bu, *bu, ik->histcount++);
			{
				*le = r;
				ik->cmd_buf = bu;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @ik: parameter struct
 * @bu: buffer
 * @is: size
 *
 * Return: rh
 */
ssize_t read_buf(info_t *ik, char *bu, size_t *is)
{
	ssize_t rh = 0;

	if (*is)
		return (0);
	rh = read(ik->readfd, bu, READ_BUF_SIZE);
	if (rh >= 0)
		*is = rh;
	return (rh);
}

/**
 * _getline - gets the next line of input from STDIN
 * @ik: parameter struct
 * @prot: address of pointer to buffer, preallocated or NULL
 * @lan: size of preallocated ptr buffer if not NULL
 *
 * Return: sp
 */
int _getline(info_t *ik, char **prot, size_t *lan)
{
	static char bu[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, sp = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *prot;
	if (p && lan)
		sp = *lan;
	if (i == len)
		i = len = 0;

	r = read_buf(ik, bu, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(bu + i, '\n');
	k = c ? 1 + (unsigned int)(c - bu) : len;
	new_p = _realloc(p, sp, sp ? sp + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (sp)
		_strncat(new_p, bu + i, k - i);
	else
		_strncpy(new_p, bu + i, k - i + 1);

	sp += k - i;
	i = k;
	p = new_p;

	if (lan)
		*lan = s;
	*prot = p;
	return (sp);
}

/**
 * sigintHandler - blocks ctrl-C
 * @s_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int s_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
