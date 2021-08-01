#include "../../includes/parsing.h"

static char	*strip_space(char *str)
{
	char	*res;

	if (!(res = ft_strtrim(str, " ")))
		return (NULL);
	free(str);
	return (res);
}

int			strip_space_cmdline(t_commands *cmd)
{
	char	*cmdline;

	while (cmd)
	{
		cmdline = cmd->command_line;
		if (!(cmdline = strip_space(cmdline)))
			return (1);
		cmd->command_line = cmdline;
		cmd = cmd->next;
	}
	return (0);
}
