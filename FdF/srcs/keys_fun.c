/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   technical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:18:15 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/13 21:18:16 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		deal_key3(int key, t_fdf *fdf)
{
	if (key == 21)
	{
		fdf->x = 1.5708;
		fdf->y = 0;
		fdf->z = 0;
	}
	if (key == 23)
	{
		fdf->x = 1.5708;
		fdf->y = 0;
		fdf->z = 1.5708;
	}
	if (key == 123)
		fdf->shift_x -= 5;
	if (key == 124)
		fdf->shift_x += 5;
	if (key == 123 || key == 124 || key == 23 || key == 21 ||
			key == 18 || key == 19 || key == 20 || key == 125 || key == 126)
		draw(fdf);
	if (key == 53)
		exit(0);
	return (0);
}

int		deal_key2(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		fdf->x = 0.959931;
		fdf->y = 0;
		fdf->z = 0.785398;
	}
	if (key == 19)
	{
		fdf->x = 0.523599;
		fdf->y = 0;
		fdf->z = 0;
	}
	if (key == 20)
	{
		fdf->x = 0;
		fdf->y = 0;
		fdf->z = 0;
	}
	if (key == 126)
		fdf->shift_y -= 5;
	if (key == 125)
		fdf->shift_y += 5;
	deal_key3(key, fdf);
	return (0);
}

int		deal_key(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (key == 12)
		fdf->z -= 0.1;
	if (key == 14)
		fdf->z += 0.1;
	if (key == 13)
		fdf->x += 0.1;
	if (key == 1)
		fdf->x -= 0.1;
	if (key == 0)
		fdf->y -= 0.1;
	if (key == 2)
		fdf->y += 0.1;
	if (key == 6)
		fdf->color_delta += 25;
	if (key == 7)
		fdf->color_delta -= 25;
	if (key == 12 || key == 14 || key == 13 || key == 6 || key == 7 ||
		key == 0 || key == 1 || key == 2)
		draw(fdf);
	deal_key2(key, fdf);
	return (0);
}

int		my_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
