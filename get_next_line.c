/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/02/03 18:52:38 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl_lstnew(char const *data, size_t len, int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->data = ft_memalloc(len);
	ft_bzero(new->t1, len);
	new->len = len;
	new->fd = fd;
	new->next = NULL;
	return (new);
}
int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	static t_gnl	*bl;

	ft_bzero(t1, BUFF_SIZE + 1);
	if (fd < 0)
		return (-1);
	if (!bl)
		bl = gnl_lstnew("", BUFF_SIZE + 1, fd);
	while((bl->bs = read(fd, t1, BUFF_SIZE)) || bl->data != '\0')
	{
		bl->t2 = ft_strjoin(bl->data, t1);
		ft_bzero(t1, BUFF_SIZE + 1);
		bl->data = bl->t2;
		if (ft_strchr(bl->t2, '\n') || bl->bs)
		{
			*line = ft_strndup(bl->data, ft_wordlen(bl->data, '\n'));
			bl->data = ft_strchr(bl->data, '\n');
			bl->data++;
			return (1);
		}
		if (bl->bs == 0)
			return (0);
	}
	return (0);
}
