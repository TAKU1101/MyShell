#include "minishell.h"

void	cntl_c_signal(int n)
{
	if (g_pid == 0)
	{
		ft_putstr_fd("\b\b  \b\b", 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("minishell$ ", 1);
	}
	else
	{
		ft_putstr_fd("\n", 1);
	}
	(void)n;
}

void	cntl_backslash_signal(int n)
{
	(void)n;
	if (g_pid != 0)
	{
		ft_putstr_fd("Quit: 3\n", 1);
	}
	else
	{
		ft_putstr_fd("\b\b  \b\b", 1);
	}
}

void	do_nothing(int n)
{
	(void)n;
}

int		set_signal(void)
{
	signal(SIGQUIT, cntl_backslash_signal);
	signal(SIGINT, cntl_c_signal);
	return (0);
}
