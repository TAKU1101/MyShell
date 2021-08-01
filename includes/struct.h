#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_envs
{
	char				*key_value_pair;
	char				*key;
	char				*value;
	int					is_equal_found;
	struct s_envs		*next;
}						t_envs;

/*
** If you change this structure,
** please also change cm_lstinit.c and cm_lstdelone
*/
typedef struct			s_commands
{
	char				**data;
	char				*command_line;
	int					is_pipe;
	int					pipe_fd[2];
	int					output_is_use[256];
	int					input_is_use[256];
	int					output_fd[256];
	int					input_fd[256];
	char				*output_file[256];
	char				*input_file[256];
	int					output_type[256];
	struct s_commands	*prev;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_bins
{
	char				*path;
	char				*name;
	struct s_bins		*next;
}						t_bins;

typedef struct			s_minishell
{
	int					exit_status;
	t_bins				*bins;
	t_envs				*envs;
	t_envs				*sort_list;
	char				**envs_array;
	t_commands			*cmd;
}						t_minishell;

#endif
