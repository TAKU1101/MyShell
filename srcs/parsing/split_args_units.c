#include "../../includes/parsing.h"

static int	did_skip_quotation(char *line, int *i)
{
	if (line[*i] == '"')
	{
		*i += skip_quotation(&line[*i], '"');
		return (TRUE);
	}
	else if (line[*i] == '\'')
	{
		*i += skip_quotation(&line[*i], '\'');
		return (TRUE);
	}
	return (FALSE);
}

void		update_count_and_index(char *line, int *i, int *count, int *flag)
{
	*flag &= ft_isdigit(line[*i]);
	if (did_skip_quotation(line, i))
		*count += !line[*i] ? 1 : 0;
	else if (ft_strchr("<>", line[*i]))
	{
		*i += ft_strnstr(&line[*i], ">>", 2) ? 1 : 0;
		*count += !line[*i] ? 2 : 1;
	}
	else if (line[*i] == '\\')
	{
		*i += 1;
		*count += !line[*i] || (line[*i] == '\\' && !line[*i + 1]) ? 1 : 0;
		*count += ft_strchr(" <>", line[*i]) && \
									ft_strchr(" <>", line[*i + 1]) ? 1 : 0;
	}
	if (line[*i] && !ft_strchr(" <>", line[*i]))
		if (line[*i] != '\\' && (ft_strchr(" ", line[*i + 1]) || \
								(ft_strchr("<>", line[*i + 1]) && !*flag)))
			(*count)++;
	if (line[*i] == ' ')
		*flag = TRUE;
	(void)flag;
	(void)*flag;
	(*i)++;
}
