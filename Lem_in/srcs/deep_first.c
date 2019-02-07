/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:01:23 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/02/06 17:01:25 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
**Deep-first search (DFS)
*/

int		path_exists(t_farm *farm, t_room *start, int *checked)
{
	int	i;

	i = -1;
	checked[ft_atoi(start->index)] = 1;
	if (start->edges)
	{
		while (start->edges[++i])
			if (ft_strequ(start->edges[i]->index, farm->e_index))
				return (1);
		i = -1;
		while (start->edges[++i])
			if (!(checked[ft_atoi(start->edges[i]->index)]))
				if (path_exists(farm, start->edges[i], checked))
					return (1);
	}
	return (0);
}

int		check_edges_dfs(t_farm *farm, t_path **paths, int *checked, int *j)
{
	int		i;
	t_room	*start;

	i = -1;
	start = farm->rooms[ft_atoi(farm->s_index)];
	checked[ft_atoi(start->index)] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;
	while (start->edges[++i])
		if (ft_strequ(start->edges[i]->index, farm->e_index))
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			checked[ft_atoi(start->index)] = 0;
			return (1);
		}
	return (0);
}

int		find_paths_dfs(t_farm *farm, t_path **paths, int *checked, int *j)
{
	int		i;
	t_room	*start;

	start = farm->rooms[ft_atoi(farm->s_index)];
	if ((i = -1) == -1 && check_edges_dfs(farm, paths, checked, j))
		return (1);
	while (start->edges[++i])
		if (!(checked[ft_atoi(start->edges[i]->index)]))
		{
			farm->s_index = start->edges[i]->index;
			if (find_paths_dfs(farm, paths, checked, j))
			{
				if (*j >= 20)
					return (1);
				(*j)++;
				path_mem(farm, paths, *j, paths[*j - 1]->depth - 2);
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[ft_atoi(start->edges[i]->index)] = 0;
			}
		}
	return (0);
}
