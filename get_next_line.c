/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/25 16:09:58 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl_lstnew(char const *data, size_t len, int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->data = ft_memalloc(len);
	new->len = len;
	new->fd = fd;
	new->next = NULL;
	return (new);
}
int	get_next_line(const int fd, char **line)
{
//	char			t1[BUFF_SIZE + 1];
	static t_gnl	*bl;

//	ft_bzero(t1, BUFF_SIZE + 1);
	if (bl->fd == 0)
		bl = gnl_lstnew("", BUFF_SIZE + 1, fd);
	while((bl->bs = read(bl->fd, bl->t1, BUFF_SIZE)))
	{
		if (bl->bs < 0)
			return (-1);
		else
		{
			bl->t2 = ft_strjoin(bl->data, bl->t1);
			bl->data = bl->t2;
		}
		if (ft_strchr(bl->t1, '\n'))
		{
			*line = ft_strndup(bl->data, ft_wordlen(bl->data, '\n'));
			bl->data = ft_strchr(bl->data, '\n');
			bl->data++;
			return (1);
		}
		ft_bzero(bl->t1, BUFF_SIZE + 1);
	}
	return (0);
}
