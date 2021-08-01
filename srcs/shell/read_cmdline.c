#include "minishell.h"

static void	init_flags(int *flags)
{
	flags[SINGLE] = 0;
	flags[DOUBLE] = 0;
	flags[BACKSH] = 0;
}

static void	reload_flags_before_join(char c, int *flags)
{
	if (c == '"' && !flags[BACKSH] && !flags[DOUBLE])
		flags[SINGLE] = !flags[SINGLE];
	if ((c == '\'' && !any_flag(flags)) || (c == '\'' && flags[DOUBLE]))
		flags[DOUBLE] = !flags[DOUBLE];
}

static void	reload_flags_after_join(char c, int *flags)
{
	if (c == '\\' && !flags[BACKSH])
		flags[BACKSH] = TRUE;
	else
		flags[BACKSH] = FALSE;
}

static int	update_line(char *buf, char **cmdline, int *flags)
{
	char	*tmp;

	if (buf[0] != '\n' || (!flags[BACKSH] || flags[DOUBLE]))
	{
		if (!(tmp = ft_strjoin((*cmdline), buf)))
			return (EXIT_FAILURE);
		free_add_null_pointer((*cmdline));
		if (!((*cmdline) = ft_strdup(tmp)))
			return (EXIT_FAILURE);
		free_add_null_pointer(tmp);
	}
	else if (buf[0] == '\n' && flags[BACKSH])
		del_index_char_from_str((*cmdline), ft_strlen((*cmdline)) - 1);
	return (SUCCESS);
}

char		*read_cmdline(t_minishell *shell)
{
	char	buf[2];
	char	*cmdline;
	int		flags[3];
	int		rtv;

	init_flags(flags);
	if (!(cmdline = ft_strdup("")))
		return (NULL);
	while ((rtv = read(0, buf, 1)) >= 0)
	{
		buf[rtv] = 0;
		if (rtv == 0 && !ft_strcmp("", cmdline))
			put_exit(0, shell, cmdline);
		reload_flags_before_join(buf[0], flags);
		if (buf[0] == '\n' && !any_flag(flags))
			break ;
		if (update_line(buf, &cmdline, flags))
			return (NULL);
		if (buf[0] == '\n' && any_flag(flags))
			write(1, "> ", 2);
		reload_flags_after_join(buf[0], flags);
	}
	return (cmdline);
}
