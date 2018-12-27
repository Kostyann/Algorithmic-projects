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
	if (n != 1)
		return (0);
	return (1);
}

int		ft_closer(int **piece, int **field, int prime[2], int temp[2])
{
	int i;
	int j;
	int p_dist;
	int t_dist;

	i = -1;
	p_dist = 0;
	t_dist = 0;
	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
		{
			if (piece[i][j] == -1)
			{
				p_dist += field[prime[0] + i][prime[1] + j];
				t_dist += field[temp[0] + i][temp[1] + j];
			}
		}
	}
	if (t_dist < p_dist)
		return (1);
	return (0);
}

void	place_piece(int **field, int **piece)
{
	int	prime[2] = {-1, -1};
	int temp[2] = {-1, -1};
	int i;
	int j;

	i = -1;
	while (field[++i])
	{
		j = -1;
		while (field[i][++j])
		{
			if (try_place(piece, field, i, j))
			{
				temp[0] = i;
				temp[1] = j;
				if (prime[0] == -1 || ft_closer(piece, field, prime, temp))
				{
					prime[0] = temp[0];
					prime[1] = temp[1];
				}
			}
		}
	}
	if (prime[0] == -1)
	{
		prime[0] = 0;
		prime[1] = 0;
	}
	ft_printf("%d %d\n", prime[0], prime[1]);
}

int		main(void)
{
	char	*line;
	int		fd;
	int 	xy[2] = {0, 0};
	char	en_num;
	int 	**field;
	int 	**piece;

//	fd = open("test.txt", O_RDONLY);
	fd = 0;

	if ((get_next_line(fd, &line) == 1))
	{
		en_num = line[10];
		free(line);
		en_num = (en_num == '1') ? 'X' : 'O';
	}
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
		}

	return (0);
}