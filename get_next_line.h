/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:42:20 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/19 14:30:22 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

int		ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
