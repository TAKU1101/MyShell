#include "../../includes/parsing.h"

int	is_correct_filename(char *filename, t_commands *cmd)
{
	if (filename == NULL)
	{
		if (cmd->is_pipe)
			print_syntax_error_msg("|");
		else
			print_syntax_error_msg(cmd->next ? ";" : "newline");
		return (1);
	}
	else if (is_redirection(filename, ">"))
	{
		print_syntax_error_msg(">");
		return (1);
	}
	else if (is_redirection(filename, "<"))
	{
		print_syntax_error_msg("<");
		return (1);
	}
	else if (is_redirection(filename, ">>"))
	{
		print_syntax_error_msg(">>");
		return (1);
	}
	return (0);
}
