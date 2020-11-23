/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:24:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/23 15:38:49 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v3.h"
#include <string.h>
/*
int check_leftover(char *line, char *leftover)
{
	int i;
	char *line_found;

	i = 0;
	if(ft_strchr(leftover, '\n'))
	{
		printf("leftover before :%s\n", leftover);
		while(leftover && leftover[i] != '\n')
			i++;
		line_found = ft_substr(leftover, 0, i);
		printf("line_found:%s\n",  line_found);
		line = ft_strdup(line_found);
		printf("line during check:%s\n", line);
		leftover = ft_strchr(leftover, '\n') + 1;
		printf("leftover after :%s\n", leftover);
		//free (line_found);
		if(leftover == NULL)
			return (0);
		return (0);
	}
	else
		line = leftover;
	return (0);
}
*/
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

	char *tmp_buf;
	int i;
	printf("CALL GNL\n\n");
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (leftover)
	{
	/*	if(check_leftover(*line, leftover) == 0)
		{
			printf("line after check:%s\n", *line);
			return (0);
		}
		*/
		 if(ft_strchr(leftover, '\n'))
		{
			*line = line_in_leftover(*line, leftover);
			leftover = ft_strchr(leftover, '\n') + 1;
			return (1);
		}
		else
			*line = leftover;
	}
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buf[read_size] = 0;
		while(buf[i] && buf[i] != '\n')
			i++;
		tmp_buf = ft_substr(buf, 0, i);
		*line = ft_strjoin(*line, tmp_buf);
		free(tmp_buf);
		if (ft_strchr(buf, '\n'))
		{
			leftover = ft_strdup(ft_strchr(buf, '\n') + 1);
			break;
		}
		if(read_size == 0 && leftover[0] == '\0')
		{
			*line = ft_strdup("");
			return (0);
		}
	}
	return (1);
}

int main()
{
	char *line; //commence a 1 si pas assigné :D
	int fd;

	fd = open("texte.txt", O_RDONLY);

	get_next_line(fd, &line);
	printf("line on main output :%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("line on main output :%s\n", line);
	free(line);
	get_next_line(fd, &line);
	printf("line on main output :%s\n", line);
	free(line);
	//get_next_line(fd, &line);
	//printf("line on main output :%s\n", line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	return (0);
}
