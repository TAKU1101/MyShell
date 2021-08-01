#include "execution.h"

static int	set_fd(t_commands *cmd)
{
	int len;
	int	i;
	int fd[2];

	len = count_pipes(cmd);
	i = 0;
	while (i < (len - 1))
	{
		if (pipe(fd) < 0)
		{
			ft_putendl_fd("pipe error\n", 2);
			return (EXIT_FAILURE);
		}
		cmd->next->input_fd[0] = fd[0];
		cmd->output_fd[1] = fd[1];
		cmd = cmd->next;
		i++;
	}
	return (SUCCESS);
}

static void	close_all_fd(t_commands *cmd, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i != 0)
			close(cmd->input_fd[0]);
		if (i != (len - 1))
			close(cmd->output_fd[1]);
		i++;
		cmd = cmd->next;
	}
}

static int	fork_cmd(t_commands *cmd, t_commands *head, \
										t_minishell *shell, int len)
{
	int	pid;

	if ((pid = fork()) == -1)
	{
		ft_putendl_fd("fork error", 2);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if ((dup2(cmd->output_fd[1], 1)) < 0)
		{
			ft_putendl_fd("dup2 error", 2);
			exit(1);
		}
		if ((dup2(cmd->input_fd[0], 0)) < 0)
		{
			ft_putendl_fd("dup2 error", 2);
			exit(1);
		}
		close_all_fd(head, len);
		execute_command(shell, cmd);
		exit(shell->exit_status);
	}
	return (EXIT_SUCCESS);
}

int			execute_pipe(t_minishell *shell, t_commands *cmd)
{
	int			len;
	int			i;
	t_commands	*head;
	int			status;

	head = cmd;
	len = count_pipes(cmd);
	if (set_fd(cmd))
		return (EXIT_FAILURE);
	i = 0;
	while (i < len)
	{
		fork_cmd(cmd, head, shell, len);
		i++;
		cmd = cmd->next;
	}
	close_all_fd(head, len);
	i = 0;
	while (i++ < len)
		wait(&status);
	shell->exit_status = status ? 1 : 0;
	return (EXIT_SUCCESS);
}
