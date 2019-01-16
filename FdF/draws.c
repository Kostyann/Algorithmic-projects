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

#include "fdf.h"

void	img_put_pixel(t_fdf *fdf, int x, int y, int color)
{
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
		img_put_pixel(fdf, WIDTH / 2 + fdf->x0,
				HEIGHT / 2 + fdf->y0, fdf->color);
		if (fdf->x0 == fdf->x1 && fdf->y0 == fdf->y1)
			break ;
		error[1] = 2 * error[0];
		if (error[1] >= fdf->dy)
		{
			error[0] += fdf->dy;
			fdf->x0 += fdf->sx;
		}
		if (error[1] <= fdf->dx)
		{
			error[0] += fdf->dx;
			fdf->y0 += fdf->sy;
		}
	}
}

void	set_coords(t_fdf *fdf, int k, int n, char *num)
{
	fdf->x0 = fdf->x1;
	fdf->y0 = fdf->y1;
	fdf->x1 = fdf->q * (n - fdf->cols / 2);
	fdf->y1 = fdf->q * (k - fdf->rows / 2);
	fdf->z1 = fdf->q * ft_atoi(num);
	rotate(fdf);
	fdf->color = 0x0000FF;
}

void	draw_loop(t_fdf *fdf, int k, int n, char **nums)
{
	char	**nums1;

	nums1 = NULL;
	if (nums[n + 1])
	{
		set_coords(fdf, k, n, nums[n]);
		set_coords(fdf, k, n + 1, nums[n + 1]);
		draw_line(fdf);
	}
	if (fdf->field[k + 1])
	{
		nums1 = ft_strsplit(fdf->field[k + 1], ' ');
		set_coords(fdf, k, n, nums[n]);
		set_coords(fdf, k + 1, n, nums1[n]);
		draw_line(fdf);
	}
	if (nums1 != NULL)
		free_array(&nums1);
}

void	draw(t_fdf *fdf)
{
	char	**nums;
	int		k;
	int		n;

	k = -1;
	ft_bzero(fdf->img_addr, HEIGHT * WIDTH * fdf->bpp / 8);
	while (fdf->field[++k])
	{
		n = -1;
		nums = ft_strsplit(fdf->field[k], ' ');
		while (nums[++n])
			draw_loop(fdf, k, n, nums);
		free_array(&nums);
	}
//	ft_printf("x = %f\n", fdf->x);
//	ft_printf("y = %f\n", fdf->y);
//	ft_printf("z = %f\n", fdf->z);
//	ft_printf("______________\n");
	fdf->x0 = 0;
	fdf->y0 = 0;
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}
