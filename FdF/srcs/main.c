/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:03:14 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/12/28 12:32:46 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	count_dimensions(t_fdf *fdf)
{
	char	*line;
	char	**nums;
	int		k;
	int		n;
	int		temp;

	k = 0;
	while ((get_next_line(fdf->fd, &line) == 1))
	{
		k++;
		nums = ft_strsplit(line, ' ');
		n = -1;
		while (nums[++n])
			if ((temp = ft_atoi(nums[n])) < fdf->min_z)
				fdf->min_z = temp;
			else if (temp > fdf->max_z)
				fdf->max_z = temp;
		free(line);
		free_array(&nums);
	}
	fdf->cols = n;
	fdf->rows = k;
}

void	get_field(t_fdf *fdf)
{
	char	*line;
	char	**nums;
	int		k;
	int		n;

	k = -1;
	fdf->max_z = 1;
	fdf->min_z = 0;
	count_dimensions(fdf);
	close(fdf->fd);
	fdf->fd = open(fdf->name, O_RDONLY);
	fdf->field = (int**)malloc(sizeof(int*) * (fdf->rows + 1));
	while (++k < fdf->rows && (get_next_line(fdf->fd, &line) == 1))
	{
		nums = ft_strsplit(line, ' ');
		n = -1;
		fdf->field[k] = (int*)malloc(sizeof(int) * (fdf->cols));
		while (nums[++n])
			fdf->field[k][n] = ft_atoi(nums[n]);
		free(line);
		free_array(&nums);
		if (n != fdf->cols)
		{
			ft_printf("Found wrong line length. Exiting.\n");
			exit(0);
		}
	}
	fdf->field[k] = 0;
}

void	set_tweaks(t_fdf *fdf)
{
	int q1;
	int q2;
	int q3;

	q1 = WIDTH / 1.3 / fdf->cols;
	q2 = HEIGHT / 1.3 / fdf->rows;
	q3 = HEIGHT / 2.5 / (fdf->max_z - fdf->min_z);
	fdf->q = (q1 < q2) ? q1 : q2;
	fdf->q = (fdf->q < q3) ? fdf->q : q3;
	fdf->alt = 1.0;
	fdf->color_delta = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
}

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
	if (x > fdf->rot_x && fdf->rot_x)
	{
		fdf->z += 0.1;
		draw(fdf);
		fdf->rot_x = x;
		fdf->rot_y = y;
	}
	if (x < fdf->rot_x && fdf->rot_x)
	{
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
	if (button == 1)
	{
		fdf->rot_x = x;
		fdf->rot_y = y;
		mlx_hook(fdf->win_ptr, 6, 1L << 2, &mouse_move, fdf);
		mlx_hook(fdf->win_ptr, 5, 1L << 3, &mouse_release, fdf);
	}
	if (button == 2)
	{
		fdf->rot_x = x;
		fdf->rot_y = y;
		mlx_hook(fdf->win_ptr, 6, 1L << 2, &mouse_move2, fdf);
		mlx_hook(fdf->win_ptr, 5, 1L << 3, &mouse_release, fdf);
	}
	if (button == 4)
	{
		fdf->q -= 1;
		draw(fdf);
	}
	if (button == 5)
	{
		fdf->q += 1;
		draw(fdf);
	}
	if (button == 6)
	{
		fdf->alt -= 0.1;
		draw(fdf);
	}
	if (button == 7)
	{
		fdf->alt += 0.1;
		draw(fdf);
	}
	return (0);
}

void	start_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf 42");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->bpp = 32;
	fdf->img_addr = mlx_get_data_addr(fdf->img_ptr,
									  &fdf->bpp, &fdf->s_line, &fdf->endian);
	get_field(fdf);
	set_tweaks(fdf);
	close(fdf->fd);
	draw(fdf);
	mlx_hook(fdf->win_ptr, 4, 1L << 1, &mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, &deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 1L << 17, &my_close, (void*)0);
	mlx_loop(fdf->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (0);
	if (ac == 2)
	{
		fdf->name = av[1];
		if ((fdf->fd = open(fdf->name, O_RDONLY)) == -1)
		{
			ft_printf("No file %s\n", fdf->name);
			return (0);
		}
		fdf->x = 0.959931;
		fdf->y = 0;
		fdf->z = 0.785398;
		start_fdf(fdf);
	}
	else
		ft_printf("Usage: %s <filename> [ case_size z_size ]\n", av[0]);
	return (0);
}
