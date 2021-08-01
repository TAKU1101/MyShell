#include "execution.h"

int	count_pipes(t_commands *cmd)
{
	int counter;

	counter = 0;
	while (cmd)
	{
		counter++;
		if (!cmd->is_pipe)
			return (counter);
		cmd = cmd->next;
	}
	return (counter);
}
