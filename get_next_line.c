/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/23 21:08:21 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char 	t1[BUFF_SIZE + 1];
	char	*t2;
	size_t	ct;
	t_list	*rdin;

	while (read(fd, t1, BUFF_SIZE))
		{
			if (!t1)
				return (-1); //Nothing has been read?
			while (*t1 != '\n' && *t1)
				*line++ = *t1++;//Transfer buf into line
			if (*t1 == '\n')
				return (1); //Reached end of line
			t2 = (char *)malloc(sizeof(char) * (ft_wordlen(t1, '\n') + 1));
			t2 = ft_strchr(t1,'\n');//Copy the rest of buf into t2
			while (*t2 != '\n' && *t2)
				*line++ = *t2++;//if there is anything left
			if (!t2)
				free(t2);
		}
	return (0); //Reading completed
}
