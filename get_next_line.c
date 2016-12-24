/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/23 17:57:52 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(const int fd, char **line)
{
	char *tmp;

	read(fd, tmp, BUFF_SIZE);
	if (!tmp)
		return (0); //Nothing has been read?
}
