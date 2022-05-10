/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:56:59 by coder             #+#    #+#             */
/*   Updated: 2022/05/11 00:10:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{	
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;	
	int			i;
	
	line = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	while ((!ft_strchr(buffer, '\n')) && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			return (NULL); // ?????
		buffer[i] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}