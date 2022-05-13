/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 03:07:55 by acosta-a          #+#    #+#             */
/*   Updated: 2022/05/09 20:03:12 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*get_line(char	*text);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*get_newtext(char	*text);
char	*ft_strdup(const char *s);
char	*check_buffer(void);

#endif
