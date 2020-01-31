/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:40:09 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/31 17:01:47 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char *line;
	int file = open("testfile", O_RDONLY);
	int line_read = 1;
	while (line_read > 0)
	{
		line_read = get_next_line(file, &line);
		printf("%s\n", line);
		free(line);
	}
	while (1);
}