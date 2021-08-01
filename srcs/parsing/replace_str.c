#include "../../includes/parsing.h"

int			*replace_args(t_minishell *shell, char **line)
{
	char	*arg;
	int		i;

	i = 0;
	arg = *line;
	while (arg[i])
	{
		if (arg[i] == '\\')
		{
			del_index_char_from_str(arg, i);
			i++;
		}
		else if (i >= 0 && arg[i] == '\'')
			i += skip_single_quotation(&arg[i]) + 1;
		else if (i >= 0 && arg[i] == '"')
			i += skip_double_quotation(&arg, i, shell) + 1;
		else if (i >= 0 && arg[i] == '$')
			i += replace_var(&arg, i, shell) + 1;
		else
			i++;
	}
	*line = arg;
	return (0);
}

void		replace_cmdlist(t_minishell *shell, t_commands *cmd)
{
	char	*cmdline;
	char	**data;
	int		i;

	while (cmd)
	{
		data = cmd->data;
		i = 0;
		while (data[i])
		{
			cmdline = data[i];
			replace_args(shell, &cmdline);
			data[i] = cmdline;
			i++;
		}
		if (cmd->input_file[0])
			replace_args(shell, &(cmd->input_file[0]));
		if (cmd->output_file[1])
			replace_args(shell, &(cmd->output_file[1]));
		cmd = cmd->next;
	}
}

void		replace_pipes(t_minishell *shell, t_commands *cmd)
{
	char	*cmdline;
	char	**data;
	int		i;

	while (cmd)
	{
		data = cmd->data;
		i = 0;
		while (data[i])
		{
			cmdline = data[i];
			replace_args(shell, &cmdline);
			data[i] = cmdline;
			i++;
		}
		if (cmd->input_file[0])
			replace_args(shell, &(cmd->input_file[0]));
		if (cmd->output_file[1])
			replace_args(shell, &(cmd->output_file[1]));
		if (cmd && !cmd->is_pipe)
			break ;
		cmd = cmd->next;
	}
}
