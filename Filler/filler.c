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
#include "filler.h"

#include <fcntl.h>

int		try_place(int **piece, int **field, int x, int y)
{
	int n;
	int i;
	int j;

	i = -1;
	n = 0;
	while (piece[++i])
	{
		if (!(field[x + i]))
			return (0);
		j = -1;
		while (piece[i][++j])
		{
			if (!(field[x + i][y + j]))
				return (0);
			if (piece[i][j] == -1)
			{
				if (field[x + i][y + j] == -1)
					n++;
				else if (field[x + i][y + j] == -2)
					return (0);
			}
		}
	}
	return (n == 1 ? 1 : 0);
}

int		ft_dist(int **piece, int **field, int k, int n)
{
	int i;
	int j;
	int dist;

	i = -1;
	dist = 0;
	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
			if (piece[i][j] == -1)
				dist += field[k + i][n + j];
	}
	return (dist);
}

void	place_piece(int **field, int **piece)
{
	int	prime[2];
	int dist;
	int temp;
	int i;
	int j;

	prime[0] = -1;
	prime[1] = -1;
	i = -1;
	while (field[++i])
	{
		j = -1;
		while (field[i][++j])
		{
			if (try_place(piece, field, i, j) && ((prime[0] == -1) ||
				(temp = ft_dist(piece, field, i, j)) < dist))
			{
				prime[0] = i;
				prime[1] = j;
				dist = (temp > 0) ? temp : ft_dist(piece, field, i, j);
			}
		}
	}
	ft_printf("%d %d\n", prime[0], prime[1]);
}

void	filler(int fd, char en_num, int xy[2])
{
	char	*line;
	int		**field;
	int		**piece;

	while ((get_next_line(fd, &line) == 1))
	{
		xy[0] = ft_atoi(&line[8]);
		xy[1] = ft_atoi(&line[8 + ft_digits(xy[0]) + 1]);
		free(line);
		get_next_line(fd, &line);
		field = make_field(en_num, fd, xy[0], xy[1]);
		free(line);
		get_next_line(fd, &line);
		xy[0] = ft_atoi(&line[6]);
		xy[1] = ft_atoi(&line[6 + ft_digits(xy[0]) + 1]);
		piece = make_field(en_num, fd, xy[0], xy[1]);
		free(line);
		map_field(field);
		place_piece(field, piece);
		free_field(field);
		free_field(piece);
	}
}

int		main(void)
{
	char	*line;
	int		xy[2];
	char	en_num;

	xy[0] = 0;
	xy[1] = 0;
	en_num = 0;
	if ((get_next_line(0, &line) == 1))
	{
		en_num = line[10];
		free(line);
		en_num = (en_num == '1') ? 'X' : 'O';
	}
	filler(0, en_num, xy);
	return (0);
}
