#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst
{
	int					fd;
	char				*accumulator;
	struct s_lst		*next;
	struct s_lst		*prev;
} t_lst;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*get_line(char *str);
char	*get_remainder(char *str);
t_lst	*ft_add_new_node(t_lst *lst, int fd);
t_lst	*ft_iterfd(t_lst *node, int fd);
void	ft_delnode(t_lst *lst, t_lst *node, int fd);

#endif