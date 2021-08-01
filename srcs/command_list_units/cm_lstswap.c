#include "command_list_units.h"

void		cm_lstswap(t_commands *elem1, t_commands *elem2)
{
	t_commands	*elem1_f;
	t_commands	*elem2_f;

	if (elem1 == elem2)
		return ;
	cm_lstadd_front(&elem1, cm_lstnew(ft_strdup("It is dummy data!")));
	elem1_f = elem1->prev;
	cm_lstremove(elem1);
	elem2_f = elem2->prev;
	cm_lstremove(elem2);
	cm_lstinsert_back(elem2_f, elem1);
	cm_lstinsert_back(elem1_f, elem2);
	cm_lstdelone(cm_lstremove(cm_lstfirst(elem1_f)));
}
