/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:39:38 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/10 02:07:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

//free the lines that were already read
/*void free_line(char *s, int j)
{
	int i;

	i = 0;
	while (i <= j)
	{
		free(&s[i]);
		i++;
	}
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((const char *) src)[i];
		i++;
	}
	return (dest);
}

void *ft_my_realloc(void *ptr, size_t original_l, size_t new_l)
{
	void *new_ptr;

	if (new_l == 0)
	{
		printf("new_l == 0\n");
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		printf("!ptr\n");
		return (malloc(new_l));
	}
	if (new_l <= original_l)
	{
		printf("new_l <= original\n");
		return (ptr);
	}
	new_ptr = malloc(new_l);
	//free(ptr);
	if (new_ptr)
	{
		printf("new_ptr\n");
		ft_strlcat(new_ptr, ptr, new_l);
		//free(ptr);
	}
	return (new_ptr);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char *aux;
	char *line;
	int j;
	
	j = 0;
	if (!buff)
		buff = malloc((BUFFER_SIZE) * sizeof(char));
	//buff[BUFFER_SIZE] = '\0';

	int i = 0;
	while ((!(ft_strchr(buff, '\n'))) || !EOF )
	{
		printf("iteration: %d\n", i);
		i++;
		read(fd, buff, BUFFER_SIZE);
		//buff = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		//printf("buff: %s\n", buff);
		j += ft_strlen(buff);
		//printf("j: %d\n", j);
		//printf("%s\n", buff);
		aux = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		printf("buff: %s\n", buff);
		//memset(aux, '\0', j);
		printf("aux %s\n", aux);
	}
	//ft_strlcat(aux, buff, j);
	//printf("line: %s\n", line);
	
	
	return(NULL);
	
	/*
	//line = malloc((BUFFER_SIZE)* sizeof(char));
	if (!buff || !line || fd < 0 || BUFFER_SIZE <= 0)
	{	
		printf("something failed\n");
		return (NULL);
	}
	while ((!(ft_strchr(line, '\n'))))
	{
		read(fd, buff, BUFFER_SIZE);
		printf("%s\n", buff);
		j = ft_strlen(buff);
		line = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		line = ft_strncat(line, buff, BUFFER_SIZE);
	}
	//	printf("line after: %s\n", line);
		printf("********** FORA LOOP\n");
		printf("\n");
        return (line);*/
}
