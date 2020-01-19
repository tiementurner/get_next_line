/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 14:00:08 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/19 14:28:32 by tblanker      ########   odam.nl         */
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

static char	*cut_from_newline(char *buffer)
{
	while (*buffer != '\n')
		buffer++;
	buffer++;
	return (buffer);
}

int			get_next_line(int fd, char **line)
{
	static char *prev_buffer;
	char		buffer[BUFFER_SIZE];
	int			ret_val;

	if (prev_buffer && ft_strchr(prev_buffer, '\n'))
	{
		*line = cut_to_newline(prev_buffer, *line);
		prev_buffer = cut_from_newline(prev_buffer);
		return (1);
	}
	ret_val = read(fd, buffer, BUFFER_SIZE);
	prev_buffer = ft_strjoin(prev_buffer, buffer);
	while (ret_val == BUFFER_SIZE && !(ft_strchr(prev_buffer, '\n')))
	{
		ret_val = read(fd, buffer, BUFFER_SIZE);
		prev_buffer = ft_strjoin(prev_buffer, buffer);
	}
	if (ft_strchr(prev_buffer, '\n'))
	{
		*line = cut_to_newline(prev_buffer, *line);
		prev_buffer = cut_from_newline(prev_buffer);
		return (1);
	}
	*line = ft_strdup(prev_buffer);
	return (0);
}
