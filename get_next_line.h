/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:36 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/09 14:12:21 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 32
# define BUF BUFF_SIZE + 1
#include "../libft/libft.h"

typedef struct		s_gnl
{
	char			*data;
	size_t			len;
	struct	s_list	*next;
}					t_gnl;

int	get_next_line(const int fd, char **line);
