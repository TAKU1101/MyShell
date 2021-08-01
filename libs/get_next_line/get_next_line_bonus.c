#include "get_next_line_bonus.h"

static int	free_memory_and_output_error(char **memory, int fd)
{
	free(memory[fd]);
	memory[fd] = NULL;
	return (GNL_ERROR);
}

static char	*get_ready_for_buffer(void)
{
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	{
		return (NULL);
	}
	return (buffer);
}

/*
** if ((next_line_pointer = ft_strchr(memory[fd], '\n')) ! = NULL)
**
** If there is a newline character in the static area memory
** that has been read and stored so far, then
** Store the string up to the newline character in the line.
** If there is a newline character,
** store the string up to the newline character in line.
** After freeing memory, store the contents of the remainder and
** prepare it for the next read.
**
** else
**
** If no newline character is found == reach EOF
** -> prepare to terminate the program
*/

static int	store_in_line(char **memory, int fd, char **line)
{
	char		*next_line_pointer;
	char		*remainder;
	int			length;

	if ((next_line_pointer = ft_strchr(memory[fd], '\n')) != NULL)
	{
		*next_line_pointer = '\0';
		length = ft_strlen(memory[fd]) - ft_strlen(next_line_pointer);
		if ((*line = ft_substr(memory[fd], 0, length)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		if ((remainder = ft_strdup(next_line_pointer + 1)) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = remainder;
	}
	else
	{
		if ((*line = ft_strdup(memory[fd])) == NULL)
			return (free_memory_and_output_error(memory, fd));
		free(memory[fd]);
		memory[fd] = NULL;
		return (GNL_EOF);
	}
	return (GNL_READ);
}

static int	return_value(ssize_t bytes, char **memory, int fd, char **line)
{
	int	i;

	if (bytes == -1)
	{
		i = 0;
		while (i < OPEN_MAX)
		{
			if (memory[i] != NULL)
			{
				free(memory[i]);
				memory[i] = NULL;
			}
			i++;
		}
		return (GNL_ERROR);
	}
	else if (bytes == 0 && (memory[fd] == NULL || memory[fd][0] == '\0'))
	{
		if ((*line = ft_strdup("")) == NULL)
			return (GNL_ERROR);
		return (GNL_EOF);
	}
	else
		return (store_in_line(memory, fd, line));
}

/*
** Sequence of events
** 1. read the buffer_size and store it in the buffer, then store the contents
**    in the static area memory
** 2. if there is a line break in memory, stop reading and go to
**    the process of storing up to the line break character in line
** 3. Relay the function return_value to the store_in_line function,
**    which stores the value in line.
** if (memory[fd] == NULL) == when the program is invoked
** -> If (memory[fd] == NULL) == when the program is started
** If (memory[fd] == NULL) == program is invoked
** -> static variable with static local variable & not explicitly initialized
*/

int			get_next_line(int fd, char **line)
{
	static char		*memory[OPEN_MAX];
	char			*buffer;
	char			*temp;
	ssize_t			bytes;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0 || line == NULL)
		return (GNL_ERROR);
	if ((buffer = get_ready_for_buffer()) == NULL)
		return (free_memory_and_output_error(memory, fd));
	while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (memory[fd] == NULL)
			memory[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = temp;
		}
		if (ft_strchr(memory[fd], '\n') != NULL)
			break ;
	}
	free(buffer);
	return (return_value(bytes, memory, fd, line));
}
