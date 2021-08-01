#include "error.h"

void	print_syntax_error_msg(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `",
																STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}
