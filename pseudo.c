/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:24:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/23 22:14:17 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v3.h"
#include <string.h>

int		ft_free(char *to_free, int ret)
{
	free(to_free);
	to_free = NULL;
	return(ret);
}

char *line_in_leftover(char *line, char *leftover)
{
	int i;
	char *line_found;

	i = 0;
	while(leftover && leftover[i] != '\n')
		i++;
	line_found = ft_substr(leftover, 0, i);
	line = ft_strdup(line_found);
	free (line_found);
	return (line);
}

int get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*leftover;
	int			read_size;
	char 		*tmp_buf;
	int 		i;

	printf("CALL GNL\n\n");
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (leftover)
	{
		printf("leftover after previous call: %s\n", leftover);
		 if (ft_strchr(leftover, '\n'))
		{
			*line = line_in_leftover(*line, leftover);
			leftover = ft_strchr(leftover, '\n') + 1;
			printf("leftover after founding line in it: %s\n", leftover);
			return (1);
		}
		*line = ft_strjoin(*line, leftover);
	}
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buf[read_size] = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		tmp_buf = ft_substr(buf, 0, i);
		*line = ft_strjoin(*line, tmp_buf);
		free(tmp_buf);
		if (ft_strchr(buf, '\n'))
		{
			leftover = ft_strdup(ft_strchr(buf, '\n') + 1);
			break ;
		}
	}
	printf("leftover after readin loop: %s\n", leftover);
	if (read_size < 0)
		return (ft_free(leftover, -1));
		//return (-1);
	if ((leftover == NULL || leftover[0] == '\0') && read_size == 0)
		return (ft_free(leftover, 0));
		//return (0);
	return (1);
}

int main()
{
	char *line; //commence a 1 si pas assigné :D
	int fd;

	fd = open("texte.txt", O_RDONLY);
//MAC
	//printf("status output:%d\nline output:%s\n", get_next_line(fd, &line), line);
	//free(line);
	//printf("status output:%d\nline output:%s\n", get_next_line(fd, &line), line);
	//free(line);
	//printf("status output:%d\nline output:%s\n", get_next_line(fd, &line), line);
	//free(line);
	//printf("status output:%d\nline output:%s\n", get_next_line(fd, &line), line);
	//free(line);
	//LINUX VM
	printf("\033[0;31mline output:%s\n\033[0mstatus output:\033[0;31m%d\033[0m\n", line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline output:%s\n\033[0mstatus output:\033[0;31m%d\033[0m\n", line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline output:%s\n\033[0mstatus output:\033[0;31m%d\033[0m\n", line, get_next_line(fd, &line));
	free(line);
	printf("\033[0;31mline output:%s\n\033[0mstatus output:\033[0;31m%d\033[0m\n", line, get_next_line(fd, &line));
	free(line);
	return (0);
}
