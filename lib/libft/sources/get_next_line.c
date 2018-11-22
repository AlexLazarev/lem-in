/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:48:27 by alazarev          #+#    #+#             */
/*   Updated: 2018/05/10 19:49:01 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "libft.h"

t_list	*ft_find(t_list *storage, size_t fd)
{
	while (storage)
	{
		if (storage->content_size == fd)
			return (storage);
		storage = storage->next;
	}
	return (NULL);
}

t_list	*ft_create(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	node->content = (void*)content;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}

int		ft_line_fill(t_list *node, char **line)
{
	char	*index;
	int		len;

	index = ft_strchr((char*)node->content, '\n');
	if (index)
	{
		len = index - ((char*)node->content);
		if (!(*line = ft_strrealloc(&(*line), len)))
			return (-1);
		ft_strncat(*line, (char*)node->content, len);
		ft_memmove(node->content, index + 1, ft_strlen(index));
		return (1);
	}
	if ((len = ft_strlen((char*)node->content)))
	{
		if (!(*line = ft_strrealloc(&(*line), len)))
			return (-1);
		ft_strcat(*line, (char*)node->content);
		*(char*)node->content = '\0';
	}
	return (0);
}

int		ft_norm(int fd, t_list **node, char **line)
{
	int ret;
	int	error;

	*line = NULL;
	if (!(*node)->content)
		return (0);
	if ((error = ft_line_fill(*node, line)))
		return (error);
	while ((ret = read(fd, (char*)(*node)->content, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		((char*)(*node)->content)[ret] = 0;
		if ((error = ft_line_fill(*node, line)))
			return (error);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*storage = NULL;
	t_list			*node;
	int				error;

	if (BUFF_SIZE < 0 || !line || read(fd, 0, 0) < 0 || fd > 5000)
		return (-1);
	if (!storage)
		storage = ft_create(ft_strnew(BUFF_SIZE), fd);
	node = ft_find(storage, fd);
	if (!node)
	{
		node = ft_create(ft_strnew(BUFF_SIZE), fd);
		ft_lstadd(&storage, node);
	}
	if ((error = ft_norm(fd, &node, line)))
		return (error);
	if (*line)
		return (1);
	return (0);
}
