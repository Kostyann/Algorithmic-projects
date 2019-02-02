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
	int				depth;
	struct s_room	*parent;
	struct s_room	**edges;
	int 			*arrivals;
}					t_room;

typedef struct		s_farm
{
	int				ants;
	int				rooms_n;
	char			*s_index;
	char			*e_index;
	t_room			**rooms;
	char			***solution;
	char 			**view;
	t_room			**bfs_to_visit;
}					t_farm;

typedef struct		s_path
{
	int				depth;
	int				invalid;
	t_room			**path;
}					t_path;

void	print_farm(t_farm *farm);
void	print_paths(t_path **paths, t_farm *farm);
void	print_solution(t_farm *farm);

t_farm	*make_farm();

t_path	**get_paths(t_farm *farm);

#endif
