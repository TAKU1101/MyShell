#include "bin_list_units.h"

int		update_bins(t_minishell *shell)
{
	bin_lstclear(&(shell->bins));
	if (initialize_bins(shell))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
