/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:36 by ssalaues          #+#    #+#             */
/*   Updated: 2017/02/11 22:00:35 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 16
# include "./libft/libft.h"

typedef struct		s_gnl
{
	char			*data;
	char			t1[BUFF_SIZE + 1];
	char			*t2;
	int				used;
	int				fd;
	int				bs;
	size_t			len;
	struct	s_gnl	*next;
}					t_gnl;

int	get_next_line(const int fd, char **line);
