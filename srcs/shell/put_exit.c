#include "minishell.h"

void	put_exit(int n, t_minishell *shell, char *cmdline)
{
	(void)shell;
	free_add_null_pointer(cmdline);
	ft_putstr_fd("exit\n", 1);
	exit(n);
}
