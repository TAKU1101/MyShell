#include "../../includes/parsing.h"

static int	count_args(char *line)
{
	int	i;
	int	count;
	int all_digit_flag;

	i = 0;
	count = 0;
	all_digit_flag = 1;
	while (line[i])
	{
		update_count_and_index(line, &i, &count, &all_digit_flag);
	}
	return (count);
}

static void	all_free(char **res, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	**create_argv(char *line, int argc, char **res)
{
	int	i;
	int j;
	int arg_len;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (*line == ' ')
			line++;
		arg_len = count_arg_len(line);
		if (!(res[i] = (char *)malloc(sizeof(char) * (arg_len + 1))))
		{
			all_free(res, i);
			return (NULL);
		}
		j = 0;
		while (j < arg_len)
			res[i][j++] = *line++;
		res[i++][j] = 0;
	}
	res[i] = NULL;
	return (res);
}

int			split_args(t_commands *cmd)
{
	char	**res;
	char	*line;
	int		argc;

	while (cmd)
	{
		line = cmd->command_line;
		if (!line)
			return (1);
		argc = count_args(line);
		if (!(res = (char **)malloc(sizeof(char *) * (argc + 1))))
			return (1);
		if (!(res = create_argv(line, argc, res)))
			return (1);
		cmd->data = res;
		cmd = cmd->next;
	}
	return (0);
}
