/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:12:53 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/27 12:12:55 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "filler.h"

void	free_field(int **field)
{
	int i = -1;

	while (field[++i])
		free(field[i]);
	free(field);
}

int 	**make_field(char en_num, int fd, int i, int j)
{
	char	*line;
	int		**res;
	int		k;
	int 	n;

	k = -1;
	res = (int**)malloc(sizeof(int*) * (i + 1));
	while (++k < i && (get_next_line(fd, &line) == 1))
	{
		if (line[0] >= '0' && line[0] <= '9')
			ft_memmove(line, &line[4], j + 1);
		res[k] = (int*)malloc(sizeof(int) * (j + 1));
		n = -1;
		while (line[++n])
		{
			if (line[n] == '.')
				res[k][n] = 42;
			else if (line[n] == en_num || line[n] == en_num + 32)
				res[k][n] = -2;
			else
				res[k][n] = -1;
		}
		res[k][n] = 0;
		free(line);
	}
	res[k] = 0;
	return (res);
}

void	map_field(int **field)
{
	int i;
	int j;
	int go = 1;
	int num = -1;

	while (num < 70)
	{
		go = 0;
		i = -1;
		num++;
		while (field[++i])
		{
			j = -1;
			while (field[i][++j])
			{
				if (field[i][j] == -2 || field[i][j] == num)
				{
					if (i > 0)
					{
						if (j > 0 && field[i - 1][j - 1] == 42)
							field[i - 1][j - 1] = num + 1;
						if (field[i - 1][j] == 42)
							field[i - 1][j] = num + 1;
						if (field[i - 1][j + 1] && field[i - 1][j + 1] == 42)
							field[i - 1][j + 1] = num + 1;
					}
					if (j > 0 && field[i][j - 1] == 42)
						field[i][j - 1] = num + 1;
					if (field[i][j + 1] && field[i][j + 1] == 42)
						field[i][j + 1] = num + 1;
					if (field[i + 1])
					{
						if (j > 0 && field[i + 1][j - 1] == 42)
							field[i + 1][j - 1] = num + 1;
						if (field[i + 1][j] == 42)
							field[i + 1][j] = num + 1;
						if (field[i + 1][j + 1] && field[i + 1][j + 1] == 42)
							field[i + 1][j + 1] = num + 1;
					}
				}
			}

		}
	}
}