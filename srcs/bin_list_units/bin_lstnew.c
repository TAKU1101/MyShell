#include "bin_list_units.h"

t_bins	*bin_lstnew(char *path, char *name)
{
	t_bins	*new;

	if (!(new = (t_bins *)malloc(sizeof(t_bins))))
		return (NULL);
	new->path = path;
	new->name = name;
	new->next = NULL;
	return (new);
}
