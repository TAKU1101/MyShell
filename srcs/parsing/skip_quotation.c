#include "../../includes/parsing.h"

int	skip_quotation(char *cmd_line, char c)
{
	int i;

	i = 1;
	while (cmd_line[i] != c && cmd_line[i])
	{
		if (c == '"' && cmd_line[i] == '\\')
			i++;
		i++;
	}
	return (i);
}

int	skip_single_quotation(char *cmd_line)
{
	int qlen;

	qlen = skip_quotation(cmd_line, '\'');
	del_index_char_from_str(cmd_line, 0);
	del_index_char_from_str(cmd_line, qlen - 1);
	return (qlen - 2);
}

int	skip_double_quotation(char **cmd_line, int n, t_minishell *shell)
{
	int		i;
	char	*line;

	i = 1;
	line = *cmd_line;
	while (line[i + n] != '"' && line[i + n])
	{
		if (line[i + n] == '\\')
		{
			if (ft_strchr("$\\\"", line[i + n + 1]))
			{
				del_index_char_from_str(line, i + n);
			}
			else
				i++;
		}
		else if (line[i + n] == '$')
			i += replace_var(&line, i + n, shell);
		i++;
	}
	del_index_char_from_str(line, n);
	del_index_char_from_str(line, i + n - 1);
	*cmd_line = line;
	return (i - 2);
	(void)line;
}
