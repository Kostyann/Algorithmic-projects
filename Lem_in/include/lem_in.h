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
	char			*index;
	int				x;
	int				y;
	int				ants;
	int				status;
	struct s_room	**edges;
	int 			*arrivals;
}					t_room;

typedef struct		s_farm
{
	int				ants;
	int				quantity;
	char			*s_index;
	char			*e_index;
	t_room			**rooms;
	char			***solution;
}					t_farm;

typedef struct		s_path
{
	int				depth;
	int				invalid;
	t_room			**path;
}					t_path;

#endif
