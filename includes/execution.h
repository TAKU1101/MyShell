#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

# define PIPE_NOT_SEEN 0
# define NOT_FOUND_STATUS 127

int			execute_builtins_command(t_minishell *shell, t_commands *cmd);
int			count_pipes(t_commands *cmd);
int			execute_pipe(t_minishell *shell, t_commands *cmd);
int			execute_command(t_minishell *shell, t_commands *cmd);
int			execute_path(t_minishell *shell, t_commands *cmd);
int			execute_bin(t_minishell *shell, t_commands *cmd);
t_commands	*get_elem_after_nth(t_commands *cmd, int n);
int			execute_cmdlst(t_minishell *shell);
int			set_redirection(t_commands *cmd, int input_fd_backup[256], \
													int output_fd_backup[256]);
int			reset_redirection(t_commands *cmd, int input_fd_backup[256], \
													int output_fd_backup[256]);

#endif
