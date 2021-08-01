#include "minishell.h"

/*
** static int	print_elem_data(t_commands *cmd)
** {
**	char	**data;
**	int		i;
**	int		j;
**
**	printf("\tis_pipe, cmd_list\n");
**	while (cmd)
**	{
**		printf("\tinput\n");
**		j = 0;
**		while (j < 256)
**		{
**			if (cmd->input_is_use[j])
**				printf("\t\t%d(%d) <- %s\n", j, cmd->input_fd[j], \
**														cmd->input_file[j]);
**			j++;
**		}
**		printf("\toutput\n");
**		j = 0;
**		while (j < 256)
**		{
**			if (cmd->output_is_use[j])
**				printf("\t\t%d(%d) -> %s\n", j, cmd->output_fd[j], \
**														cmd->output_file[j]);
**			j++;
**		}
**		printf("\t%d      , %s\n", cmd->is_pipe, cmd->command_line);
**		data = cmd->data;
**		i = 0;
**		while (data[i])
**		{
**			printf("\t\t%d: %s\n", i, data[i]);
**			i++;
**		}
**		cmd = cmd->next;
**	}
**	return (0);
** }
*/

int	minishell(t_minishell *shell)
{
	char	*cmdline;

	set_signal();
	while (1)
	{
		g_pid = 0;
		ft_putstr_fd("minishell$ ", 1);
		cmdline = read_cmdline(shell);
		if (is_all_space(cmdline) || check_cmdline(shell, cmdline))
		{
			free_add_null_pointer(cmdline);
			continue ;
		}
		else if (parsing_cmdline(cmdline, shell))
			(void)0;
		else if (check_syntax_cmdlst(shell, shell->cmd))
			(void)0;
		else if (execute_cmdlst(shell))
			(void)0;
		cm_lstclear(&(shell->cmd));
		free_add_null_pointer(cmdline);
	}
	return (0);
}
