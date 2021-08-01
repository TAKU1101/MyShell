#include "../../includes/parsing.h"

static int	set_filename(char ***data, int *i, t_commands *cmd, \
													t_minishell *shell)
{
	if (is_redirection((*data)[*i], ">") || is_redirection((*data)[*i], "<")\
						|| is_redirection((*data)[*i], ">>"))
	{
		if (is_correct_filename((*data)[*i + 1], cmd))
		{
			shell->exit_status = EXIT_STATUS_SYNTAX_ERROR;
			return (1);
		}
		else
		{
			if (set_file_data((*data), *i, cmd, shell))
				return (EXIT_FAILURE);
			(*data) = delete_strings_with_redirection_signs((*data), *i);
			(*data) = delete_strings_with_filename((*data), *i);
		}
	}
	else
		(*i)++;
	return (EXIT_SUCCESS);
}

int			store_file_data_by_redirection_type(t_commands *cmd, \
													t_minishell *shell)
{
	char	**data;
	int		i;

	while (cmd)
	{
		data = cmd->data;
		i = 0;
		while (data[i])
		{
			if (set_filename(&data, &i, cmd, shell))
			{
				cmd->data = data;
				return (EXIT_FAILURE);
			}
		}
		cmd->data = data;
		cmd = cmd->next;
	}
	return (EXIT_SUCCESS);
}
