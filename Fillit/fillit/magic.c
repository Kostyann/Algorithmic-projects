/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:11:27 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:30 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int num)
{
	int i;

	i = 0;
	while (i * i < num)
		i++;
	return (i);
}

char	**create_field(int t)
{
	int		i;
	int		j;
	char	**field;

	if (!(field = (char **)malloc(sizeof(char**) * (t + 1))))
		return (NULL);
	i = -1;
	while (++i < t)
	{
		field[i] = ft_strnew(t);
		j = -1;
		while (++j < t)
			field[i][j] = '.';
	}
	field[i] = NULL;
	return (field);
}

#define FR (*field)[fi + coord[i * 2 + 1]]
#define FREE (*field)[fi + coord[i * 2 + 1]][fj + coord[i * 2 + 2]]

int		check_free(char ***field, int fi, int fj, int *coord)
{
	int i;

	i = -1;
	while (++i < 4)
		if (!FR || !FREE || FREE != '.')
			return (0);
	while (--i >= 0)
		FREE = 'A' + coord[0];
	return (1);
}

void	clear_tets(char ***field, int fi, int fj, int *coord)
{
	int i;

	i = 4;
	while (--i >= 0)
		FREE = '.';
}

int		place_tets(char ***field, int quant, int to_place)
{
	int t;
	int i;
	int j;

	if (to_place == 0)
		return (1);
	t = quant - to_place;
	i = -1;
	while ((*field)[++i])
	{
		j = -1;
		while ((*field)[i][++j])
		{
			if (check_free(field, i, j, g_coord[t]))
			{
				if (!place_tets(field, quant, to_place - 1))
					clear_tets(field, i, j, g_coord[t]);
				else
					return (1);
			}
		}
	}
	return (0);
}
