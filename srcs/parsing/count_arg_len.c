#include "../../includes/parsing.h"

static void	count_arg_len_un_red(char *line, int *i)
{
	while (!ft_strchr(" <>", line[*i]))
	{
		if (line[*i] == '"')
			*i += skip_quotation(&line[*i], '"') + 1;
		else if (line[*i] == '\'')
			*i += skip_quotation(&line[*i], '\'') + 1;
		else if (line[*i] == '\\')
			*i += 2;
		else
			(*i)++;
	}
}

int			count_arg_len(char *line)
{
	int	i;

	i = 0;
	if (ft_isdigit(line[i]))
	{
		while (ft_isdigit(line[i]))
			i++;
	}
	if (ft_strchr("<>", line[i]))
	{
		if (ft_strnstr(&line[i], ">>", 2))
			i += 2;
		else if (ft_strnstr(&line[i], ">", 1) || ft_strnstr(&line[i], "<", 1))
			i += 1;
	}
	else
		count_arg_len_un_red(line, &i);
	return (i);
}
