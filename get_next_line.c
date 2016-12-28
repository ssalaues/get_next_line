/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/27 19:02:23 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char 			*t1;
//	char			*t2;
	static t_list	*rdin;
	
	t1 = ft_strnew(BUFF_SIZE + 1);
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
}
