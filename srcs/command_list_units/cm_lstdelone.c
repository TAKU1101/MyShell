#include "command_list_units.h"

static void	free_all_file(t_commands *lst)
{
	int i;

	i = 0;
	while (i < 256)
	{
		if (lst->input_is_use[i])
			free_add_null_pointer(lst->input_file[i]);
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (lst->output_is_use[i])
			free_add_null_pointer(lst->output_file[i]);
		i++;
	}
}

void		cm_lstdelone(t_commands *lst)
{
	int i;

	if (lst)
	{
		if (lst->command_line)
			free_add_null_pointer(lst->command_line);
		if (lst->data)
		{
			i = 0;
			while (lst->data[i])
			{
				free_add_null_pointer(lst->data[i]);
				lst->data[i] = NULL;
				i++;
			}
			free(lst->data);
			lst->data = NULL;
		}
		free_all_file(lst);
		free(lst);
	}
}
