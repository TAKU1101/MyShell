#include "execution.h"

int			execute_command(t_minishell *shell, t_commands *cmd)
{
	int	input_fd_backup[256];
	int	output_fd_backup[256];
	int	status;

	cmd->input_fd[0] = 0;
	cmd->output_fd[1] = 1;
	if (set_redirection(cmd, input_fd_backup, output_fd_backup))
		return (EXIT_FAILURE);
	if (!(execute_builtins_command(shell, cmd)))
		status = EXIT_SUCCESS;
	else if (!(execute_bin(shell, cmd)))
		status = EXIT_SUCCESS;
	else if (!(execute_path(shell, cmd)))
		status = EXIT_SUCCESS;
	else
		status = EXIT_FAILURE;
	if (reset_redirection(cmd, input_fd_backup, output_fd_backup))
		return (EXIT_FAILURE);
	return (status);
}
