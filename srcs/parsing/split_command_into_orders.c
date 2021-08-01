#include "../../includes/parsing.h"

static int	add_cmd_list(t_commands **cmd, char *cmd_line, int len, int is_pipe)
{
	char		*res;
	t_commands	*new;

	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (1);
	ft_strlcpy(res, cmd_line, len + 1);
	if (!(new = cm_lstnew(res)))
		return (1);
	if (is_pipe)
		new->is_pipe = is_pipe;
	cm_lstadd_back(cmd, new);
	return (0);
}

static int	pipe_and_semicolone(t_commands **cmd, char *line, int *i, int *j)
{
	if (ft_strchr("|;", line[*i]) && line[*i])
	{
		if (add_cmd_list(cmd, &line[*j + 1], *i - *j - 1, line[*i] == '|'))
			return (-1);
		*j = *i;
	}
	return (0);
}

t_commands	*split_command_into_orders(char *cmd_line)
{
	t_commands	*cmd;
	int			i;
	int			head;

	i = 0;
	head = -1;
	cmd = NULL;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '\\')
			i += cmd_line[i + 1] ? 2 : 0;
		if (cmd_line[i] == '"')
			i += skip_quotation(&cmd_line[i], '"');
		if (cmd_line[i] == '\'')
			i += skip_quotation(&cmd_line[i], '\'');
		if (pipe_and_semicolone(&cmd, cmd_line, &i, &head))
			return (NULL);
		i += cmd_line[i] ? 1 : 0;
	}
	if (add_cmd_list(&cmd, &cmd_line[head + 1], i - head - 1, PIPE_NOT_SEEN))
		return (NULL);
	return (cmd);
}
