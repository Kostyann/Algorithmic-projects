/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:06:33 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/18 12:06:35 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_move(int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if ((abs(y - fdf->rot_y) > abs(x - fdf->rot_x)) && fdf->rot_y)
	{
		if (y > fdf->rot_y)
			fdf->x -= 0.1;
		else if (y < fdf->rot_y)
			fdf->x += 0.1;
		draw(fdf);
		fdf->rot_x = x;
		fdf->rot_y = y;
	}
	else if (fdf->rot_x)
	{
		if (x > fdf->rot_x)
			fdf->y += 0.1;
		else if (x < fdf->rot_x)
			fdf->y -= 0.1;
		draw(fdf);
		fdf->rot_x = x;
		fdf->rot_y = y;
	}
	return (0);
}

int		mouse_move2(int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (fdf->rot_x)
	{
		if (x > fdf->rot_x)
			fdf->z += 0.1;
		if (x < fdf->rot_x)
			fdf->z -= 0.1;
		draw(fdf);
		fdf->rot_x = x;
		fdf->rot_y = y;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	(void)button;
	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf*)param;
	if (button == 1 || button == 2)
	{
		fdf->rot_x = x;
		fdf->rot_y = y;
		if (button == 1)
			mlx_hook(fdf->win_ptr, 6, 1L << 2, &mouse_move, fdf);
		if (button == 2)
			mlx_hook(fdf->win_ptr, 6, 1L << 2, &mouse_move2, fdf);
		mlx_hook(fdf->win_ptr, 5, 1L << 3, &mouse_release, fdf);
	}
	if (button == 4)
		fdf->q -= 1;
	if (button == 5)
		fdf->q += 1;
	if (button == 6)
		fdf->alt -= 0.1;
	if (button == 7)
		fdf->alt += 0.1;
	if (button == 4 || button == 5 || button == 6 || button == 7)
		draw(fdf);
	return (0);
}
