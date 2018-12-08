/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:34:41 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/13 15:34:42 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tet(int *list)
{
	int q;
	int sosedi;

	q = 0;
	sosedi = 0;
	while (++q <= 4)
	{
		if (!(list[q] & 0x8888) && list[q] * 2 & list[0])
			sosedi++;
		if (!(list[q] & 0x1111) && list[q] / 2 & list[0])
			sosedi++;
		if (list[q] * 16 & list[0])
			sosedi++;
		if (list[q] / 16 & list[0])
			sosedi++;
	}
	if (sosedi != 6 && sosedi != 8)
		return (0);
	while (!(list[0] & 0x000f))
		list[0] /= 16;
	while (!(list[0] & 0x1111))
		list[0] /= 2;
	return (1);
}

int		check_valid(char *buf, int i, int j)
{
	int k;
	int q;
	int g;

	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n'
		|| buf[i - 1] != '\n')
		return (0);
	k = -1;
	q = 1;
	g = 0;
	while (++k < i - 1)
	{
		if (buf[k] == '#')
		{
			g_comb_numbs[j][0] += q;
			g_comb_numbs[j][++g] = q;
		}
		else if (buf[k] != '.' && k != 4 && k != 9 && k != 14 && k != 19)
			return (0);
		if (k != 4 && k != 9 && k != 14 && k != 19)
			q *= 2;
	}
	if ((g != 4 || !check_tet(g_comb_numbs[j])))
		return (0);
	return (1);
}

int		read_tet(char *source)
{
	int		fd;
	int		i;
	int		j;
	char	buf[21];

	fd = open(source, O_RDONLY);
	i = 0;
	j = -1;
	if (read(fd, 0, 0) < 0)
		return (0);
	while (++j < 26 && (i = read(fd, buf, 21)) == 21)
	{
		if (!check_valid(buf, i, j))
			return (0);
	}
	if (i != 20 || j > 26)
		return (0);
	if (!check_valid(buf, i, j))
		return (0);
	return (j + 1);
}
