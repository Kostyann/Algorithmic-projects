/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:38:45 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/22 16:38:47 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/include/libft.h"

typedef struct		s_room
{
	char			*name;
	int				index;
	int				x;
	int				y;
	int				ants;
	int				status;
	struct s_room	**edges;
}					t_room;

typedef struct		s_farm
{
	int				quantity;
	int				s_index;
	int				e_index;
	t_room			**rooms;
}					t_farm;

typedef struct		s_path
{
	int				depth;
	int				found;
	t_room			**path;
}					t_path;

#endif
