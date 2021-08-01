#ifndef COMMAND_LIST_UNITS_H
# define COMMAND_LIST_UNITS_H

# include "minishell.h"

t_commands	*cm_lstnew(char *commnad_line);
t_commands	*cm_lstfirst(t_commands *lst);
t_commands	*cm_lstlast(t_commands *lst);
void		cm_lstadd_front(t_commands **lst, t_commands *new);
void		cm_lstadd_back(t_commands **lst, t_commands *new);
int			cm_lstsize(t_commands *lst);
void		cm_lstdelone(t_commands *lst);
void		cm_lstclear(t_commands **lst);
void		cm_lstinit(t_commands *lst);
void		cm_lstinsert_back(t_commands *lst, t_commands *new);
void		cm_lstinsert_front(t_commands *lst, t_commands *new);
void		cm_lstswap(t_commands *elem1, t_commands *elem2);
void		cm_lstreverse(t_commands *start, t_commands *end);
void		cm_lstswap_val(t_commands *elem1, t_commands *elem2);
t_commands	*cm_lstremove(t_commands *current);

#endif
