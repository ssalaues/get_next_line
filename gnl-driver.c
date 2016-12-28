/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl-driver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 14:33:35 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/27 18:04:33 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "./includes/get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd = 0;
	char *line;
	fd = open(av[1], O_RDONLY);	
	get_next_line(fd, &line);
	printf("%s", line);
}
