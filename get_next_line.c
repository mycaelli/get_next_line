/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:39:38 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/05 18:45:21 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = NULL;
	while (s[i])
		i++;
	cpy = malloc(i + 1 * sizeof(char));
	if (!cpy)
		return (NULL);
	while (j <= i)
	{
		cpy[j] = s[j];
		j++;
	}
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	s_len;
	unsigned int	sub_len;

	s_len = ft_strlen(s);
	i = 0;
	sub = NULL;
	if (start > s_len)
		return (ft_strdup(""));
	sub_len = ft_strlen(&s[start]);
	if (len > sub_len)
		len = sub_len;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}


char	*get_next_line(int fd)
{
	static char	*buff;
	int j;

	if (!buff)
		buff = ft_calloc((BUFFER_SIZE + 2), sizeof(char));
	j = ft_newline(buff);
	buff += j;
	if (!buff || fd < 0 || BUFFER_SIZE <= 0)
	{
		//printf("aqui");
		return (NULL);
	}
	while ((!ft_strchr(buff, '\n') || !EOF) && buff[BUFFER_SIZE] != 1)
	{
		buff[BUFFER_SIZE] = 1;
		read(fd, buff, BUFFER_SIZE);
	}
	buff[BUFFER_SIZE + 1] = '\0';
	j = ft_newline(buff);
	return (ft_substr(buff, 0, j));
}
