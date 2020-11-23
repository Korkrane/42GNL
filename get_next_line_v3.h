/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v3.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:03:02 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/23 12:24:08 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_V3
#define GET_NEXT_LINE_H_V3

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


size_t	ft_strlen(const char *s);
char 	*ft_strdup(const char *s);
char 	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strchr(const char *s, int c);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
int 	get_next_line(int fd, char **line);

#endif
