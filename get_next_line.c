/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/06 22:41:44 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static  char *ft_restr(char *old, char *new)
{
	char *rt;

	rt = ft_strnew(ft_strlen(old) + BUFF_SIZE + 1);
	rt = ft_strncat(old, new, ft_wordlen(new, '\n') + ft_strlen(old));
	if (*old)
		free(old);
	return(rt);
}
//static char *ft_strndup(const char *s1, size_t n)
//{
//}

int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	char			*t2;
	size_t			ct;
	size_t			ct2 = 0;
	static t_list	*rdin;

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
}
