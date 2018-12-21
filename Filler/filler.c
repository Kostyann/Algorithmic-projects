/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:10:46 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/20 13:11:27 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <limits.h>

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("txt.txt", O_RDONLY);
	get_next_line(fd, &line);
	if (line[10] == '1')
		ft_printf("%d %d\n", 1, 2);
	else if (line[10] == '2')
		ft_printf("%d %d\n", 4, 0);

//	ft_printf("%d %d\n", 1, 2);
	return (0);
}