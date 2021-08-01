#include "minishell.h"

int		check_cmdline(t_minishell *shell, char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == ';')
	{
		print_syntax_error_msg(";");
		shell->exit_status = EXIT_STATUS_SYNTAX_ERROR;
		return (EXIT_FAILURE);
	}
	else if (str[i] == '|')
	{
		print_syntax_error_msg("|");
		shell->exit_status = EXIT_STATUS_SYNTAX_ERROR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
