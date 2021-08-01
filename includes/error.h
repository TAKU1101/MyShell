#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

/*
** PRINT_ERROR_FUNCTIONS.C
*/

void	print_error_ft_cd(char *pathname);
void	print_error_ft_export(char *args);
void	print_error_ft_unset(char *args);
int		print_error_ft_exit(int type, char *command);

void	print_error_command_not_found(char *command);
void	print_error_cannnot_open_file(char *filename);
void	print_syntax_error_msg(char *token);
void	print_non_command_error_msg(char *command);
void	print_non_file_error_msg(char *filename);

#endif
