#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# define PIPE_NOT_SEEN 0

t_commands	*split_command_into_orders(char *cmd_line);
int			strip_space_cmdline(t_commands *cmd);
int			skip_quotation(char *cmd_line, char c);
int			skip_single_quotation(char *cmd_line);
int			skip_double_quotation(char **cmd_line, int i, t_minishell *shell);
int			replace_var(char **cmdline, int i, t_minishell *shell);
void		replace_cmdlist(t_minishell *shell, t_commands *cmd);
void		replace_pipes(t_minishell *shell, t_commands *cmd);
int			split_args(t_commands *cmd);
int			del_index_char_from_str(char *str, int n);
char		**del_index_str_from_strarray(char **data, int n);
char		**delete_strings_with_redirection_signs(char **data, int n);
char		**delete_strings_with_filename(char **data, int n);
int			parsing_cmdline(char *cmdline, t_minishell *shell);
int			store_file_data_by_redirection_type(t_commands *cmd, \
														t_minishell *shell);
void		update_count_and_index(char *line, int *i, int *count, int *flag);
int			count_arg_len(char *line);
int			set_file_data(char **data, int i, t_commands *cmd, \
												t_minishell *shell);
int			is_correct_filename(char *filename, t_commands *cmd);
int			is_redirection(char *haystack, char *needle);

#endif
