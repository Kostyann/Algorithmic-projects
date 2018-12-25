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

#include <fcntl.h>

char 	**make_field(int fd, int i, int j)
{
	char	**res;
	int		k;

	k = -1;
	res = (char**)malloc(sizeof(char*) * (i + 1));
	while (++k < i && (get_next_line(fd, &res[k]) == 1))
	{
		if (res[k][0] >= '0' && res[k][0] <= '9')
			ft_memmove(res[k], &res[k][4], j + 1);
	}
	res[k] = 0;
	return (res);
}

void	fix_piece(char **piece, char num)
{
	int i = -1;
	int j;

	num = (num == '1') ? 'O' : 'X';
	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
			if (piece[i][j] == '*')
				piece[i][j] = num;
	}
}

char	find_me(char **piece)
{
	int i = -1;
	int j;

	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
			if (piece[i][j] != '.')
				return (piece[i][j]);
	}
	return (0);
}

#define ABS(x) ((x)<0 ? -(x) : (x))

int		find_dist(char **piece, int coord[2], int x, int y)
{
	int i = -1;
	int j;
	int dist;

	dist = 0;
	while (piece[++i])
	{
		j = -1;
		while (piece[i][++j])
			if (piece[i][j] != '.')
				dist += ABS(coord[0] + i - x + coord[1] + j - y);
	}
	return (dist);
}

int		try_place(char **piece, char **field, int x, int y)
{
	int n = 0;
	int i = -1;
	int j = -1;

	/*	while (*field)
				ft_printf("%s\n", *field++);
			while (*piece)
		ft_printf("%s\n", *piece++); */
	while (piece[++i])
	{
		if (!(field[x + i]))
			return (0);
		j = -1;
		while (piece[i][++j])
		{
			if (!(field[x + i][y + j]))
				return (0);
			if (piece[i][j] != '.')
			{
				if (field[x + i][y + j] == piece[i][j] ||
					 field[x + i][y + j] == piece[i][j] + 32)
					n++;
				else if (field[x + i][y + j] != '.')
					return (0);
			}
		}
	}
	if (n != 1)
		return (0);
	return (1);
}

int		ft_compare(char **piece, char **field, int prime[2], int temp[2])
{
	char me = find_me(piece);
	char he = (me == 'O') ? 'X' : 'O';
	int i = -1;
	int j;
	int p_dist;
	int t_dist;

	p_dist = 0;
	t_dist = 0;
	while (field[++i])
	{
		j = -1;
		while (field[i][++j]) {
			if (field[i][j] == he || field[i][j] == he + 32)
			{
				p_dist += find_dist(piece, prime, i, j);
				t_dist += find_dist(piece, temp, i, j);
			}
		}
	}
	if (t_dist < p_dist)
		return (1);
	return (0);
}

void	place_piece(char **field, char **piece, char num)
{
	int	prime[2] = {-1, -1};
	int temp[2] = {-1, -1};
	int i = -1;
	int j = -1;

	fix_piece(piece, num);
	while (field[++i])
	{
		j = -1;
		while (field[i][++j])
		{
			if (try_place(piece, field, i, j))
			{
				temp[0] = i;
				temp[1] = j;
				if (prime[0] == -1 || ft_compare(piece, field, prime, temp))
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
	int 	x;
	int 	y;
	char 	pl_num;
	char 	**field;
	char 	**piece;

	x = 0;
//	fd = open("test.txt", O_RDONLY);
	fd = 0;

	if ((get_next_line(fd, &line) == 1))
	{
		pl_num = line[10];
		free(line);
	}
	while ((get_next_line(fd, &line) == 1))
		{
			x = ft_atoi(&line[8]);
			y = ft_atoi(&line[8 + ft_digits(x) + 1]);
			free(line);
			get_next_line(fd, &line);
			field = make_field(fd, x, y);
			free(line);
			get_next_line(fd, &line);
			x = ft_atoi(&line[6]);
			y = ft_atoi(&line[6 + ft_digits(x) + 1]);
			piece = make_field(fd, x, y);
			free(line);
			place_piece(field, piece, pl_num);
		}

	return (0);
}