#include "command_list_units.h"

static void	init_array(t_commands *lst)
{
	int i;

	i = 0;
	while (i < 256)
		lst->input_is_use[i++] = FALSE;
	i = 0;
	while (i < 256)
		lst->output_is_use[i++] = FALSE;
	i = 0;
	while (i < 256)
		lst->input_fd[i++] = 0;
	i = 0;
	while (i < 256)
		lst->output_fd[i++] = 0;
	i = 0;
	while (i < 256)
		lst->output_type[i++] = 0;
	i = 0;
	while (i < 256)
		lst->output_file[i++] = NULL;
	i = 0;
	while (i < 256)
		lst->input_file[i++] = NULL;
}

void		cm_lstinit(t_commands *lst)
{
	lst->is_pipe = 0;
	lst->data = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	init_array(lst);
	lst->input_fd[0] = 0;
	lst->input_is_use[0] = TRUE;
	lst->output_fd[1] = 1;
	lst->output_is_use[1] = TRUE;
	lst->output_type[1] = 0;
}
