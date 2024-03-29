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
	int				edges_n;
	int				*arrivals;
	int				blocked;
}					t_room;

typedef struct		s_farm
{
	int				ants;
	int				rooms_n;
	char			*s_index;
	char			*e_index;
	t_room			**rooms;
	char			***solution;
	char			**view;
	t_room			**bfs_to_visit;
}					t_farm;

typedef struct		s_path
{
	int				depth;
	int				invalid;
	t_room			**path;
}					t_path;

t_farm				*make_farm(void);

int					room_or_comment(t_farm *farm, int *start, int *end,
																char **split);
int					link_or_comment(t_farm *farm, int j, char **split);

void				path_mem(t_farm *farm, t_path **paths, int n, int depth);
t_path				**get_paths(t_farm *farm);

int					find_paths_bfs(t_farm *farm, t_path **paths,
														int *checked, int w);

int					path_exists(t_farm *farm, t_room *start, int *checked);
int					find_paths_dfs(t_farm *farm, t_path **paths, int *checked,
									int *j);

void				print_farm(t_farm *farm);
void				print_solution(t_farm *farm);
int					com_o_comm(char *line);

#endif
