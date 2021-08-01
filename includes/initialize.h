#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "minishell.h"
# include "struct.h"
# include "constants.h"
# include "env_list_units.h"

int		initialize_minishell(t_minishell *shell, char **envp);

#endif
