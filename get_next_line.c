/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:39:38 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/04 22:03:17 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char *str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	int size;
	int temp;

	buff =  NULL;
	//str = NULL;
	size = 0;
	temp = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n'))
	{
		read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff);
		temp = ft_strlen(str);
		printf("temp: %d\n", temp);
	}
	size = ft_strlen(str);
	printf("len: %d\n", size);
	return (str);
}
