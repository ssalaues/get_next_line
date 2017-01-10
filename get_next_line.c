/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/09 16:54:26 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	char			*t2;
	size_t			ct;
	size_t			ct2 = 0;
//	static t_list	*rdin;

	ct = 0;
	bzero(t1, BUFF_SIZE + 1);
	t2 = ft_strnew(BUFF_SIZE + 1);
	while (read(fd, t1, BUFF_SIZE))
	{
		ct = ft_strlen(t2);
		ct2 = ft_wordlen(t1, '\n');
		t2 = ft_strncat(t2, t1, ct2);//ft_wordlen(t1, '\n') + ft_strlen(t2));//Copy to first \n if found
		if (ft_strchr(t1, '\n'))
		{
			*line = t2;
			return (1);	
		}
	}
	return (0); //Reading Complete EOF
}*/
// With Lists
static char	*ft_strndup(const char *s1, size_t n)
{
	char *dup;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	else
		ft_strncpy(dup, s1, n);
	return (dup);
}
int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	size_t			bs = 0;
	int				ct = 0;
	static t_list	*rdin;

	ft_bzero(t1, BUFF_SIZE + 1);
	while((bs = read(fd, t1, BUFF_SIZE)))
	{
		if (ct == 0)
			rdin = ft_lstnew((char*)t1, bs + 1);
//		rdin->content = ft_strncat(rdin->content, t1, ft_wordlen(t1, '\n'));
		if (ft_strchr(t1, '\n'))
		{
			*line = ft_strndup(rdin->content, ft_wordlen(rdin->content, '\n'));
			free(rdin->content);
			return (1);
		}
		ct++;
	}
	return (0);
}
