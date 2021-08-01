#include "execution.h"

/*
** static void print_elem_data(t_commands *cmd)
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
** }
*/

int	execute_cmdlst(t_minishell *shell)
{
	t_commands	*cmd;
	int			pipes;

	cmd = shell->cmd;
	pipes = 0;
	while (cmd)
	{
		pipes = count_pipes(cmd);
		replace_pipes(shell, cmd);
		if (pipes == 1)
		{
			execute_command(shell, cmd);
		}
		else
		{
			execute_pipe(shell, cmd);
		}
		cmd = get_elem_after_nth(cmd, pipes);
	}
	return (EXIT_SUCCESS);
}
