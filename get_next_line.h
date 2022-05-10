/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:23:33 by mcerquei          #+#    #+#             */
/*   Updated: 2022/05/10 23:36:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
