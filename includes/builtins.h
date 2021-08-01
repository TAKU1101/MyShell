#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include "constants.h"
# include "libft.h"
# include "struct.h"
# include "utilities.h"
# include "error.h"
# include <dirent.h>

int		ft_pwd(void);
int		ft_echo(char **argv);
int		ft_cd(char **argv, t_minishell *minishell);
int		ft_env(t_envs *envs);
int		ft_export(t_minishell *shell, char **argv);
int		ft_unset(t_minishell *shell, char **argv);
int		ft_exit(t_minishell *shell, char **argv);

# ifndef PASS_MAX
#  define PASS_MAX   256
# endif

#endif
