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
	if (n > 1)
		paths[n]->path = ft_memcpy(paths[n]->path, paths[n - 1]->path,
				sizeof(paths[n - 1]->path) * (paths[n - 1]->depth - 1));
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
		ft_printf("ERROR5!\n");
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
