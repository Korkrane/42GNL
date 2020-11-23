/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:24:58 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/12 23:59:52 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v3.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s, size_t n)
{
	size_t		i;
	char		*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	while (i < n)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strcat(char *dest, char const *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fillstr;
	int		tot_len;
	char	*emptystr;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	if (tot_len == 0)
	{
		emptystr = malloc(sizeof(char) * 1);
		emptystr[0] = '\0';
		return (emptystr);
	}
	fillstr = malloc(sizeof(char) * tot_len + 1);
	if (!fillstr)
		return (NULL);
	fillstr[0] = '\0';
	ft_strcat(fillstr, s1);
	ft_strcat(fillstr, s2);
	fillstr[tot_len] = '\0';
	return (fillstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

int get_next_line(int fd, char **line)
{
	static int test_output_call = 1;

	char		buf[BUFFER_SIZE + 1];
	static char	*leftover;
	char		*line_found_in_leftover;
	int			read_size;
	int			i;

	i = 0;
	printf("\033[0;31mGNL call n°%d...\n\n", test_output_call);
	printf("\033[0m");
	if (leftover)
	{
		printf("Leftover found...\nChecking for line inside of leftover...\n");
		*line = ft_strdup(leftover, ft_strlen(leftover));
		if (ft_strchr(leftover, '\n'))
		{
			line_found_in_leftover = malloc(sizeof(char) * ft_strlen(leftover + 1));
			while(leftover[i] && leftover[i] != '\n')
			{
				line_found_in_leftover[i] = leftover[i];
				i++;
			}
			printf("Have found a line in leftover...\n");
			line_found_in_leftover[i] = '\0';
			leftover = ft_strchr(leftover, '\n') + 1;
			*line = ft_strdup(line_found_in_leftover, ft_strlen(line_found_in_leftover));
			printf("my line %d :%s\n", test_output_call, *line);
			printf("my leftover %d :%s\n", test_output_call, leftover);
			test_output_call++;
			return(0);
		}
		printf("Did not found line in leftover...\n\n");
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
		*line = ft_strcat(*line, tmp_buf);
		if (ft_strchr(buf, '\n'))
		{
			leftover = ft_strchr(buf, '\n') + 1;
			break;
		}
		printf("my buffer %d :%s\n", test_output_call, buf);
	}
	printf("\nmy last buffer %d :%s\n", test_output_call, buf);
	printf("my line %d :%s\n", test_output_call, *line);
	printf("my leftover %d :%s\n", test_output_call, leftover);
	test_output_call++;
	return (0);
}

int main()
{
	char *line;
	int fd;

	fd = open("texte.txt", O_RDONLY);

	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
}
