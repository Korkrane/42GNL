/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:31:07 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/25 15:45:37 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
**  MAC
**  printf("status :%d\nline :%s\n", get_next_line(fd, &line), line);
**  free(line);
**  printf("status :%d\nline :%s\n", get_next_line(fd, &line), line);
**  free(line);
**  printf("status :%d\nline :%s\n", get_next_line(fd, &line), line);
**  free(line);
**  printf("status :%d\nline :%s\n", get_next_line(fd, &line), line);
**  free(line);
**  LINUX VM one in main
*/

int			main(void)
{
	char	*line;
	int		fd;

	fd = open("texte.txt", O_RDONLY);
	printf("\033[0;31mline :%s\n\033[0mstatus :\033[0;31m%d\033[0m\n",
			line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline :%s\n\033[0mstatus :\033[0;31m%d\033[0m\n",
			line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline :%s\n\033[0mstatus :\033[0;31m%d\033[0m\n",
			line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline :%s\n\033[0mstatus :\033[0;31m%d\033[0m\n",
			line, get_next_line(fd, &line));
	free(line);
	printf("\n");
	return (0);
}
