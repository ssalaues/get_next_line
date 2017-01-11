/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/10 19:47:51 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*ft_strndup(const char *s1, size_t n)
{
	char *dup;

	dup = ft_memalloc(n + 1);
	if (!dup)
		return (NULL);
	else
		ft_strncpy(dup, s1, n);
	return (dup);
}
int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
    char            *t2;
	size_t			bs = 0;
	int				ct = 0;
	static t_list	*rdin;

	ft_bzero(t1, BUFF_SIZE + 1);
	while((bs = read(fd, t1, BUFF_SIZE)))
	{
		if (ct == 0)
			rdin = ft_lstnew((char*)t1, bs + 1);
		else
			{
            t2 = ft_strndup(ft_strncat(rdin->content, t1, ft_strlen(rdin->content) + bs), ft_strlen(rdin->content) + bs);
			free(rdin->content);
			rdin->content = t2;
            free(t2);
			}
		if (ft_strchr(t1, '\n'))
		{
			*line = ft_strndup(rdin->content, ft_wordlen(rdin->content, '\n'));
//			free(rdin->content);
			return (1);
		}
		ct++;
	}
	return (0);
}
