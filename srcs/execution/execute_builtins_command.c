#include "execution.h"

static void	update_minishell(t_minishell *shell)
{
	update_bins(shell);
	free_2d_array(shell->envs_array);
	store_envs_in_envs_array(shell);
}

static int	switch_buildins_command_2(t_minishell *shell, t_commands *cmd)
{
	char	*first_arg;

	first_arg = cmd->data[0];
	if (!ft_strcmp(first_arg, "unset"))
	{
		shell->exit_status = ft_unset(shell, cmd->data);
		update_minishell(shell);
		return (TRUE);
	}
	else if (!ft_strcmp(first_arg, "env"))
	{
		shell->exit_status = ft_env(shell->envs);
		return (TRUE);
	}
	else if (!ft_strcmp(first_arg, "exit"))
	{
		ft_exit(shell, cmd->data);
		exit(shell->exit_status);
	}
	return (FALSE);
}

static int	switch_buildins_command_1(t_minishell *shell, t_commands *cmd)
{
	char	*first_arg;

	first_arg = cmd->data[0];
	if (!ft_strcmp(first_arg, "echo"))
	{
		shell->exit_status = ft_echo(cmd->data);
		return (TRUE);
	}
	else if (!ft_strcmp(first_arg, "cd"))
	{
		shell->exit_status = ft_cd(cmd->data, shell);
		return (TRUE);
	}
	else if (!ft_strcmp(first_arg, "pwd"))
	{
		shell->exit_status = ft_pwd();
		return (TRUE);
	}
	else if (!ft_strcmp(first_arg, "export"))
	{
		shell->exit_status = ft_export(shell, cmd->data);
		update_minishell(shell);
		return (TRUE);
	}
	return (FALSE);
}

int			execute_builtins_command(t_minishell *shell, t_commands *cmd)
{
	if (switch_buildins_command_1(shell, cmd))
		return (EXIT_SUCCESS);
	else if (switch_buildins_command_2(shell, cmd))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
