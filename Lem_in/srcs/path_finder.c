/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:27:43 by kmerkulo          #+#    #+#             */
/*   Updated: 2019/01/30 16:27:45 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	path_mem(t_farm *farm, t_path **paths, int n, int depth)
{
	paths[n] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
	paths[n]->path = (t_room**)ft_memalloc(sizeof(t_room*) *
			(farm->rooms_n + 1));
	paths[n]->depth = depth;
}

int		ft_strbrstr(t_room **haystack, t_room **needle)
{
	int i;
	int j;

	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] &&
				ft_strequ(haystack[i + j]->index, needle[j]->index))
			j++;
		if (!needle[j])
			return (1);
	}
	i = -1;
	while (needle[++i])
	{
		j = 0;
		while (needle[i + j] && haystack[j] &&
				ft_strequ(needle[i + j]->index, haystack[j]->index))
			j++;
		if (!haystack[j])
			return (1);
	}
	return (0);
}

void	check_valid(t_path **paths)
{
	int	i;
	int	j;

	i = -1;
	while (paths[++i])
	{
		if (!paths[i]->invalid)
		{
			j = 0;
			while (paths[i + ++j])
			{
				if (!paths[i + j]->invalid && ft_strbrstr(paths[i]->path,
						paths[i + j]->path))
				{
					if (paths[i]->depth > paths[i + j]->depth)
						paths[i]->invalid = 1;
					else
						paths[i + j]->invalid = 1;
				}
			}
		}
	}
}

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

/*
**Deep-first search (DFS)
*/

int		find_paths_dfs(t_farm *farm, t_path **paths, int *checked, int *j)
{
	int		i;
	t_room	*start;

	i = -1;
	start = farm->rooms[ft_atoi(farm->s_index)];
	checked[ft_atoi(start->index)] = 1;
	paths[*j]->path[++(paths[*j]->depth)] = start;
	while (start->edges[++i])
	{
		if (ft_strequ(start->edges[i]->index, farm->e_index))
		{
			paths[*j]->path[++(paths[*j]->depth)] = start->edges[i];
			checked[ft_atoi(start->index)] = 0;
			return (1);
		}
	}
	i = -1;
	while (start->edges[++i])
	{
		if (!(checked[ft_atoi(start->edges[i]->index)]))
		{
			farm->s_index = start->edges[i]->index;
			if (find_paths_dfs(farm, paths, checked, j))
			{
				if (*j >= 100)
					return (1);
				(*j)++;
				path_mem(farm, paths, *j, paths[*j - 1]->depth - 2);
				paths[*j]->path = ft_memcpy(paths[*j]->path,
					paths[*j - 1]->path,
					sizeof(paths[*j - 1]->path) * (paths[*j - 1]->depth - 1));
			}
			else
			{
				paths[*j]->path[(paths[*j]->depth)--] = 0;
				checked[ft_atoi(start->edges[i]->index)] = 0;
			}
		}
	}
	return (0);
}

/*
** Breadth-first search (BFS)
*/

#define BFS farm->bfs_to_visit

int		find_paths_bfs(t_farm *farm, t_path **paths, int *checked)
{
	int		k;
	int		i;
	int		j;
	int		p;
	t_room	*link;

	BFS = (t_room**)ft_memalloc(sizeof(t_room*) *
			(farm->rooms_n * 2 + 1));
	BFS[0] = farm->rooms[ft_atoi(farm->s_index)];
	k = -1;
	p = 0;
	while (BFS[++k])
	{
		i = -1;
		while (BFS[k]->edges[++i])
		{
			if (BFS[k]->edges[i] != BFS[k]->parent)
			{
				if (!BFS[k]->edges[i]->depth)
					BFS[k]->edges[i]->depth = BFS[k]->depth + 1;
				if (!BFS[k]->edges[i]->parent)
					BFS[k]->edges[i]->parent = BFS[k];
			}
			if (ft_strequ(BFS[k]->edges[i]->index, farm->e_index))
			{
				link = BFS[k]->edges[i];
				paths[p]->path[link->depth] = link;
				paths[p]->depth = link->depth;
				while (link->parent)
				{
					link = link->parent;
					paths[p]->path[link->depth] = link;
				}
				return (1);
			}
		}
		checked[ft_atoi(BFS[k]->index)] = 1;
		i = -1;
		while (BFS[k]->edges[++i])
			if (!(checked[ft_atoi(BFS[k]->edges[i]->index)]))
			{
				j = -1;
				while (BFS[++j])
					;
				BFS[j] = BFS[k]->edges[i];
			}
	}
	free(BFS);
	return (p);
}

int		no_end(t_path **paths, int index, int n)
{
	int i;

	i = 0;
	while (paths[n]->path[i])
		i++;
	if (ft_atoi(paths[n]->path[i - 1]->index) == index)
		return (0);
	ft_memdel((void**)&paths[n]->path);
	ft_memdel((void**)&paths[n]);
	return (1);
}

t_path	**get_paths(t_farm *farm)
{
	t_path	**paths;
	int		*checked;
	int		n;

	checked = (int*)ft_memalloc(sizeof(int) * (farm->rooms_n + 1));
	paths = (t_path**)ft_memalloc(sizeof(t_path*) * (farm->rooms_n / 2
			* (farm->rooms_n + 1)));
	path_mem(farm, paths, 0, -1);
	if (!(path_exists(farm, farm->rooms[ft_atoi(farm->s_index)], checked)))
	{
		ft_printf("ERROR: no solution!\n");
		exit(0);
	}
	ft_bzero((void*)checked, sizeof(int) * (farm->rooms_n + 1));
	n = find_paths_bfs(farm, paths, checked);
	ft_bzero((void*)checked, sizeof(int) * (farm->rooms_n + 1));
	path_mem(farm, paths, n, -1);
	find_paths_dfs(farm, paths, checked, &n);
	no_end(paths, ft_atoi(farm->e_index), n);
	check_valid(paths);
	free(checked);
	return (paths);
}
