#include "../../includes/parsing.h"

static char	*replace_str(char *src, char *replace, int head, int len)
{
	int		after_len;
	int		replace_len;
	char	*res;

	after_len = ft_strlen(replace) + ft_strlen(src) - len;
	if (!(res = (char *)malloc(after_len + 1)))
		return (NULL);
	replace_len = ft_strlen(replace);
	res[after_len] = 0;
	ft_memmove(res, src, head);
	ft_memmove(&res[head], replace, replace_len);
	ft_memmove(&res[head + replace_len], &src[head + len], \
										after_len - head - replace_len);
	free_add_null_pointer(src);
	return (res);
}

int			is_alnum_or_underscore(int c)
{
	return (ft_isalnum(c) || (c == '_') || (c == '?'));
}

int			replace_var(char **cmdline, int i, t_minishell *shell)
{
	char	*val;
	char	*name;
	int		target_len;
	int		val_len;

	target_len = 1;
	while (is_alnum_or_underscore((*cmdline)[i + target_len]) && \
											(*cmdline)[i + target_len])
		target_len++;
	if (!(name = (char *)malloc(sizeof(char) * (target_len + 1))))
		return (-1);
	ft_memmove(name, &((*cmdline)[i + 1]), target_len - 1);
	name[target_len - 1] = 0;
	val = get_env_value(shell, name);
	val_len = ft_strlen(val);
	*cmdline = replace_str(*cmdline, val, i, target_len);
	free_add_null_pointer(name);
	free_add_null_pointer(val);
	return (val_len - 1);
}
