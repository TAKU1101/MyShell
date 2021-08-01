#ifndef UTILITIES_H
# define UTILITIES_H

# include "minishell.h"

/*
** ENVS_UTILITIES.C
*/

int			get_index_equals_sign(char *str);
int			can_find_equals_sign(char *str);
char		*get_key(t_envs *lst);
char		*get_value(t_envs *lst);
int			set_key_and_value(t_envs *new);
int			is_env_valid_for_export_use(char *args);
int			is_env_valid_for_unset_use(char *args);

/*
** MANIPULATE_KEY_AND_VALUE.C
*/

char		*extract_key(char *arg);
int			update_env_value(t_envs *list, char *arg);
char		*get_key(t_envs *lst);
char		*get_value(t_envs *lst);
int			set_key_and_value(t_envs *new);

/*
** FREE_FUNCTIONS.C
*/

void		free_2d_array(char **contents);
void		free_add_null_pointer(char *str);
void		unsigned_free_add_null_pointer(unsigned int *array);

/*
** FT_EXIT_HANDLE_OVERFLOW
*/

UINT		*convert_decimal_to_binary(LLINT num);
UINT		*create_bit_weight(void);
UINT		get_exit_status_from_negative_value(LLINT num);
int			is_overflowing(LLINT num, const char *str);

/*
** FT_EXIT_MANIPULATE_STRINGS
*/

int			modify_string_with_minus(const char **str);
int			format_string_for_irregular_input(const char **str);

/*
** HELPER_FT_EXPORT
*/

int			is_argv_empty_string(char *target);
void		handle_error_case(char *args, int *temp_status);

#endif
