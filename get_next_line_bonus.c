/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 14:00:08 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/12 10:25:46 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*cut_to_newline(char *buffer, char *line)
{
	int i;

	i = 0;
	line = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*cut_from_newline(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (!res)
	{
		free(buffer);
		return (0);
	}
	res[(ft_strlen(buffer) - i)] = '\0';
	while (buffer[i])
	{
		res[j] = buffer[i];
		j++;
		i++;
	}
	free(buffer);
	return (res);
}

static	int	newline_found(char **line, char **buffer, int fd)
{
	char *temp;

	*line = cut_to_newline(buffer[fd], *line);
	temp = cut_from_newline(buffer[fd]);
	if (!temp || !(*line))
		return (-1);
	buffer[fd] = temp;
	return (1);
}

static	int	buf_concatenate(int ret_val, char **buffer, int fd, char **line)
{
	char temp_buffer[BUFFER_SIZE + 1];

	while (ret_val == BUFFER_SIZE && !(ft_strchr(buffer[fd], '\n')))
	{
		ret_val = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[ret_val] = '\0';
		buffer[fd] = gnl_strjoin(buffer[fd], temp_buffer);
		if (!(buffer[fd]))
			return (-1);
	}
	if (ft_strchr(buffer[fd], '\n'))
		return (newline_found(line, buffer, fd));
	*line = gnl_strdup(buffer[fd]);
	free(buffer[fd]);
	if (!(*line))
		return (-1);
	buffer[fd] = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *prev_buffer[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			ret_val;
	char		*temp;

	if (prev_buffer[fd] && ft_strchr(prev_buffer[fd], '\n'))
		return (newline_found(line, prev_buffer, fd));
	ret_val = read(fd, buffer, BUFFER_SIZE);
	if (ret_val == -1 || BUFFER_SIZE < 0)
		return (-1);
	buffer[ret_val] = '\0';
	temp = gnl_strjoin(prev_buffer[fd], buffer);
	prev_buffer[fd] = gnl_strdup(temp);
	free(temp);
	if (!(prev_buffer[fd]))
		return (-1);
	return (buf_concatenate(ret_val, prev_buffer, fd, line));
}
