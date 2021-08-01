#include "minishell.h"

static int	is_cmdlst_empty(t_commands *cmd)
{
	while (cmd)
	{
		if (cmd->data != NULL && cmd->data[0] != NULL)
		{
			return (FALSE);
		}
		cmd = cmd->next;
	}
	return (TRUE);
}

static int	is_cmdlst_redirection_empty(t_minishell *shell, t_commands *cmd, \
															t_commands *first)
{
	t_commands	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->data == NULL || cmd->data[0] == NULL)
		{
			if (cmd->output_file[1] == NULL && cmd->input_file[0] == NULL)
			{
				if (cmd->is_pipe)
					print_syntax_error_msg("|");
				else
					print_syntax_error_msg(";");
				shell->exit_status = EXIT_STATUS_SYNTAX_ERROR;
				return (TRUE);
			}
			if (cmd == first)
				shell->cmd = cmd->next;
			cm_lstremove(cmd);
			cm_lstdelone(cmd);
		}
		cmd = tmp;
	}
	return (FALSE);
}

static int	check_syntax_last_elem(t_minishell *shell, t_commands *cmd, \
															t_commands *first)
{
	t_commands *last;

	last = cm_lstlast(cmd);
	if ((last->data == NULL || last->data[0] == NULL))
	{
		if (last->prev && last->prev->is_pipe &&\
			(last->output_file[1] == NULL && last->input_file[0] == NULL))
		{
			print_syntax_error_msg("newline");
			shell->exit_status = EXIT_STATUS_SYNTAX_ERROR;
			return (EXIT_FAILURE);
		}
		if (cmd != last)
		{
			if (last == first)
				shell->cmd = last->next;
			cm_lstremove(last);
			cm_lstdelone(last);
		}
	}
	return (EXIT_SUCCESS);
}

int			check_syntax_cmdlst(t_minishell *shell, t_commands *cmd)
{
	t_commands	*first;

	first = cm_lstfirst(cmd);
	if (check_syntax_last_elem(shell, cmd, first))
		return (EXIT_FAILURE);
	if (is_cmdlst_empty(cmd))
		return (EXIT_FAILURE);
	if (is_cmdlst_redirection_empty(shell, cmd, first))
		return (EXIT_FAILURE);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
