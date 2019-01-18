/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:16:11 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/13 21:16:12 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_put_pixel(t_fdf *fdf, int x, int y, int col)
{
	int	color;

//	ft_printf("color_delta = %d\n", fdf->color_delta);
//	ft_printf("color_before = %d\n", col);
/*	if (((col + fdf->color_delta) & 0xFFFFFF) > 0xFFFFFF)
	{
		ft_printf("UPPER bound\n");
		fdf->color_delta = 0;
	}
	else if (((col + fdf->color_delta) & 0x000000) < 0x000000)
	{
		ft_printf("LOWER bound\n");
		fdf->color_delta = 0;
	} */
	color = col + fdf->color_delta;
//	ft_printf("color_after = %d\n", color);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(fdf->img_addr + ((x + y * WIDTH) * fdf->bpp / 8)) = color;
}

void	rotate(t_fdf *fdf)
{
	int x;
	int y;
	int z;

	x = fdf->x1;
	y = fdf->y1;
	z = fdf->z1;

/*	fdf->x1 = (x - y) * cos(fdf->z);
	fdf->y1 = -z + (x + y) * sin(fdf->z); */

	fdf->x1 = x * cos(fdf->z) - y * sin(fdf->z);
	fdf->y1 = x * sin(fdf->z) + y * cos(fdf->z);
	x = fdf->x1;
	fdf->x1 = x * cos(fdf->y) + z * sin(fdf->y);
	fdf->z1 = -x * sin(fdf->y) + z * cos(fdf->y);
	y = fdf->y1;
	z = fdf->z1;
	fdf->y1 = y * cos(fdf->x) - z * sin(fdf->x);
	fdf->z1 = y * sin(fdf->x) + z * cos(fdf->x);

}

double percent(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int get_light(int start, int end, double percent)
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
	red = get_light((fdf->color0 >> 16) & 0xFF, (fdf->color1 >> 16) & 0xFF, perc);
	green = get_light((fdf->color0 >> 8) & 0xFF, (fdf->color1 >> 8) & 0xFF, perc);
	blue = get_light(fdf->color0 & 0xFF, fdf->color1 & 0xFF, perc);
	fdf->color_curr = (red << 16) | (green << 8) | blue;
}

void	draw_line(t_fdf *fdf)
{
	int error[2];

	fdf->dx = abs(fdf->x1 - fdf->x0);
	fdf->dy = -abs(fdf->y1 - fdf->y0);
	fdf->sx = fdf->x0 < fdf->x1 ? 1 : -1;
	fdf->sy = fdf->y0 < fdf->y1 ? 1 : -1;
	error[0] = fdf->dx + fdf->dy;
	while (1)
	{
		get_color(fdf);
		img_put_pixel(fdf, WIDTH / 2 + fdf->x_curr + fdf->shift_x,
				HEIGHT / 2 + fdf->y_curr + fdf->shift_y, fdf->color_curr);
		if (fdf->x_curr == fdf->x1 && fdf->y_curr == fdf->y1)
			break ;
		error[1] = 2 * error[0];
		if (error[1] >= fdf->dy)
		{
			error[0] += fdf->dy;
			fdf->x_curr += fdf->sx;
		}
		if (error[1] <= fdf->dx)
		{
			error[0] += fdf->dx;
			fdf->y_curr += fdf->sy;
		}
	}
}

void	set_coords(t_fdf *fdf, int k, int n)
{
	fdf->x0 = fdf->x1;
	fdf->y0 = fdf->y1;
	fdf->color0 = fdf->color1;
	fdf->x1 = fdf->q * (n - fdf->cols / 2);
	fdf->y1 = fdf->q * (k - fdf->rows / 2);
	fdf->z1 = fdf->q * fdf->field[k][n] * fdf->alt;
	if (fdf->z1 > (fdf->q * fdf->max_z * 0.8))
		fdf->color1 = 0xFFFFFF;
	else if (fdf->z1 > (fdf->q * fdf->max_z / 3))
		fdf->color1 = 0x35CCF5;
	else if (fdf->z1 > 0)
		fdf->color1 = 0x036836;
	else if (fdf->z1 < (-fdf->q * fdf->max_z))
		fdf->color1 = 0xE13213;
	else if (fdf->z1 < (-fdf->q * fdf->max_z / 5))
		fdf->color1 = 0x2A078D;
	else
		fdf->color1 = 0x04A92E;
	rotate(fdf);
	// FE43D7  pink  was FFFFFF
	// 39C4F8  blue  was 04A92E
}

void	draw_loop(t_fdf *fdf, int k, int n)
{
	char	**nums1;

	nums1 = NULL;
	if (n + 1 < fdf->cols)
	{
		set_coords(fdf, k, n);
		set_coords(fdf, k, n + 1);
		fdf->x_curr = fdf->x0;
		fdf->y_curr = fdf->y0;
		fdf->color_curr = fdf->color0;
		draw_line(fdf);
	}
	if (k + 1 < fdf->rows)
	{
		set_coords(fdf, k, n);
		set_coords(fdf, k + 1, n);
		fdf->x_curr = fdf->x0;
		fdf->y_curr = fdf->y0;
		fdf->color_curr = fdf->color0;
		draw_line(fdf);
	}
}

void	draw(t_fdf *fdf)
{
	int		k;
	int		n;
	int 	color;

	color = 0xEF0E0A;
	k = -1;
	ft_bzero(fdf->img_addr, HEIGHT * WIDTH * fdf->bpp / 8);
	while (++k < fdf->rows)
	{
		n = -1;
		while (++n < fdf->cols)
			draw_loop(fdf, k, n);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 590, 0x0BADF3,
				   "Hold Z or X to see the Lightshow!;)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 610, color,
			"Press 1, 2, 3, 4 or 5 to choose different types of projection");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 630, color,
				   "Press Q, W, E, A, S, D (or use mouse buttons) to rotate");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 650, color,
				   "Use arrows to move along X or Y axis");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 670, color,
				   "Scroll up/down to change a scale");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 690, color,
				   "Scroll left/right to change an altitude");
}
