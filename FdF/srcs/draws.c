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
		img_put_pixel(fdf, fdf->x_curr, fdf->y_curr);
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

void	rotate(t_fdf *fdf)
{
	int x;
	int y;
	int z;

	x = fdf->x1;
	y = fdf->y1;
	z = fdf->z1;
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

	k = -1;
	ft_bzero(fdf->img_addr, HEIGHT * WIDTH * fdf->bpp / 8);
	while (++k < fdf->rows)
	{
		n = -1;
		while (++n < fdf->cols)
			draw_loop(fdf, k, n);
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 590, 0x9E18F5,
			"Hold Z or X to see the Lightshow!;)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 610, 0xF5F843,
			"Press 1, 2, 3, 4 or 5 to choose different types of projection");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 630, 0xF5F843,
			"Press Q, W, E, A, S, D (or use mouse buttons) to rotate");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 650, 0xF5F843,
			"Use arrows to move along X or Y axis");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 670, 0x0BADF3,
			"Scroll up/down to change a scale");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 30, 690, 0x0BADF3,
			"Scroll left/right to change an altitude");
}
