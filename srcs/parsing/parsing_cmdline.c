#include "../../includes/parsing.h"

/*
** static int	print_elem_data(t_commands *cmd)
** {
** 	char	**data;
** 	int		i;
**
** 	printf("\tis_pipe, cmd_list\n");
** 	while (cmd)
** 	{
** 		printf("\toutputfile: %s\n", cmd->output_file);
** 		printf("\tinputfile: %s\n", cmd->input_file);
** 		printf("\t%d      , %s\n", cmd->is_pipe, cmd->command_line);
** 		data = cmd->data;
** 		i = 0;
** 		while (data[i])
** 		{
** 			printf("\t\t%d: %s\n", i, data[i]);
** 			i++;
** 		}
** 		cmd = cmd->next;
** 	}
** 	return (0);
** }
*/

int	parsing_cmdline(char *cmdline, t_minishell *shell)
{
	t_commands	*cmd;

	if (!(cmd = split_command_into_orders(cmdline)))
	{
		shell->cmd = cmd;
		return (EXIT_FAILURE);
	}
	if (strip_space_cmdline(cmd))
	{
		shell->cmd = cmd;
		return (EXIT_FAILURE);
	}
	if (split_args(cmd))
	{
		shell->cmd = cmd;
		return (EXIT_FAILURE);
	}
	if (store_file_data_by_redirection_type(cmd, shell))
	{
		shell->cmd = cmd;
		return (EXIT_FAILURE);
	}
	shell->cmd = cmd;
	return (EXIT_SUCCESS);
}
