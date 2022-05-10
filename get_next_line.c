/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:39:38 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/10 12:28:17 by coder            ###   ########.fr       */
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
		//free(ptr);
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
		//printf("new_ptr\n");
		ft_strlcat(new_ptr, ptr, new_l);
		//free(ptr);
	}
	return (new_ptr);
}

char *ft_strconcat(char *s1, char *s2)
{
	char *str;
	int s1_l;
	int s2_l;
	int i;
	int j;

	i = 0;
	j = 0;
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = malloc((s1_l + s2_l + 1) * sizeof(char));
	if (!str || !s1 || !s2)
		return (NULL);
	while (i < s1_l)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_l)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char *aux;
	static char *line;
	int j;
	
	j = 0;
	if (!buff)
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff[BUFFER_SIZE] = '\0';

	int i = 1;
	while ((!(ft_strchr(line, '\n'))) || !EOF )
	{ //aux e buff
		printf("iteration: %d\n", i);
		read(fd, buff, BUFFER_SIZE);
		line = ft_strconcat(line, buff);
	//	aux = (char *) ft_my_realloc(line, BUFFER_SIZE, BUFFER_SIZE * i);
		i++;
		//line = (char *) ft_my_realloc(buff, BUFFER_SIZE, BUFFER_SIZE * i);
		
		//buff = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		//printf("buff: %s\n", buff);
		//j += ft_strlen(buff);
		//buff = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		//printf("j: %d\n", j);
		//printf("%s\n", buff);
		//line = (char *) ft_my_realloc(buff, BUFFER_SIZE + 1, j + 1);
		//ft_strlcat(line, buff, j + 1);
		printf("buff: %s\n", buff);
		//memset(aux, '\0', j);
		printf("line %s\n", line);
	}
	//printf("aquii %s\n", aux);
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
