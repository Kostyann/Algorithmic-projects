/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:25:52 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/14 15:25:54 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		power_two(int power)
{
	if (power > 0)
		return (2 * (power_two(power - 1)));
	return (1);
}

void	print_field(char **field)
{
	int i;
	int j;

	i = -1;
	while (field[++i])
	{
		j = -1;
		while (field[i][++j])
			write(1, &field[i][j], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	save_tet(int t)
{
	int i[3];

	i[0] = -1;
	g_coord = (int **)malloc(sizeof(int*) * t);
	while (++(i[0]) < t)
		g_coord[i[0]] = (int *)malloc(sizeof(int) * 9);
	while (--t >= 0)
	{
		g_coord[t][0] = t;
		i[0] = -1;
		i[2] = -1;
		while (++(i[0]) < 4)
		{
			i[1] = -1;
			while (++(i[1]) < 4)
			{
				if (g_comb_numbs[t][0] & (power_two(i[0] * 4 + i[1])))
				{
					g_coord[t][++(i[2]) * 2 + 1] = i[0];
					g_coord[t][i[2] * 2 + 2] = i[1];
				}
			}
		}
	}
}
