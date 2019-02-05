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

int		ft_strbrstr(t_room **haystack, t_room **needle)
{
	int i;
	int j;

	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && ft_strequ(haystack[i + j]->index, needle[j]->index))
			j++;
		if (!needle[j])
			return (1);
	}
	i = -1;
	while (needle[++i])
	{
		j = 0;
		while (needle[i + j] && haystack[j] && ft_strequ(needle[i + j]->index, haystack[j]->index))
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
				if (!paths[i + j]->invalid && ft_strbrstr(paths[i]->path, paths[i + j]->path))
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

int		path_exists(t_farm *farm, t_room *start, int *checked, int *n)
{
	int	i;

	i = -1;
	checked[ft_atoi(start->index)] = 1;
	(*n)++;
	if (start->edges)
	{
		while (start->edges[++i])
			if (ft_strequ(start->edges[i]->index, farm->e_index))
				return (1);
		i = -1;
		while (start->edges[++i])
			if (!(checked[ft_atoi(start->edges[i]->index)]))
				if (path_exists(farm, start->edges[i], checked, n))
					return (1);
	}
	(*n)--;
	return (0);
}

/*
**Deep-first search (DFS)
*/

int		find_paths_dfs(t_farm *farm, t_room *start, t_path **paths, int *checked, int *j)
{
	int	i;

	i = -1;
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
			if (find_paths_dfs(farm, start->edges[i], paths, checked, j))
			{
				if (*j >= 100)
					return (1);
				(*j)++;
				paths[*j] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
				paths[*j]->path = (t_room**)ft_memalloc(sizeof(t_room*)
														* (farm->rooms_n * 2 + 1));
				paths[*j]->depth = paths[*j - 1]->depth - 2;
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

int		find_paths_bfs(t_farm *farm, t_path **paths, int *checked)
{
	int		k;
	int		i;
	int		j;
	int		p;
	t_room	*link;

	farm->bfs_to_visit = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n * 2 + 1));
	farm->bfs_to_visit[0] = farm->rooms[ft_atoi(farm->s_index)];
	k = -1;
	p = 0;
	while (farm->bfs_to_visit[++k])
	{
		i = -1;
		while (farm->bfs_to_visit[k]->edges[++i])
		{
			if (farm->bfs_to_visit[k]->edges[i] != farm->bfs_to_visit[k]->parent)
			{
				if (!farm->bfs_to_visit[k]->edges[i]->depth)
					farm->bfs_to_visit[k]->edges[i]->depth = farm->bfs_to_visit[k]->depth + 1;
				if (!farm->bfs_to_visit[k]->edges[i]->parent)
					farm->bfs_to_visit[k]->edges[i]->parent = farm->bfs_to_visit[k];
			}
			if (ft_strequ(farm->bfs_to_visit[k]->edges[i]->index, farm->e_index))
			{
				link = farm->bfs_to_visit[k]->edges[i];
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
		checked[ft_atoi(farm->bfs_to_visit[k]->index)] = 1;
		i = -1;
		while (farm->bfs_to_visit[k]->edges[++i])
		{
			if (!(checked[ft_atoi(farm->bfs_to_visit[k]->edges[i]->index)]))
			{
				j = -1;
				while (farm->bfs_to_visit[++j])
					;
				farm->bfs_to_visit[j] = farm->bfs_to_visit[k]->edges[i];
			}
		}
	}
	free(farm->bfs_to_visit);
	return (p);
}

int		no_end(t_room **path, int index)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	if (ft_atoi(path[i - 1]->index) == index)
		return (0);
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
	paths[0] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
	paths[0]->path = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	paths[0]->depth = -1;
	if (!(path_exists(farm, farm->rooms[ft_atoi(farm->s_index)], checked, &n)))
	{
		ft_printf("ERROR: no solution!\n");
		exit(0);
	}
	ft_bzero((void*)checked, sizeof(int) * (farm->rooms_n + 1));
	n = find_paths_bfs(farm, paths, checked);
	ft_bzero((void*)checked, sizeof(int) * (farm->rooms_n + 1));
	paths[n] = (t_path*)ft_memalloc(sizeof(t_path) + 1);
	paths[n]->path = (t_room**)ft_memalloc(sizeof(t_room*) * (farm->rooms_n + 1));
	paths[n]->depth = -1;
	find_paths_dfs(farm, farm->rooms[ft_atoi(farm->s_index)], paths, checked, &n);
	if (no_end(paths[n]->path, ft_atoi(farm->e_index)))
	{
		ft_memdel((void**)&paths[n]->path);
		ft_memdel((void**)&paths[n]);
	}
	check_valid(paths);
	free(checked);
	return (paths);
}
