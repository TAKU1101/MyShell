#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include "struct.h"
# include "command_list_units.h"
# include "parsing.h"
# include "constants.h"
# include "builtins.h"
# include "execution.h"
# include "env_list_units.h"
# include "bin_list_units.h"
# include "initialize.h"
# include "error.h"
# include "libft.h"
# include "get_next_line.h"

# define SINGLE 0
# define DOUBLE 1
# define BACKSH 2

# define EXIT_STATUS_SYNTAX_ERROR 2

# define VM_SIGQUIT	131

/*
** int			g_exit_flag;
*/

/*
** char					****read_line(void);
** int						is_correct_command(char ****command);
** int						init_signal(void);
** int						execve_command(char ****data);
*/

pid_t	g_pid;

char	*read_cmdline(t_minishell *shell);
int		any_flag(int flags[]);
int		minishell(t_minishell *shell);
int		check_syntax_cmdlst(t_minishell *shell, t_commands *cmd);
int		set_signal();
void	terminate_minishell(t_minishell *minishell);
void	put_exit(int n, t_minishell *shell, char *cmdline);
int		is_all_space(char *str);
int		check_cmdline(t_minishell *shell, char *str);
void	do_nothing(int n);
void	cntl_c_signal(int n);
void	cntl_backslash_signal(int n);

#endif
