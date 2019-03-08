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

void	clean_member(t_path **paths, int w)
{
	int	i;

	i = 0;
	while (++i < paths[w]->depth)
		paths[w]->path[i]->blocked = 1;
}

int		check_room_bfs(t_room *room, t_path **paths, t_farm *farm, int w)
{
	t_room	*link;

	if (ft_strequ(room->index, farm->e_index))
	{
		link = room;
		paths[w]->path[link->depth] = link;
		paths[w]->path[link->depth + 1] = 0;
		paths[w]->depth = link->depth;
		while (link->parent)
		{
			link = link->parent;
			paths[w]->path[link->depth] = link;
		}
		if (paths[w]->depth > 1)
			clean_member(paths, w);
		return (1);
	}
	return (0);
}

#define BFS farm->bfs_to_visit

void	add_to_bfs(t_farm *farm, int *checked, int k)
{
	int	i;
	int j;

	i = -1;
	while (BFS[k]->edges[++i])
		if (!(checked[ft_atoi(BFS[k]->edges[i]->index)]) &&
			!BFS[k]->edges[i]->blocked && (j = -1) == -1)
		{
			while (BFS[++j])
				;
			BFS[j] = BFS[k]->edges[i];
			checked[ft_atoi(BFS[k]->edges[i]->index)] = 1;
			if (BFS[j] != BFS[k]->parent)
			{
				if (!BFS[j]->depth)
					BFS[j]->depth = BFS[k]->depth + 1;
				if (!BFS[j]->parent)
					BFS[j]->parent = BFS[k];
			}
		}
}

int		find_paths_bfs(t_farm *farm, t_path **paths, int *checked, int w)
{
	int		k;
	int		i;

	BFS = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	BFS[0] = farm->rooms[ft_atoi(farm->s_index)];
	k = -1;
	while (BFS[++k] && (i = -1) == -1)
	{
		if (check_room_bfs(BFS[k], paths, farm, w))
		{
			k = -1;
			while (BFS[++k])
			{
				BFS[k]->depth = 0;
				BFS[k]->parent = 0;
			}
			ft_bzero((void*)checked, sizeof(int) * (farm->rooms_n + 1));
			free(BFS);
			return (1);
		}
		checked[ft_atoi(BFS[k]->index)] = 1;
		add_to_bfs(farm, checked, k);
	}
	return (0);
}
