/*

// struct
	fd
	conteudo
	ptr prox

// cria um no
// adc conteudo no no
// deleta conteudo e no -> se erro
// itera os nos 
*/

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	char			*buffer;
	char			*line;
	int 			validation;
	t_lst			*node;
	static	t_lst	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	node = ft_iterfd(lst, fd);
	if (!node)
		node = ft_add_new_node(lst, fd);
	if (!lst)
		lst = node;
	validation = 1;
	while ((!ft_strchr(node->accumulator, '\n')) && validation > 0)
	{
		validation = read(fd, buffer, BUFFER_SIZE);
		// cheguei no fim do arquivo
			// mas sera que acabou tudo que tinha pra ler ????
		if (validation <= 0)
		{
			ft_delnode(lst, node, fd);
			//free(buffer);
			return (NULL);
		}
		buffer[validation] = '\0';
		node->accumulator = get_remainder(node->accumulator);
	}
	free(buffer);
	line = get_line(buffer);
	node->accumulator = get_remainder(node->accumulator);
	return (line);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str || !str[0])
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
	if (!str || !str[i])
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

// funcao que itera a lista procurando por um fd
	// se nao encontrar cria um novo no
	// se encontrar retorna o no buscado

t_lst	*ft_add_new_node(t_lst *lst, int fd)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(1 * sizeof(t_lst));
	if (!new_node)
		return (NULL);
	*(new_node->accumulator) = '\0';
	new_node->fd = fd;
	new_node->next = NULL;
	new_node->prev = NULL;
	/* inicializa lst */
	// acha o fim da lista
	while (lst->next)
		lst = lst->next;
	// prev eh o ultimo elemento
	new_node->prev = lst;
	// next eh o no adicionado
	lst->next = new_node;
	return (new_node);
}

t_lst	*ft_iterfd(t_lst *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
