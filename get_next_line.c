/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/02/13 14:31:43 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*gnl_lstnew(t_gnl *bl, size_t len, int fd)
{
	t_gnl	*new;

	if (!bl)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		new->data = (char *)malloc(sizeof(char *));
		ft_bzero(new->data, 1);
		new->len = len;
		new->fd = fd;
		new->next = NULL;
		return (new);
	}
	if (bl && bl->fd != fd)
		bl = gnl_lstnew(bl->next, len, fd);
	while (bl)
	{
		if (bl->fd == fd)
			return (bl);
		bl = bl->next;
	}
	return (NULL);
}

int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	static t_gnl	*bl;

	ft_bzero(t1, BUFF_SIZE + 1);
	if (!bl || bl->fd != fd)
		bl = gnl_lstnew(bl, BUFF_SIZE + 1, fd);
	while ((bl->bs = read(fd, t1, BUFF_SIZE)) || bl->data != 0)
	{
		if (!*t1 && bl->bs < 0)
			return (-1);
		if (*t1)
			bl->data = ft_strjoin(bl->data, t1);
		ft_bzero(t1, BUFF_SIZE + 1);
		if ((!bl->bs && *bl->data != '\0') || (ft_strchr(bl->data, '\n')))
		{
			*line = ft_strndup(bl->data, ft_wordlen(bl->data, '\n'));
			if ((bl->data = ft_strchr(bl->data, '\n')))
				bl->data++;
			return (1);
		}
		if (bl->bs == 0)
			return (0);
	}
	return (0);
}
