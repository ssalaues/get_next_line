/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/01 21:17:50 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	get_next_line(const int fd, char **line)
{
	char 			t1[BUFF_SIZE];
t2	char			*t2;
	static t_list	*rdin;

//	t1 = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(t1, BUFF_SIZE);
	while (read(fd, t1, BUFF_SIZE))
		{
			rdin = ft_lstnew(t1, BUFF_SIZE + 1);
			if (!rdin->content)
				return (-1); //Nothing has been read?
			while (*(char*)(rdin->content) != '\n' && *rdin->content)
				*line++ = rdin->content++;//Transfer buf into line
			if (*(rdin->content) == '\n')
				return (1); //Reached end of line
//			t2 = (char *)malloc(sizeof(char) * (ft_wordlen(t1, '\n') + 1));
//			t2 = ft_strchr(t1,'\n');//Copy the rest of buf into t2
//			while (*t2 != '\n' && *t2)
//				*line++ = t2++;//if there is anything left
//			if (!t2)
//				free(t2);
		}
	return (0); //Reading completed
}*/

int	get_next_line(const int fd, char **line)
{
	char			t1[BUFF_SIZE + 1];
	char			*t2;
	size_t			ct;
	static t_list	*rdin;

	ct = 1;
	t2 = ft_strnew(ft_strlen(t2) + BUFF_SIZE + 1);
	while (read(fd, t1, BUFF_SIZE))
	{
		ft_strncat(t2, t1, ft_wordlen(t1, '\n') + ft_strlen(t2));//Copy to first \n if found
		if (ft_strchr(t1, '\n'))
		{
			*line = t2;
			return (1);	
		}
		ct++;
	}
	return (0); //Reading Complete EOF
}
