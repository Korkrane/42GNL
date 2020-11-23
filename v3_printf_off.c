/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_printf_off.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:24:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/23 12:30:59 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v3.h"
#include <string.h>

int get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*leftover;
	char		*line_found_in_leftover;
	int			read_size;
	int			i;

	i = 0;
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (leftover)
	{
		*line = ft_strdup(leftover);
		if (ft_strchr(leftover, '\n'))
		{
			line_found_in_leftover = malloc(sizeof(char) * ft_strlen(leftover + 1));
			if(!line_found_in_leftover)
				return (-1);
			while(leftover[i] && leftover[i] != '\n')
			{
				line_found_in_leftover[i] = leftover[i];
				i++;
			}
			line_found_in_leftover[i] = '\0';
			leftover = ft_strchr(leftover, '\n') + 1;
			*line = ft_strdup(line_found_in_leftover);
			free(line_found_in_leftover);
			return(1);
		}
	}
	char *tmp_buf;
	int j;
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		j = 0;
		buf[read_size] = 0;
		while(buf[j] && buf[j] != '\n')
			j++;
		tmp_buf = ft_substr(buf, 0, j);
		*line = ft_strjoin(*line, tmp_buf);
		free(tmp_buf);
		if (ft_strchr(buf, '\n'))
		{
			leftover = ft_strdup(ft_strchr(buf, '\n') + 1);
			break;
		}
		if(read_size == 0 && (leftover == NULL || leftover[0] == '\0'))
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
	//get_next_line(fd, &line);
	//printf("line on main output :%s\n", line);
	//get_next_line(fd, &line);
	//printf("line on main output :%s\n", line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	return (0);
}
