#include "bin_list_units.h"

char	*get_bin_path(t_minishell *shell, char *name)
{
	t_bins	*current;
	char	*path;

	current = shell->bins;
	path = NULL;
	while (current)
	{
		if (!ft_strcasecmp(current->name, name))
		{
			if (!(path = ft_strdup(current->path)))
			{
				return (NULL);
			}
			return (path);
		}
		current = current->next;
	}
	return (NULL);
}
