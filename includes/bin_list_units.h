#ifndef BIN_LIST_UNITS_H
# define BIN_LIST_UNITS_H

# include "minishell.h"

void	bin_lstadd_back(t_bins **lst, t_bins *new);
void	bin_lstclear(t_bins **lst);
int		bin_lstsize(t_bins *lst);
void	bin_lstdelone(t_bins *lst);
t_bins	*bin_lstnew(char *path, char *name);
t_bins	*bin_lstlast(t_bins *lst);
int		initialize_bins(t_minishell *shell);
int		update_bins(t_minishell *shell);
char	*get_bin_path(t_minishell *shell, char *name);

#endif
