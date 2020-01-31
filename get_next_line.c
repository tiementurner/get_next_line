/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 14:00:08 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/31 17:11:18 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cut_to_newline(char *buffer, char *line)
{
	int i;

	i = 0;
	line = (char *)malloc(sizeof(char) * ft_strlen(buffer));
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char *cut_from_newline(char *buffer)
{
	while (*buffer != '\n')
		buffer++;
	buffer++;
	return (buffer);
}

static	int	buf_concatenate(int ret_val, char **buffer, int fd, char **line)
{
	char temp_buffer[BUFFER_SIZE + 1];

	temp_buffer[ret_val] = '\0';
	while (ret_val == BUFFER_SIZE && !(ft_strchr(*buffer, '\n')))
	{
		ret_val = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[ret_val] = '\0';
		*buffer = ft_strjoin(*buffer, temp_buffer);
	}
	if (ft_strchr(*buffer, '\n'))
	{
		*line = cut_to_newline(*buffer, *line);
		*buffer = cut_from_newline(*buffer);
		return (1);
	}
	*line = ft_strdup(*buffer);
	free(*buffer);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char *prev_buffer;
	char		buffer[BUFFER_SIZE + 1];
	int			ret_val;

	if (prev_buffer && ft_strchr(prev_buffer, '\n'))
	{
		*line = cut_to_newline(prev_buffer, *line);
		prev_buffer = cut_from_newline(prev_buffer);
		return (1);
	}
	ret_val = read(fd, buffer, BUFFER_SIZE);
	if (ret_val == -1)
		return (-1);
	buffer[ret_val] = '\0';
	prev_buffer = ft_strjoin(prev_buffer, buffer);
	return (buf_concatenate(ret_val, &prev_buffer, fd, line));
}
