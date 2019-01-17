/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:32:58 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/12 13:33:00 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

typedef struct	s_fdf
{
	char	*name;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		s_line;
	int		endian;

	int		**field;
	int		x1;
	int		y1;
	int		x_curr;
	int		y_curr;
	int		x0;
	int		y0;
	int		z1;

	int		cols;
	int		rows;

	int		dx;
	int		dy;
	int		sx;
	int		sy;

	int		color1;
	int		color_curr;
	int		color0;
	int		color_delta;

	// Angles

	float	x;
	float	y;
	float	z;

	// Tweaks

	int		q;
	float	alt;
	int		shift_x;
	int		shift_y;
	int		max_z;
	int		min_z;
	int		rot_x;
	int		rot_y;

}				t_fdf;




void			rotate(t_fdf *fdf);
void			draw_line(t_fdf *fdf);
void			set_coords(t_fdf *fdf, int k, int n);
void			draw_loop(t_fdf *fdf, int k, int n);
void			draw(t_fdf *fdf);

void			img_put_pixel(t_fdf *fdf, int x, int y, int color);
void			free_array(char ***array);
int				deal_key2(int key, t_fdf *fdf);
int				deal_key(int key, void *param);
int				my_close(void *param);

#endif