/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_n_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:27:37 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/18 13:27:38 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

void	get_color(t_fdf *fdf)
{
	int		red;
	int		green;
	int		blue;
	double	perc;

	if (fdf->color0 == fdf->color1)
		return ;
	if (fdf->dx > fdf->dy)
		perc = percent(fdf->x0, fdf->x1, fdf->x_curr);
	else
		perc = percent(fdf->y0, fdf->y1, fdf->y_curr);
	red = get_light((fdf->color0 >> 16) & 0xFF,
			(fdf->color1 >> 16) & 0xFF, perc);
	green = get_light((fdf->color0 >> 8) & 0xFF,
			(fdf->color1 >> 8) & 0xFF, perc);
	blue = get_light(fdf->color0 & 0xFF, fdf->color1 & 0xFF, perc);
	fdf->color_curr = (red << 16) | (green << 8) | blue;
}

void	img_put_pixel(t_fdf *fdf, int x, int y)
{
	int	color;

	get_color(fdf);
	color = fdf->color_curr + fdf->color_delta;
	x = x + WIDTH / 2 + fdf->shift_x;
	y = y + HEIGHT / 2 + fdf->shift_y;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(fdf->img_addr + ((x + y * WIDTH) * fdf->bpp / 8)) = color;
}
