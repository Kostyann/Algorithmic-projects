/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:01:55 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/02/06 17:01:57 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

/*
** Breadth-first search (BFS)
*/

int		check_edges_bfs(t_room *room, t_path **paths, t_farm *farm, int i)
{
	t_room	*link;

	if (room->edges[i] != room->parent)
	{
		if (!room->edges[i]->depth)
			room->edges[i]->depth = room->depth + 1;
		if (!room->edges[i]->parent)
			room->edges[i]->parent = room;
	}
	if (ft_strequ(room->edges[i]->index, farm->e_index))
	{
		link = room->edges[i];
		paths[0]->path[link->depth] = link;
		paths[0]->depth = link->depth;
		while (link->parent)
		{
			link = link->parent;
			paths[0]->path[link->depth] = link;
		}
		return (1);
	}
	return (0);
}

#define BFS farm->bfs_to_visit

int		find_paths_bfs(t_farm *farm, t_path **paths, int *checked)
{
	int		k;
	int		i;
	int		j;

	BFS = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n * 2 + 1));
	BFS[0] = farm->rooms[ft_atoi(farm->s_index)];
	k = -1;
	while (BFS[++k] && (i = -1) == -1)
	{
		while (BFS[k]->edges[++i])
			if (check_edges_bfs(BFS[k], paths, farm, i))
				return (1);
		checked[ft_atoi(BFS[k]->index)] = 1;
		i = -1;
		while (BFS[k]->edges[++i])
			if (!(checked[ft_atoi(BFS[k]->edges[i]->index)]) && (j = -1) == -1)
			{
				while (BFS[++j])
					;
				BFS[j] = BFS[k]->edges[i];
			}
	}
	return (0);
}
