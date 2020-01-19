/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:40:09 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/19 14:29:03 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char *line;
	int file = open("testfile", O_RDONLY);
	int line_read = 1;
	while(get_next_line(file, &line))
		printf("%s\n", line);
	// while (get_next_line(file, &line))
	// 	printf("k");
}