/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 04:43:22 by coder             #+#    #+#             */
/*   Updated: 2022/05/11 09:53:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{	
	//char		*buffer;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*accumulator;	
	int			validation;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	validation = 1;
	//buffer = check_buffer();
	while ((!ft_strchr(buffer, '\n')) && validation > 0)
	{
		validation = read(fd, buffer, BUFFER_SIZE);
		if (validation <= 0)
		{
			//free(buffer);
			return (NULL);
		}
		buffer[validation] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
	}
	//free(buffer);
	line = get_line(accumulator);
	accumulator = get_remainder(accumulator);
	return (line);
}

/*
char	*check_buffer(void)
{
	char	*buffer;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}
*/

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *) malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	remainder = (char *)malloc((sizeof(char) * (ft_strlen(str) - i + 1)));
	if (!remainder)
		return (NULL);
	while (str[i])
		remainder[j++] = str[i++];
	remainder[j] = '\0';
	free(str);
	return (remainder);
}
