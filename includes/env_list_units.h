#ifndef ENV_LIST_UNITS_H
# define ENV_LIST_UNITS_H

# include "minishell.h"
# include "struct.h"
# include "utilities.h"

int			initialize_env_lst(t_minishell *minishell, char **envp);
int			initialize_sort_list(t_minishell *minishell, char *arg);
t_envs		*env_lstnew(char *value);
void		env_lstdelone(t_envs *lst);
void		env_lstclear(t_envs **list);
char		*get_env_value(t_minishell *shell, char *key);
int			envs_lstsize(t_envs *envs);
int			store_envs_in_envs_array(t_minishell *shell);

/*
** ENV_SORT_LIST.C
*/

void		swap_element(char **first, char **second);
void		swap_node(t_envs **first, t_envs **second);
int			should_swap(char *first, char *second);
void		sort_list(t_envs **sort_list);

/*
** ENV_PRINT_OUT.C
*/

void		print_sorted_list(t_envs *list);
int			print_out_envs(t_minishell *shell);

/*
** CONTROL_PWD_AND_OLDPWD
*/

int			create_pwd(t_minishell *shell, char *current_dir);
int			update_pwd(t_minishell *shell);
int			create_oldpwd(t_minishell *shell, char *current_dir);
int			update_oldpwd(t_minishell *shell);

#endif
