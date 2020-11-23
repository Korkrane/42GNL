/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:03:02 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/13 00:17:57 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


size_t	ft_strlen(const char *s);
char 	*ft_strdup(const char *s, size_t n);
char 	*ft_strcat(char *dest, const char *src);
char 	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_strchr(const char *s, int c);
char 	*ft_substr(char const *s, unsigned int start, size_t len);
int 	get_next_line(int fd, char **line);

#endif
